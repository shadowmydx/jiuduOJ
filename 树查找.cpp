#include <iostream>
using namespace std;
int n;
int node[2000];

void printTree(int level)
{
    int start = (1 << (level - 1));
    int last  = (1 << level);
    if(start > n)
        cout << "EMPTY";
    else
    {
        cout << node[start];
        for(int i = start + 1;i < last && i <= n;i++)
        {
            cout << " " << node[i];
        }
    }
}

int main(void)
{
    int level;
    while(cin >> n)
    {
        for(int i = 1;i <= n;i++)
            cin >> node[i];
        cin >> level;
        printTree(level);
        cout << endl;
    }
    return 0;
}
