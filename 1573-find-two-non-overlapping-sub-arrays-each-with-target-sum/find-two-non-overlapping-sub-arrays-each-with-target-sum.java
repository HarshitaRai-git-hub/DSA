class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] best = new int[n];
        int i = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;
        int ans = Integer.MAX_VALUE;

        for(int j = 0; j < n; j++) {
            sum += arr[j];

            while(sum > target) {
                sum -= arr[i];
                i++;
            }

            if(sum == target) {
                int len = j - i + 1;

                if(i > 0 && best[i - 1] != 0) {
                    ans = Math.min(ans, len + best[i - 1]);
                }

                minLen = Math.min(minLen, len);
            }

            if(minLen != Integer.MAX_VALUE)
                best[j] = minLen;
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}