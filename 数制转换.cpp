#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char check[] = "0123456789ABCDEF";

long long stringToTen(int a,string &n)
{
    long long result = 0;
    long long mask   = 1;
    for(int i = n.size() - 1;i >= 0;i--)
    {
        if(isalpha(n[i]))
        {
            result += (tolower(n[i]) - 87) * mask;
        }
        else result += (n[i] - '0') * mask;
        mask *= a;
    }
    return result;
}

string tenToX(long long val,int b)
{
    string result;
    if(val == 0)
        result = "0";
    while(val)
    {
        int dit = val % b;
        result = result + check[dit];
        val /= b;
    }
    return result;
}

void printAll(string &s)
{
    for(int i = s.size() - 1;i >= 0;i--)
        cout << s[i];
}

int main(void)
{
    int a,b;
    string n;
    while(cin >> a >> n >> b)
    {
        long long val = stringToTen(a,n);
        string result = tenToX(val,b);
        printAll(result);
        cout << endl;
    }
    return 0;
}
