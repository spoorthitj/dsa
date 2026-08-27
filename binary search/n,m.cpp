class Solution {
public:
    int NthRoot(int N, int M) {
        int l = 0;
        int r = M;

        while (l <= r) {
            int m = l + (r - l) / 2;

            long long power = 1;

            // Calculate m^N
            for (int i = 0; i < N; i++) {
                power *= m;

                // Stop early if power becomes too large
                if (power > M) {
                    break;
                }
            }

            if (power == M) {
                return m;
            }
            else if (power > M) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return -1;
    }
};