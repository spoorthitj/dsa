class Solution {
public:
    int kthGrammar(int n, int k) {

        if (n == 1) {
            return 0;
        }

        int l = 1 << (n - 1);

        if (k <= l / 2) {
            return kthGrammar(n - 1, k);
        }
        else {
            int newK = k - l / 2;
            return 1 - kthGrammar(n - 1, newK);
        }
    }
};