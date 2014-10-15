#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int x;
    int y;
    int length;
}edge;

int villege[200];
edge road[6000];
int n;

bool cmp(const edge &a,const edge &b)
{
    return a.length < b.length;
}

void init()
{
    for(int i = 0;i < 200;i++)
        villege[i] = -1;
    for(int i = 0;i < 6000;i++)
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
        if(0 == n)
            break;
        init();
        int board = (n * (n-1)) / 2;
        int flag,a1,a2,a3,top = 0;
        for(int i = 0;i < board;i++)
        {
            cin >> a1 >> a2 >> a3 >> flag;
            if(flag == 1)
            {
                /*
                注意！！想法是对的，但是合并的方法是错的！！
                */
                int root1 = findRoot(a1);
                int root2 = findRoot(a2);
                if(root1 != root2)
                {
                    villege[root2] = root1;
                }
            }
            else
            {
                road[top].x = a1;
                road[top].y = a2;
                road[top].length = a3;
                top ++;
            }

        }
        sort(road,road+top,cmp);
        int result = 0;
        for(int i = 0;i < top;i++)
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
