#include <iostream>
using namespace std;

int result[22];

void init()
{
    result[1] = 1;
    result[2] = 2;
    for(int i = 3;i < 22;i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
}

int main(void)
{
    int n;
    init();
    while(cin >> n)
    {
        cout << result[n] << endl;
    }
    return 0;
}
