#include <iostream>
using namespace std;
int main(void)
{
    int n;
    int k;
    while(cin >> n)
    {
        int mask = n * n;
        if(n < 10)
            k = 10;
        else
            k = 100;
        if(mask % k == n)
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
    return 0;
}
