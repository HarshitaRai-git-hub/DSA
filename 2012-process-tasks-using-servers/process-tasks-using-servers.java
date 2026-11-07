import java.util.PriorityQueue;

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;
        int[] ans = new int[m];

        // free priority queue: sorts by weight (a[0]), then index (a[1])
        PriorityQueue<int[]> free = new PriorityQueue<>((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        // busy priority queue: sorts by available time (a[0])
        // elements: [free_time, weight, index]
        PriorityQueue<long[]> busy = new PriorityQueue<>((a, b) -> {
            return Long.compare(a[0], b[0]);
        });

        for (int i = 0; i < n; i++) {
            free.add(new int[]{servers[i], i});
        }

        long time = 0;

        for (int i = 0; i < m; i++) {
            // Time cannot be less than the arrival time of the current task `i`
            time = Math.max(time, i);

            // If there are no free servers, jump time to when the next server becomes free
            if (free.isEmpty()) {
                time = Math.max(time, busy.peek()[0]);
            }

            // Release all servers that have finished their tasks by the current `time`
            while (!busy.isEmpty() && busy.peek()[0] <= time) {
                long[] temp = busy.poll();
                free.add(new int[]{(int) temp[1], (int) temp[2]});
            }

            // Assign the task to the top server in the free queue
            int[] server = free.poll();
            ans[i] = server[1];

            busy.add(new long[]{
                time + tasks[i],
                server[0],
                server[1]
            });
        }

        return ans;
    }
}