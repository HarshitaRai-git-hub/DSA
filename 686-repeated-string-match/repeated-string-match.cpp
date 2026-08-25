class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.size();
        int n=b.size();
        int ans=(m+n-1)/m;
        string s="";
        for(int i=0;i<ans;i++)s+=a;
        if(s.find(b)!=-1)return ans;
        ans++;
        s+=a;
        if(s.find(b)!=-1)return ans;
        return -1;
    }
};