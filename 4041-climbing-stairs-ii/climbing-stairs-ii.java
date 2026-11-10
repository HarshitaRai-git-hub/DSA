class Solution {
    public int climbStairs(int n, int[] costs) {
        int[] f = new int[n + 1];
        final int inf = Integer.MAX_VALUE / 2;
        Arrays.fill(f, inf);
        
        // Base case: starting at step 0 with cost 0
        f[0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            int currentCost = costs[i - 1];
            // We can jump from step j to i, where i - 3 <= j < i
            for (int j = Math.max(0, i - 3); j < i; ++j) {
                int jumpCost = (i - j) * (i - j);
                f[i] = Math.min(f[i], f[j] + currentCost + jumpCost);
            }
        }
        
        return f[n];
    }
}