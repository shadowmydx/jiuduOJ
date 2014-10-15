#include <iostream>
using namespace std;
int pow(int num,int e)
{
    int result = 1;
    for(int i = 1;i <= e;i++)
        result *= num;
    return result;
}
int main(void)
{
    int A,B,K;
    while(cin >> A >> B >> K)
    {
        if(A == 0 && B == 0)
            break;
        int mask = pow(10,K);
        if(A % mask == B % mask)
            cout << -1 << endl;
        else
            cout << A + B << endl;
    }
    return 0;
}
