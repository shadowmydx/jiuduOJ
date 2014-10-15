#include <iostream>
using namespace std;
int n;
int table[2000];

int findRoot(int num)
{
    if(table[num] == -1)
        return num;
    else return table[num] = findRoot(table[num]);
}

void init()
{
    for(int i = 1;i <= n;i++)
        table[i] = -1;
}

int main(void)
{
    int t,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        init();
        int fre1,fre2;
        for(int i = 0;i < m;i++)
        {
            cin >> fre1 >> fre2;
            int root1 = findRoot(fre1);
            int root2 = findRoot(fre2);
            if(root1 != root2)
            {
                table[root2] = root1;
            }
        }
        int result = 0;
        for(int i = 1;i <= n;i++)
        {
            if(table[i] == -1)
                result ++;
        }
        cout << result << endl;
    }
    return 0;
}
