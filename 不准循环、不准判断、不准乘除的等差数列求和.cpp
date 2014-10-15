#include <iostream>
using namespace std;

int cal(int num)
{
    num || goto al;
    return cal(num-1) + num;
    al:
        return 0;
}

int main(void)
{
    int n;
    cin >> n;
    cout << cal(n) << endl;
    return 0;
}
