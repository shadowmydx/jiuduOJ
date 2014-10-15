#include <iostream>
#include <vector>
using namespace std;

int num[200002];
vector<int> prime;

void init()
{
    for(int i = 2;i < 200002;i++)
    {
        if(num[i] == 0)
        {
            for(int j = i * 2,q = 2;j < 200002; q++,j = i * q)
                num[j] = 1;
            prime.push_back(i);
        }
    }
}

int main(void)
{
    init();
    int n;
    while(cin >> n)
    {
        cout << prime[n-1] << endl;
    }
    return 0;
}

