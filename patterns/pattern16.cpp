#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // number of rows for the upper half

    // upper half
    for (int row = 1; row <= n; row++) {
        // spaces
        for (int space = 1; space <= n - row; space++) {
            cout << "  ";
        }
        // stars
        for (int star = 1; star <= 2 * row - 1; star++) {
            cout << "* ";
        }
        cout << endl;
    }

    // lower half
    for (int row = n - 1; row >= 1; row--) {
        // spaces
        for (int space = 1; space <= n - row; space++) {
            cout << "  ";
        }
        // stars
        for (int star = 1; star <= 2 * row - 1; star++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
