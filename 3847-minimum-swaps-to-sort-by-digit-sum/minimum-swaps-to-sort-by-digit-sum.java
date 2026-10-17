class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            int sum = 0, x = nums[i];

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            arr[i][1] = sum;
        }

        Arrays.sort(arr, (a, b) -> {
            if (a[1] != b[1]) return a[1] - b[1];
            return a[0] - b[0];
        });

        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++) {
            index.put(nums[i], i);
        }

        boolean[] visited = new boolean[n];
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || index.get(arr[i][0]) == i) {
                visited[i] = true;
                continue;
            }

            int j = i;
            int cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = index.get(arr[j][0]);
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
}