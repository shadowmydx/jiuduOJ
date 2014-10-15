#include <iostream>
using namespace std;

int num[10002];

void init()
{
    for(int i = 2;i < 10002;i++)
    {
        if(num[i] == 0)
        {
            for(int j = i * 2,q = 2;j < 10002; q++,j = i * q)
                num[j] = 1;
        }
    }
}

int main(void)
{
    init();
    int n;
    while(cin >> n)
    {
        bool flag = false;
        for(int i = 2;i < n;i++)
        {
            if(num[i] == 0 && i % 10 == 1)
            {
                if(flag == false)
                {
                    flag = true;
                    cout << i;
                }
                else cout << " " << i;
            }
        }
        if(flag == false)
            cout << -1;
        cout << endl;
    }
    return 0;
}
