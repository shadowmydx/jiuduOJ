#include <iostream>
#include <vector>
using namespace std;

void getNum(int a,vector<int> &v)
{
    if(a == 0)
        v.push_back(0);
    else
    {
        while(a)
        {
            v.push_back(a%10);
            a /= 10;
        }
    }
}

int cal(vector<int> &v1,vector<int> &v2)
{
    int result = 0;
    for(int i = 0;i < v1.size();i++)
    {
        for(int j = 0;j < v2.size();j++)
            result += v1[i] * v2[j];
    }
    return result;
}

int main(void)
{
    int a,b;
    vector<int> v1;
    vector<int> v2;
    while(cin >> a >> b)
    {
        getNum(a,v1);
        getNum(b,v2);
        cout << cal(v1,v2) << endl;
        v1.clear();
        v2.clear();
    }
    return 0;
}
