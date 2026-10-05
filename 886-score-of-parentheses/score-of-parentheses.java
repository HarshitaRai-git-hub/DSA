class Solution {
    public int scoreOfParentheses(String s) {
        int ans=0;
        int open=0;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='(')open++;
            else{
                open--;
                if(s.charAt(i - 1) == '(') {
                    ans += 1 << open;
                }
            }
        }
        return ans;
    }
}