class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<pair<int,int>> stk;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(stk.empty())stk.push({i,t[i]});
            else{
                int a=stk.top().second;
                if(t[i]<=a)stk.push({i,t[i]});
                else{
                    while(a<t[i]&&!stk.empty()){
                        ans[stk.top().first]=i-stk.top().first;
                        stk.pop();
                        if(!stk.empty())a=stk.top().second;
                    }
                    stk.push({i,t[i]});
                }
            }
        }
        return ans;
    }
};