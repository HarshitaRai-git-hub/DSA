import java.util.Vector;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] charVector = new int[128];
        int maxlength=0;
        int cnt=1;
        int left=0;
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            charVector[c]++;
            cnt++;
            if(charVector[c]>1){
                maxlength=Math.max(maxlength,cnt-1);
                while(charVector[c]>1){
                    cnt--;
                    charVector[s.charAt(left)]--;
                    left++;
                }
            }
            
        }
        maxlength=Math.max(cnt,maxlength);
        return maxlength-1;
    }
}