public class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] result = new long[k];
        long[] dp = new long[k];

        for (int num : nums) {
            int val = num % k;
            long[] nextDp = new long[k];
            for (int rem = 0; rem < k; rem++) {
                if (dp[rem] > 0) {
                    int newRem = (rem * val) % k;
                    nextDp[newRem] += dp[rem];
                }
            }
            nextDp[val] += 1;
            for (int rem = 0; rem < k; rem++) {
                result[rem] += nextDp[rem];
            }

            dp = nextDp;
        }

        return result;
    }
}