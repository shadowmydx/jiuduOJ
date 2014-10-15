#include <iostream>
using namespace std;

int graphy[1001];
int n;

void init()
{
    for(int i = 1;i <= n;i++)
        graphy[i] = -1;
}

int findRoot(int num)
{
    if(graphy[num] == -1)
        return num;
    else return graphy[num] = findRoot(graphy[num]);
}

int main(void)
{
    int m;
    while(cin >> n >> m)
    {
        if(n == 0)break;
        init();
        int point1,point2,result = 0;
        for(int i = 0;i < m;i++)
        {
            cin >> point1 >> point2;
            int root1 = findRoot(point1);
            int root2 = findRoot(point2);
            if(root1 != root2)
            {
                graphy[root2] = root1;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(graphy[i] == -1)
                result ++;
            if(result == 2)
                break;
        }
        if(result == 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
