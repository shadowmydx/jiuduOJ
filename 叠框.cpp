#include <iostream>
using namespace std;
char buffer[100][100];
char a,b;
int first = 0;

void printAll(int n)
{
    if(first != 0)
        cout << endl;
    else first = 1;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
            cout << buffer[i][j];
        cout << endl;
    }
}

void getTheGra(int x,int y,int length,int flag)
{
    if(length <= 0)
        return;
    char tmp;
    tmp = (flag == 1 ? a : b);
    for(int i = 0;i < length;i++)
    {
        buffer[x][i+y] = tmp;
        buffer[x+length-1][i+y] = tmp;
    }
    for(int i = 0;i < length;i++)
    {
        buffer[i+x][y] = tmp;
        buffer[i+x][y+length-1] = tmp;
    }
    getTheGra(x+1,y+1,length-2,-flag);
}

int main(void)
{
    int n,flag; // 1说明要打要打印a，-1说明要打印b
    while(cin >> n >> a >> b)
    {

        if(n == 1)
        {
            if(first != 0)
                cout << endl;
            else first = 1;
            cout << a << endl;
        }
        else
        {
            if(((n-1) / 2) & 1)
            {
                flag = -1;
            }
            else flag = 1;
            getTheGra(0,0,n,flag);
            buffer[0][0] = ' ';
            buffer[n-1][0] = ' ';
            buffer[0][n-1] = ' ';
            buffer[n-1][n-1] = ' ';
            printAll(n);
        }
    }
    return 0;
}
