#include <iostream>
using namespace std;

int main() {
    int n = 5; // height of pyramid
    for (int i = 1; i <= n; i += 2) {
        int num = (n - i) / 2;
        
        // leading spaces
        for (int k = 0; k < num; k++) {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
