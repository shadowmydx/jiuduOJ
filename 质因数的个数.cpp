#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
int num[100001];

void init()
{
    num[0] = 1;
    num[1] = 1;
    for(int i = 2;i < 100001;i++)
    {
        if(num[i] == 0)
        {
            prime.push_back(i);
            for(int j = i * 2,q = 2; j < 100001;q++,j = i * q)
            {
                num[j] = 1;
            }
        }
    }
}

int main(void)
{
    init();
    int n;
    while(cin >> n)
    {
        int result = 0;
        int here = n;
        for(int i = 0;i < prime.size();i++)
        {
            if(n % prime[i] == 0)
            {
                while(n % prime[i] == 0 && n != 0)
                {
                    result ++;
                    n /= prime[i];
                }
            }
        }
        if(n > 1)
            result ++;
        cout << result << endl;
    }
    return 0;
}
