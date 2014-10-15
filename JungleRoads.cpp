#include <iostream>
#include <algorithm>
#include <string>
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

int villege[29];
edge road[100];
int n;

void init()
{
    for(int i = 0;i < 29;i++)
        villege[i] = -1;
    for(int i = 0;i < 100;i++)
    {
        road[i].x = 0;
        road[i].y = 0;
        road[i].length = 0;
    }
}

int findRoot(int num)
{
    if(villege[num] == -1)
        return num;
    else return villege[num] = findRoot(villege[num]);
}

int main(void)
{
    while(cin >> n)
    {
        if(0 == n)break;
        init();
        int top = -1;
        int times,weight;
        string pointStart,pointEnd;
        for(int i = 0;i < n - 1;i++)
        {
            cin >> pointStart;
            cin >> times;
            for(int j = 0;j < times;j++)
            {
                cin >> pointEnd;
                cin >> weight;
                road[++top].x = pointStart[0] - 'A';
                road[top].y   = pointEnd[0]   - 'A';
                road[top].length = weight;
            }
        }
        sort(road,road+top+1,cmp);
        int result = 0;
        for(int i = 0;i <= top;i++)
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
