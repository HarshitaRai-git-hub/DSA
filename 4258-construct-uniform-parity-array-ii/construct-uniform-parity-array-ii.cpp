class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        int a=nums1[0];
        int parity=a%2;
        for(int i=1;i<n;i++){
            if(nums1[i]%2!=parity && (nums1[i]-a)%2!=parity)return false;
        }
        return true;
    }
};