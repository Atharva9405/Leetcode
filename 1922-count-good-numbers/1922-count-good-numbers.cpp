class Solution {
    
    public:
    long power(long x, long n) {
        if (n == 0) {
            return 1;
        }
        long mod=1000000007;
        long half = power(x, n / 2);
        long result = (half * half)% mod;
        if (n % 2 != 0) {
            result =(result*x)%mod;
        }
        return (long)result;
    }
    int countGoodNumbers(long n) {
        long odd=n/2;
        long even=n/2+(n%2);
        long mod=1000000007;
        odd=power(4,odd);
        even=power(5,even);
        long totalCount=(odd*even)%mod;
        return (int) totalCount;
    }
};