#include <iostream>
#include <string>
using namespace std;
int N,Q;
char temp[6][6];
char all[3001][3001];

int pow(int num1,int num2)
{
    int result = 1;
    for(int i = 0;i < num1;i++)
        result *= num2;
    return result;
}

void doSomeThing(int x,int y,int length)
{
    if(length == N)
    {
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < N;j++)
                all[x+i][y+j] = temp[i][j];
        }
        return;
    }
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            if(temp[i][j] != ' ')
            {
                doSomeThing(x + i * (length/N),y + j * (length/N),length/N);
            }
        }
    }
}

void printAll(int length)
{
    for(int i = 0;i < length;i++)
    {
        for(int j = 0;j < length;j++)
        {
            cout << all[i][j];
        }
        cout << endl;
    }
}

void init(int length)
{
    for(int i  = 0;i < length;i++)
    {
        for(int j = 0;j < length;j++)
            all[i][j] = ' ';
    }
}

void getTemp()
{
    for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
            temp[i][j] = ' ';
    for(int i = 0;i < N;i++)
    {
        string tar;
        getline(cin,tar);
        for(int j = 0;j < tar.length();j++)
        {
            temp[i][j] = tar[j];
        }
    }
}

int main(void)
{
    while(cin >> N)
    {
        if(N == 0)
            break;
        getchar(); //直接刷新的函数不给用
        getTemp();
        cin >> Q;
        int length = pow(Q,N);
        init(length);
        doSomeThing(0,0,length);
        printAll(length);
    }
    return 0;
}
