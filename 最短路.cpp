#include <iostream>
using namespace std;

int ans[101][101];
int n,m;

void init()
{
    for(int i = 0;i < 101;i++)
        for(int j = 0;j < 101;j++)
            ans[i][j] = 0;
}

void findTheMin()
{
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(ans[i][k] == 0 || ans[k][j] == 0)continue;
                if(ans[i][j] == 0 || ans[i][j] > ans[i][k] + ans[k][j])
                    ans[i][j] = ans[i][k] + ans[k][j];
            }
        }
    }
}

int main(void)
{
    while(cin >> n >> m)
    {
        if(0 == n && 0 == m)
            break;
        init();
        for(int i = 0;i < m;i++)
        {
            int x,y,length;
            cin >> x >> y >> length;
            ans[x][y] = length;
            ans[y][x] = length;
        }
        findTheMin();
        cout << ans[1][n] << endl;
    }
    return 0;
}
