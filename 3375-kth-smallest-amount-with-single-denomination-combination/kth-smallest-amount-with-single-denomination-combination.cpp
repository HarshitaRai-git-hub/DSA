class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countValid(vector<int>& coins, long long x) {
        int n = coins.size();
        long long ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    L = lcm(L, (long long)coins[i]);
                    if (L > x) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok)
                continue;

            long long cnt = x / L;

            if (bits % 2 == 1)
                ans += cnt;
            else
                ans -= cnt;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {

        long long low = 1;
        long long high = 1;
        while (countValid(coins, high) < k) {
            high *= 2;
        }
        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countValid(coins, mid) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};