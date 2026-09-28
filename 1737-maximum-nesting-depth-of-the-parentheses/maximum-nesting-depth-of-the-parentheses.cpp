class Solution {
public:
    int maxDepth(string s) {
        int open=0,maxi=0;
        for(char c:s){
            if(c=='('){
                open++;
                maxi=max(maxi,open);
            }
            else if(c==')'){
                open--;
            }
        }
        return maxi;
    }
};