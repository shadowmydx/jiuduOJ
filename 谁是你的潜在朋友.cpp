#include <iostream>
using namespace std;
int main(void)
{
    int book[300] = {0};
    int man[300]  = {0};
    int N,M;
    while(cin >> N >> M)
    {
        for(int i = 0;i < N;i++)
        {
            cin >> man[i];
            book[man[i]] ++;
        }
        for(int i = 0;i < N;i++)
        {
            if(book[man[i]] > 1)
                cout << book[man[i]] - 1 << endl;
            else cout << "BeiJu" << endl;
        }
        for(int i = 0;i < 300;i++)
            book[i] = 0;
    }
    return 0;
}
