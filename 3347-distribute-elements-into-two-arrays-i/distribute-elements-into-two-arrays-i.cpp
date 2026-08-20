class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> help;
        ans.push_back(nums[0]);
        help.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(ans.back()>help.back())ans.push_back(nums[i]);
            else help.push_back(nums[i]);
        }
        ans.insert(ans.end(), help.begin(), help.end());
        return ans;
    }
};