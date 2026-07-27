#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // print spaces
        for (int space = 1; space <= n - row; space++) {
            cout << " ";
        }
        // print stars
        for (int star = 0; star < row ; star++) {
            cout << char('A' + star);
        }
         for (int star = row - 2; star >= 0 ; star--) {
            cout << char('A' + star);
        }
        cout << endl;
    }

    return 0;
}
