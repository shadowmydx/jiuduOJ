#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;
/*
错误：
1、读清题目，不要被输入所迷惑
*/
long long gcd(long long a,long long b)
{
    if(a % b == 0)
        return b;
    else return gcd(b,a % b);
}

long long gcm(long long a,long long b)
{
    if(a < b)
    {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    long long result = gcd(a,b);
    return a * b / result;
}

int main(void)
{
    int n,m;
    string line;
    cin >> n;
    getchar();
    while(n--)
    {
        cin >> m;
        long long result = 1;
        long long tmp = 0;
        while(m--)
        {
            cin >> tmp;
            result = gcm(result,tmp);
        }
        cout << result << endl;
    }
    return 0;
}
