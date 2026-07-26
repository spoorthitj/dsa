#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            cout << char('A' + j - 1);
            if (j > 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}