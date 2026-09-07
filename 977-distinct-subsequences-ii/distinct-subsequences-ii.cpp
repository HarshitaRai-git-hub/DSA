class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long total = 1;                
        for (char ch : s) {
            long long newTotal = (2 * total % MOD - last[ch - 'a'] + MOD) % MOD;
            last[ch - 'a'] = total;
            total = newTotal;
        }
        return (total - 1 + MOD) % MOD;     
    }
};