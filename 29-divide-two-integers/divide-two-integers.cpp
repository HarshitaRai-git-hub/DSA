
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        bool neg = (a < 0) ^ (b < 0);

        a = abs(a);
        b = abs(b);

        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long cnt = 1;

            while ((temp << 1) <= a) {
                temp <<= 1;
                cnt <<= 1;
            }

            a -= temp;
            ans += cnt;
        }

        return neg ? -ans : ans;
    }
};
