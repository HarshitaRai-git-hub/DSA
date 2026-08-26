class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(count(s.begin(),s.end(),'1')<k)return "";
        int i=0,j=0;
        int mini=INT_MAX;
        int cnt=0;
        while(j<s.size()){
            // while(i<s.size()&&s[i]!='1')i++;
            // if(j<i)j=i;
            if(s[j]=='1')cnt++;
            while(cnt == k){
                while(s[i] == '0') i++;
                mini = min(mini, j - i + 1);
                if(s[i] == '1') cnt--;
                i++;
            }
            j++;
            // if(cnt<k)j++;
            // else if(cnt==k){
            //     mini=min(mini,j-i+1);
            //     if (s[i] == '1')cnt--;
            //     i++;
            // }
        }
        vector<string> s1;
        i=0,j=0;
        while(i+mini<=s.size()){    
            if(count(s.begin() + i,s.begin() + i + mini,'1')==k)s1.push_back(s.substr(i,mini));
            i++;
        }
        if(s1.empty()) return "";
        sort(s1.begin(),s1.end());
        return s1[0];
    }
};