#include <iostream>
using namespace std;
int num[301];
int main(void)
{
    int n,x,flag;
    while(cin >> n)
    {
        flag = -1;
        for(int i = 0;i < n;i++)
            cin >> num[i];
        cin >> x;
        for(int i = 0;i < n;i++)
            if(num[i] == x)
                flag = i;
        cout << flag << endl;
    }
    return 0;
}
