import java.util.HashMap;
import java.util.Map;

class Solution {
    private static final int MOD = 1000000007;
    private long[] sum;
    private long[] sumSq;
    private long[] lazy;

    public int sumCounts(int[] nums) {
        int n = nums.length;
        sum = new long[n * 4];
        sumSq = new long[n * 4];
        lazy = new long[n * 4];
        Map<Integer, Integer> lastPos = new HashMap<>();
        long ans = 0;
        long totalSum = 0;

        for (int j = 0; j < n; j++) {
            int i = lastPos.getOrDefault(nums[j], -1);
            update(1, 0, n - 1, i + 1, j, 1);
            totalSum = (totalSum + sumSq[1]) % MOD;
            lastPos.put(nums[j], j);
        }

        return (int) totalSum;
    }

    private void pushDown(int u, int l, int r) {
        if (lazy[u] != 0) {
            int mid = (l + r) / 2;
            apply(u * 2, l, mid, lazy[u]);
            apply(u * 2 + 1, mid + 1, r, lazy[u]);
            lazy[u] = 0;
        }
    }

    private void apply(int u, int l, int r, long val) {
        long len = r - l + 1;
        sumSq[u] = (sumSq[u] + 2 * val * sum[u] % MOD + val * val % MOD * len % MOD) % MOD;
        sum[u] = (sum[u] + val * len % MOD) % MOD;
        lazy[u] = (lazy[u] + val) % MOD;
    }

    private void update(int u, int l, int r, int ql, int qr, long val) {
        if (ql <= l && r <= qr) {
            apply(u, l, r, val);
            return;
        }
        pushDown(u, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            update(u * 2, l, mid, ql, qr, val);
        }
        if (qr > mid) {
            update(u * 2 + 1, mid + 1, r, ql, qr, val);
        }
        sum[u] = (sum[u * 2] + sum[u * 2 + 1]) % MOD;
        sumSq[u] = (sumSq[u * 2] + sumSq[u * 2 + 1]) % MOD;
    }
}