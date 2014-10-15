#include <iostream>
#include <string>
using namespace std;
string fun(int num)
{
    int bit[20] = {0};
    int tmp = num;
    int top = -1;
    int start = -1;
    int flag = 0;
    string result = "";
    while(tmp != 0)
    {
        bit[++top] = tmp & 1;
        if(flag == 0)
        {
            if(bit[top] == 1)
            {
                flag = 1;
                start = top;
            }
        }
        tmp = (unsigned)tmp >> 1;
    }
    for(int i = top;i >= 0;i--)
    {
        if(bit[i] == 1)
        {
            if(i > 2)
                result = result + "2" + "(" + fun(i) + ")";
            else
            {
                switch(i)
                {
                    case 0 : result = result + "2(0)";
                             break;
                    case 1 : result = result + "2";
                             break;
                    case 2 : result = result + "2(2)";
                             break;
                }
            }
            if(i > start)
                result = result + '+';
        }
    }
    return result;
}

int main(void)
{
    int num;
    string result;
    while(cin >> num)
    {
        result = fun(num);
        cout << result << endl;
    }
    return 0;
}
