class Solution {
    static final long MOD = 1000000007;
    public int numberOfSets(int n, int k) {
        int r=2*k;
        int total=n+k-1;
        if (r>total||r<0) return 0;
        long num=1;
        long den=1;
        for (int i=1;i<=r;i++) {
            num=(num*(total-i+1))%MOD;
            den=(den*i)%MOD;
        }
        long ans=(num*modInverse(den))%MOD;
        return (int)ans;
    }
    long modInverse(long x) {
        return power(x,MOD-2);
    }
    long power(long a,long b) {
        long result=1;
        a%=MOD;
        while (b>0) {
            if ((b&1)==1) {
                result=(result*a)%MOD;
            }
            a=(a*a)%MOD;
            b>>=1;
        }
        return result;
    }
}