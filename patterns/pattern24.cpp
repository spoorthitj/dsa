#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // number of rows

    for (int row = 0; row < n; row++) {
        int val = 1;  // first value in each row is 1
        for (int col = 0; col <= row; col++) {
            cout << val << " ";
            // update value using formula: nCr = nC(r-1) * (row - col) / (col + 1)
            val = val * (row - col) / (col + 1);
        }
        cout << endl;
    }

    return 0;
}
