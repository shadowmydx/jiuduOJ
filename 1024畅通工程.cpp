#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int x;
    int y;
    int length;
}edge;

bool cmp(const edge &a,const edge &b)
{
    return a.length < b.length;
}

int n,m;
int villege[200];
edge road[200];

void init()
{
    for(int i = 0;i <= n;i++)
    {
        road[i].x = 0;
        road[i].y = 0;
        road[i].length = 0;
    }
    for(int i = 0;i <= m;i++)
    {
        villege[i] = -1;
    }
}

int findRoot(int num)
{
    if(villege[num] == -1)
        return num;
    else return villege[num] = findRoot(villege[num]);
}

bool haveMst()
{
    int flag = 0;
    for(int i = 1;i <= m;i++)
        if(villege[i] == -1)
            flag ++;
    return flag == 1;
}

int main(void)
{
    while(cin >> n >> m)
    {
        if(n == 0)
            break;
        init();
        for(int i = 0;i < n;i++)
        {
            cin >> road[i].x >> road[i].y >> road[i].length;
        }
        sort(road,road+n,cmp);
        int result = 0;
        for(int i = 0;i < n;i++)
        {
            int root1 = findRoot(road[i].x);
            int root2 = findRoot(road[i].y);
            if(root1 != root2)
            {
                villege[root2] = root1;
                result += road[i].length;
            }
        }
        if(!haveMst())
            cout << '?' << endl;
        else cout << result << endl;
    }
    return 0;
}
