class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)mp[nums[i]]++;
        if(k==1){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(mp[nums[i]]==1)maxi=max(maxi,nums[i]);
            }
            if(maxi==INT_MIN)return -1;
            return maxi;
        }else if(k==n){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(maxi,nums[i]);
            }
            if(maxi==INT_MIN)return -1;
            return maxi;
        }
        int a=mp[nums[0]];
        int b=mp[nums[n-1]];
        if(a==1&&b==1)return max(nums[0],nums[n-1]);
        else if(a!=1&&b==1)return nums[n-1];
        else if(a==1&&b!=1)return nums[0];
        else return -1;
    }
};