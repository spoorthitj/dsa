#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char('E' - (j - 1));
            if (j < i) cout << " ";
        }
        cout << endl;
    }
    return 0;
}