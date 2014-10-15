#include <iostream>
using namespace std;

bool isSame(int num)
{
    int a[10];
    int top = -1;
    while(num)
    {
        a[++top] = num % 10;
        num /= 10;
    }
    int i = 0;
    while(i < top)
    {
        if(a[i] != a[top])
            return false;
        i++;
        top--;
    }
    return true;
}

int main(void)
{
    for(int i = 0;i < 257;i++)
    {
        if(isSame(i * i))
            cout << i << endl;
    }
    return 0;
}
