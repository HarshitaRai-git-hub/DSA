import java.util.*;

class Solution {
    public List<String> braceExpansionII(String expression) {
        Set<String> set = parseExpr(expression, 0, expression.length());
        List<String> result = new ArrayList<>(set);
        Collections.sort(result);
        return result;
    }

    private Set<String> parseExpr(String s, int start, int end) {
        Set<String> totalUnion = new HashSet<>();
        List<Set<String>> currentProductGroup = new ArrayList<>();
        int i = start;

        while (i < end) {
            char c = s.charAt(i);

            if (c == ',') {
                totalUnion.addAll(combineCartesian(currentProductGroup));
                currentProductGroup.clear();
                i++;
            } else if (c == '{') {
                int braceCount = 1;
                int j = i + 1;
                while (j < end && braceCount > 0) {
                    if (s.charAt(j) == '{') braceCount++;
                    else if (s.charAt(j) == '}') braceCount--;
                    j++;
                }
                currentProductGroup.add(parseExpr(s, i + 1, j - 1));
                i = j;
            } else {
                Set<String> singleLetter = new HashSet<>();
                singleLetter.add(String.valueOf(c));
                currentProductGroup.add(singleLetter);
                i++;
            }
        }

        totalUnion.addAll(combineCartesian(currentProductGroup));
        return totalUnion;
    }

    private Set<String> combineCartesian(List<Set<String>> groups) {
        if (groups.isEmpty()) return Collections.emptySet();
        
        Set<String> result = new HashSet<>();
        result.add("");

        for (Set<String> group : groups) {
            Set<String> nextResult = new HashSet<>();
            for (String head : result) {
                for (String tail : group) {
                    nextResult.add(head + tail);
                }
            }
            result = nextResult;
        }

        return result;
    }
}