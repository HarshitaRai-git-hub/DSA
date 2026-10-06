class Solution {
public int minAddToMakeValid(String s) {
        Stack<Character> stk=new Stack<>();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(')stk.push(s.charAt(i));
            else{
                if(stk.isEmpty())stk.push(s.charAt(i));
                else if(stk.peek()=='('&&s.charAt(i)==')')stk.pop();
                else stk.push(s.charAt(i));
            }
        }
        return stk.size();
    }
};