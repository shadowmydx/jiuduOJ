#include <iostream>
#include <string>
using namespace std;
int cal(string num)
{
    int result = 0;
    for(int i = 0;i < num.length();i++)
    {
        result += num[i] - '0';
    }
    return result;
}

string numToStr(int num)
{
    string tmp = "";
    while(num)
    {
        tmp = tmp + (char)(num % 10 + '0');
        num /= 10;
    }
    return tmp;
}

int main(void)
{
    string n;
    while(cin >> n)
    {
        if("0" == n)
            break;
        int result = cal(n);
        while(result >= 10)
        {
            n      = numToStr(result);
            result = cal(n);
        }
        cout << result << endl;
    }
    return 0;
}
