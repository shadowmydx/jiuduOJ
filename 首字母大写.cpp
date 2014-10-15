#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char a)
{
    return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
}

int main(void)
{
    string tmp;
    string result = "";
    int k = 0;
    while(getline(cin,tmp))
    {
        int flag = false;
        for(int i = 0;i < tmp.size();i++)
        {
            if(isAlpha(tmp[i]) && flag == false)
            {
                flag = true;
                if(tmp[i] >= 'a' && tmp[i] <= 'z')
                    k = 32;
            }
            else if(!isAlpha(tmp[i]))
            {
                flag = false;
                k = 0;
            }
            else
                k = 0;
            result = result + (char)(tmp[i] - k);
        }
        cout << result << endl;
        result.clear();
    }
    return 0;
}
