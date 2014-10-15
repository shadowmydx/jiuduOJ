#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string keyboard1 = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string input;
    string result = "";
    while(getline(cin,input))
    {
        for(int i = 0;i < input.length();i++)
        {
            if(input[i] == ' ')
                result = result + ' ';
            int index = keyboard1.find(input[i]);
            result = result + keyboard1[index - 1];
        }
        cout << result << endl;
        result.clear();
        input.clear();
    }
    return 0;
}
