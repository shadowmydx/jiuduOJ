#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
注意：
1、贪心算法是对的。
2、越想后面反而想错
3、的确有周期性，第一个更换点属于下一个周期。比如一直用a，到a自己了，肯定要换，至于换什么就取决于下一个周期终点。
4、我居然认为到a自己后就用a，这是怎么个意思？
*/
set<string> server;
set<string> check;
int n,m;

int main(void)
{
    string tmp;
    vector<string> all;
    while(cin >> n)
    {
        int result = 0;
        int total = 0;
        for(int i = 0;i < n;i++)
        {
            cin >> tmp;
            server.insert(tmp);
        }
        cin >> m;
        for(int i = 0;i < m;i++)
        {
            cin >> tmp;
            all.push_back(tmp);
        }
        for(int i = 0;i < m;i++)
        {
            set<string>::iterator it1;
            it1 = server.find(all[i]);
            if(it1 != server.end())
            {
                set<string>::iterator it2;
                it2 = check.find(all[i]);
                if(it2 == check.end())
                {
                    total ++;
                    check.insert(all[i]);
                }
            }
            if(total == n)
            {
                check.clear();
                result = n==1 ? -1 : result + 1;
                total = 0;
            }
        }
        cout << result << endl;
        server.clear();
        check.clear();
        all.clear();
    }
    return 0;
}
