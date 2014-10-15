#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a % b == 0)
        return b;
    else return gcd(b,a % b);
}

int main(void)
{
    int a,b;
    while(cin >> a >> b)
    {
        if(a < b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        cout << gcd(a,b) << endl;
    }
    return 0;
}
