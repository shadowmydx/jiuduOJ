#include <iostream>
using namespace std;

int prime[1111][1111];
int fac[1111][1111];

int num[1111];

void init()
{
    num[0] = 1;
    num[1] = 1;
    for(int i = 2;i < 1111;i++)
    {
        if(num[i] == 0)
        {
            for(int j = i * 2,q = 2;j < 1111;q++,j = i * q)
            {
                num[j] = 1;
            }
        }
    }
    for(int i = 2;i < 1111;i++)
    {
        int tmp = i;
        for(int j = 2;j <= i;j++)
        {
            if(tmp % j == 0 && num[j] == 0)
            {
                while(tmp % j == 0 && tmp != 0)
                {
                    prime[i][j]++;
                    tmp /= j;
                }
            }
        }
    }
    for(int i = 0;i < 1111;i++)
        fac[2][i] = prime[2][i];
    for(int i = 3;i < 1111;i++)
    {
        for(int j = 2;j < 1111;j++)
        {
            fac[i][j] = fac[i-1][j] + prime[i][j];
        }
    }
}

int main(void)
{
    int n,a;
    init();
    while(cin >> n >> a)
    {
        int min = (1 << 30);
        for(int i = 2;i < 1111;i++)
        {
            if(fac[n][i] == 0 && prime[a][i] != 0)
            {
                min = 0;
                break;
            }
            else if(fac[n][i] != 0 && prime[a][i] != 0)
            {
                int tmp = fac[n][i] / prime[a][i];
                if(tmp < min)
                    min = tmp;
            }
        }
        cout << min << endl;
    }
    return 0;
}
