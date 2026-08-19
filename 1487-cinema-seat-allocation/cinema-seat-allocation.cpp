class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        map<int, vector<bool>> mp;
        
        for(int i = 0; i < reservedSeats.size(); i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            
            if(mp.find(row) == mp.end())
                mp[row] = vector<bool>(3, true);
            
            if(seat >= 2 && seat <= 5)
                mp[row][0] = false;
            
            if(seat >= 4 && seat <= 7)
                mp[row][1] = false;
            
            if(seat >= 6 && seat <= 9)
                mp[row][2] = false;
        }
        
        int ans = 2 * (n - mp.size());
        
        for(auto x : mp) {
            bool left = x.second[0];
            bool middle = x.second[1];
            bool right = x.second[2];
            
            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }
        
        return ans;
    }
};