class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        vector<int> pair(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')'){
                int j=st.top();
                st.pop();
                pair[i]=j;
                pair[j]=i;
            }
        }
        string res;
        int curr=0,dir=1;
        while(curr<n){
            if(s[curr]=='('||s[curr]==')'){
                curr=pair[curr];
                dir=-dir;
            }else{
                res+=s[curr];
            }
            curr+=dir;
        }
        return res;
    }
};