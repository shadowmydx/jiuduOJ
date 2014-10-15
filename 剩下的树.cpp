#include <iostream>
using namespace std;
int main(void)
{
    int tree[10001] = {0};
    int L,M,start,end;
    int result = 0;
    while(cin >> L >> M)
    {
        for(int i = 0;i <= L;i++)
            tree[i] = 1;
        for(int i = 0;i < M;i++)
        {
            cin >> start >> end;
            for(int j = start;j <= end;j++)
                tree[j] = 0;
        }
        for(int i = 0;i <= L;i++)
            if(tree[i] == 1)
                result ++;
        cout << result << endl;
        result = 0;
    }
    return 0;
}
