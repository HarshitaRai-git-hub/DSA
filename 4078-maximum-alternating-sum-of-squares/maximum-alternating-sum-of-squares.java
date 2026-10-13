class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n=nums.length;
        for (int i=0;i<n;i++) {
            nums[i]=nums[i]*nums[i];
        }
        Arrays.sort(nums);
        long ans = 0;
        for (int i=0;i<n;i++) {
            if (i<n/2) {
                ans-=nums[i];
            } else {
                ans+=nums[i];
            }
        }
        return ans;
    }
}