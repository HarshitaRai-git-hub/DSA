class Solution {
    public int reverseDegree(String s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int a=s.charAt(i)-'a'+1;
            ans+=((27-a)*(i+1));
        }
        return ans;
    }
}