class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<bool> v(upper+2,false);
        vector<vector<int>> ans;
        for(int x:nums)if (x >= lower && x <= upper)v[x]=true;
        int i=lower,j=lower;
         while (j <= upper) {
            if (v[j]) {
                if (i <= j - 1)
                    ans.push_back({i, j - 1});

                i = j + 1;
            }

            j++;
        }
        if (i <= upper)
            ans.push_back({i, upper});
        return ans;
    }
};