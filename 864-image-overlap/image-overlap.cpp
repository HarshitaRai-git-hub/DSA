class Solution{
public:
    int largestOverlap(vector<vector<int>>&img1,vector<vector<int>>&img2){
        int n=img1.size();
        int ans=0;
        for(int dx=-(n-1);dx<n;dx++){
            for(int dy=-(n-1);dy<n;dy++){
                int count=0;
                int r1=max(0,-dx);
                int r2=min(n,n-dx);
                int c1=max(0,-dy);
                int c2=min(n,n-dy);
                for(int i=r1;i<r2;i++){
                    for(int j=c1;j<c2;j++){
                        if(img1[i][j]==1&&img2[i+dx][j+dy]==1)
                            count++;
                    }
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};