#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        // print spaces
        for (int space = 1; space <= n - row; space++) {
            cout << "  ";
        }
        // print stars
        for (int star = 1; star <= 2 * row - 1; star++) {
            if(row==1 || row==n || star==1 || star==2*row-1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
            
        }
        cout << endl;
    }

    return 0;
}
