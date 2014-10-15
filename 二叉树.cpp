#include <iostream>
using namespace std;

int findTreeHigh(int node)
{
    int result = 0;
    unsigned mask = 1;
    while(mask <= node)
    {
        result ++;
        mask <<= 1;
    }
    return result;
}

int findFirst(int node,int high)
{
    int result = node;
    high -= 1;
    while(high--)
    {
        result *= 2;
    }
    return result;
}

int findLast(int node,int high)
{
    int result = node;
    high -= 1;
    while(high--)
    {
        result = 2 * result + 1;
    }
    return result;
}

int findEnd(int first,int last,int n)
{
    int result = 0;
    for(int i = first;i <= n && i <= last;i++)
    {
        result ++;
    }
    return result;
}

int getTheNum(int high)
{
    unsigned mask   = 1;
    return (int)((mask << high) - 1);
}

int main(void)
{
    int n,m;//n是终点，m是子树父节点
    int wholeTree,partTree,tmp,first,last;
    int result;
    while(cin >> m >> n)
    {
        result = 0;
        if(m == 0 && n == 0)
            break;
        wholeTree = findTreeHigh(n);
        partTree  = findTreeHigh(m);
        tmp       = wholeTree - partTree;
        first     = findFirst(m,tmp+1);
        last      = findLast(m,tmp+1);
        result    = findEnd(first,last,n) + getTheNum(tmp);
        cout << result << endl;
    }
    return 0;
}
