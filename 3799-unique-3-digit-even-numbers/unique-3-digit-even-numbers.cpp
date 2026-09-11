class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> cnt;
        for (int d : digits) cnt[d]++;
        set<int> st;
        for (int h = 1; h <= 9; ++h) {
            for (int t = 0; t <= 9; ++t) {
                for (int u = 0; u <= 8; u += 2) {
                    cnt[h]--;
                    cnt[t]--;
                    cnt[u]--;
                    if (cnt[h] >= 0 && cnt[t] >= 0 && cnt[u] >= 0) {
                        st.insert(h * 100 + t * 10 + u);
                    }
                    cnt[h]++;
                    cnt[t]++;
                    cnt[u]++;
                }
            }
        }
        return st.size();
    }
};