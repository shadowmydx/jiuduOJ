#include <iostream>
#define MAXN 10000001
using namespace std;

int Boys[MAXN];
int sum[MAXN];
void init()
{
    for(int i = 1;i < MAXN;i++)
    {
        Boys[i] = -1;
        sum[i]  = 1;
    }
}

int findRoot(int val)
{
    if(Boys[val] == -1)
        return val;
    else return Boys[val] = findRoot(Boys[val]);
}

int main(void)
{
    int n;
    while(cin >> n)
    {
        init();
        int boy1,boy2,maxNum = 1;
        for(int i = 0;i < n;i++)
        {
            cin >> boy1 >> boy2;
            int root1 = findRoot(boy1);
            int root2 = findRoot(boy2);
            if(root1 != root2)
            {
                Boys[root2] = root1;
                sum[root1] += sum[root2];
            }
        }
        for(int i = 1;i < MAXN;i++)
        {
            if(Boys[i] == -1 && sum[i] > maxNum)
                maxNum = sum[i];
        }
        cout << maxNum << endl;
    }
    return 0;
}
