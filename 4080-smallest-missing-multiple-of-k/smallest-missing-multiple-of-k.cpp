class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int h=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==(k*h))h++;
            else if(nums[i]>(k*h))return k*h;
        }
        return k*h;
    }
};