#include <iostream>
using namespace std;

//  reverse Right angled triangle pattern

int main()
{
    for(int i = 5; i > 0; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}