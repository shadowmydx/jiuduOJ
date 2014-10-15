#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int num[40000];
vector<int> prime;
int check[40000];
stack<int> initStk;

void init()
{
    num[0] = 1;
    num[1] = 1;
    for(int i = 2;i < 40000;i++)
    {
        if(num[i] == 0)
        {
            prime.push_back(i);
            for(int j = 2 * i,q = 2;j < 40000;q++,j = i * q)
                num[j] = 1;
        }
    }
}

int main(void)
{
    init();
    int n;
    while(true)
    {
        int result = 0;
        cin >> n;
        if(0 == n)break;
        for(int i = 0;n > prime[i] && i < prime.size();i++)
        {
            if(n > prime[i] && num[n - prime[i]] == 0 && check[prime[i]] == 0)
            {
                //cout << prime[i] << " " << n - prime[i] << endl;
                check[n-prime[i]] = 1;
                result ++;
                initStk.push(n-prime[i]);
            }
        }
        cout << result << endl;
        while(!initStk.empty())
        {
            check[initStk.top()] = 0;
            initStk.pop();
        }
    }
    return 0;
}
