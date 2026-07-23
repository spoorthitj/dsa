#include <iostream>
using namespace std;

//  reverse Right angled triangle pattern

int main()
{
    for(int i = 1; i <=5; i++)
    {
        int num=0;
        while(num<5-i){
            cout<<" ";
            num++;
        }
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    return 0;
}