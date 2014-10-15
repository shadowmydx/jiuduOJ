#include <iostream>
using namespace std;

int rever(int num)
{
    int result = 0;
    int mask   = 1000;
    while(num)
    {
        result += (num % 10) * mask;
        num /= 10;
        mask /= 10;
    }
    return result;
}

int main(void)
{
    for(int i = 1000;i < 1112;i++)
    {
        if(i * 9 == rever(i))
            cout << i << endl;
    }
    return 0;
}
