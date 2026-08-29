class Solution {
public:
    double myPow(double x, int n) {
        
        // Convert n to long long to handle INT_MIN
        long long N = n;

        // Handle negative power
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        // Base case
        if (N == 0) {
            return 1;
        }

        // Recursive call
        double half = myPow(x, N / 2);

        if (N % 2 == 0) {
            return half * half;
        }
        else {
            return x * half * half;
        }
    }
};