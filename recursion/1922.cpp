class Solution {
public:
    long long MOD = 1000000007;

    long long power(long long x, long long n) {
        if (n == 0) {
            return 1;
        }

        long long half = power(x, n / 2);

        if (n % 2 == 0) {
            return (half * half) % MOD;
        }

        return (x * half % MOD * half) % MOD;
    }

    int countGoodNumbers(long long n) {

        long long evenpos = (n + 1) / 2;
        long long oddpos = n / 2;

        return (power(5, evenpos) * power(4, oddpos)) % MOD;
    }
};