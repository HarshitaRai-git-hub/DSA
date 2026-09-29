class Solution {
    public boolean hasValidPath(char[][]grid){
        int m=grid.length,n=grid[0].length;
        if((m+n-1)%2!=0||grid[0][0]!='('||grid[m-1][n-1]!=')')return false;
        int maxBalance=(m+n)/2;
        return dfs(grid,0,0,0,m,n,new boolean[m][n][maxBalance+1],maxBalance);
    }
    private boolean dfs(char[][]grid,int r,int c,int balance,int m,int n,boolean[][][]visited,int maxBalance){
        balance+=grid[r][c]=='('?1:-1;
        if(balance<0||balance>maxBalance)return false;
        if(r==m-1&&c==n-1)return balance==0;
        if(visited[r][c][balance])return false;
        visited[r][c][balance]=true;
        if(c+1<n&&dfs(grid,r,c+1,balance,m,n,visited,maxBalance))return true;
        if(r+1<m&&dfs(grid,r+1,c,balance,m,n,visited,maxBalance))return true;
        return false;
    }
}