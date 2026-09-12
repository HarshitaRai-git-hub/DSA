class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end());

        vector<int> left(n);

        for (int i = 0; i < n; i++) {
            left[i] = a[i][0];
        }

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            nxt[i] = upper_bound(left.begin(), left.end(), a[i][1]) - left.begin();
        }

        vector<vector<pair<long long, vector<int>>>> dp(n + 1,
            vector<pair<long long, vector<int>>>(5, {0, {}}));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                dp[i][k] = dp[i + 1][k];

                long long score = a[i][2] + dp[nxt[i]][k - 1].first;

                vector<int> ids = dp[nxt[i]][k - 1].second;
                ids.push_back(a[i][3]);
                sort(ids.begin(), ids.end());

                if (score > dp[i][k].first ||
                    (score == dp[i][k].first && ids < dp[i][k].second)) {
                    dp[i][k] = {score, ids};
                }
            }
        }

        return dp[0][4].second;
    }
};