#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> number;
stack<char> oper;

int main(void)
{
    string target;
    string tmp = "";
    while(true)
    {
        getline(cin,target);
        if(target == "0")break;
        for(int i = 0;i < target.length();i++)
        {
            while(i < target.length() && target[i] >= '0' && target[i] <= '9')
            {
                tmp = tmp + target[i];
                i++;
            }
            int num = changeStrToNum(tmp);
            tmp.clear();
            number.push(num);
        }
    }
    return 0;
}
