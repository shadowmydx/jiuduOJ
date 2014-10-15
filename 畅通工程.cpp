#include <iostream>
using namespace std;
int city[1001];
int N,M;

void init()
{
    for(int i = 1;i <= N;i++)
    {
        city[i] = -1;
    }
}

int findRoot(int num)
{
    if(city[num] == -1)
        return num;
    else return city[num] = findRoot(city[num]);
}

int countRoad()
{
    int result = 0;
    for(int i = 1;i <= N;i++)
        if(city[i] == -1)
            result ++;
    return result - 1;
}

int main(void)
{
    int start,end;
    while(cin >> N >> M)
    {
        if(N == 0)
            break;
        init();
        for(int i = 0;i < M;i++)
        {
            cin >> start >> end;
            int root1 = findRoot(start);
            int root2 = findRoot(end);
            if(root1 != root2)
            {
                city[root2] = root1;
            }
        }
        int result = countRoad();
        cout << result << endl;
    }
    return 0;
}
