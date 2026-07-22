#include <iostream>
using namespace std;

// Right angled triangle pattern

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}