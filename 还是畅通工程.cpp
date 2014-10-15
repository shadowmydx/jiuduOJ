#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int x;
    int y;
    int length;
}edge;

int n;
edge road[6000];
int villege[201];

bool cmp(const edge &a,const edge &b)
{
    return a.length < b.length;
}

int findRoot(int num)
{
    if(villege[num] == -1)
        return num;
    else return villege[num] = findRoot(villege[num]);
}

void init()
{
    for(int i = 0;i < 201;i++)
    {
        villege[i] = -1;
    }
    for(int i = 0;i < 6000;i++)
    {
        road[i].x  = 0;
        road[i].y  = 0;
        road[i].length = 0;
    }
}

int main(void)
{
    while(cin >> n)
    {
        if(0 == n)
            break;
        int board = (n * (n - 1)) / 2;
        init();
        for(int i = 0;i < board;i++)
        {
            cin >> road[i].x >> road[i].y >> road[i].length;
        }
        sort(road,road + board,cmp);
        int result = 0;
        for(int i = 0;i < board;i++)
        {
            int root1 = findRoot(road[i].x);
            int root2 = findRoot(road[i].y);
            if(root1 != root2)
            {
                villege[root2] = root1;
                result += road[i].length;
            }
        }
        cout << result << endl;
    }
    return 0;
}
