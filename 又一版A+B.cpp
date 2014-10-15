#include <iostream>
using namespace std;
int top = -1;
int num[1000];

void changeToX(long long a,int m)
{
    while(a)
    {
        num[++top] = a % m;
        a /= m;
    }
}

void printNum()
{
    for(int i = top;i >= 0;i--)
        cout << num[i];
}

int main(void)
{
    int m;
    long long a,b;
    while(true)
    {
        cin >> m;
        if(0 == m)
            break;
        cin >> a >> b;
        top = -1;
        a = a + b;
        changeToX(a,m);
        printNum();
        if(a == 0)
            cout << a; //注意！！！0 + 0是特殊值！
        cout << endl;
    }
    return 0;
}
