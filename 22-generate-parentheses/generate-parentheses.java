class Solution {
    void solve(int open, int close, int n, String temp, List<String> ans) {
        if (temp.length() == 2 * n) {
            ans.add(temp);
            return;
        }
        if (open < n) {
            solve(open + 1, close, n, temp + "(", ans);
        }

        if (close < open) {
            solve(open, close + 1, n, temp + ")", ans);
        }
    }

    public List<String> generateParenthesis(int n) {
        String temp = "";
        List<String> ans = new ArrayList<>();

        solve(0, 0, n, temp, ans);
        return ans;
    }
}