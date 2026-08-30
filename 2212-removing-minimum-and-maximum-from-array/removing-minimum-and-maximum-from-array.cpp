class Solution {
public:
    int minimumDeletions(vector<int>& arr) {
        int n=arr.size();
        int mini=arr[0];  int idx1=0;
        int maxi=arr[0];  int idx2=0;
        for(int i=0;i<n;i++){
            if(arr[i]<mini){
                mini=arr[i];idx1=i;
            }
            if(arr[i]>maxi){
                maxi=arr[i];idx2=i;
            }
        }
        int a = max(idx1, idx2) + 1;
        int b = n - min(idx1, idx2);
        int c = min(idx1, idx2) + 1 + n - max(idx1, idx2);

        return min({a, b, c});
    }
};