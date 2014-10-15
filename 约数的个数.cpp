#include <iostream>
#include <cmath>
using namespace std;

int findTheResult(int num)
{
    int length =  (int)sqrt(num) + 1;
    int result = 0;
    for(int i = 1;i < length;i++)
    {
        if(num % i == 0 && num / i != i)
            result += 2;
        else if(num % i == 0)
            result ++;
    }
    return result;
}

int main(void)
{
    int n;
    while(cin >> n)
    {
        int tmp;
        for(int i = 0;i < n;i++)
        {
            int result = 0;
            cin >> tmp;
            result = findTheResult(tmp);
            cout << result << endl;
        }
    }
    return 0;
}
