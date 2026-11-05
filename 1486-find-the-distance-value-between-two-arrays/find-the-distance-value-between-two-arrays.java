class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int ans=0;
        for(int i=0;i<arr1.length;i++){
            int ct=0;
            for(int j=0;j<arr2.length;j++){
                if(d<Math.abs(arr1[i]-arr2[j]))ct++;
            }
            if(ct==arr2.length)ans++;
        }
        return ans;
    }
}