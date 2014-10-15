#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
ע�⣺
1��̰���㷨�ǶԵġ�
2��Խ����淴�����
3����ȷ�������ԣ���һ��������������һ�����ڡ�����һֱ��a����a�Լ��ˣ��϶�Ҫ�������ڻ�ʲô��ȡ������һ�������յ㡣
4���Ҿ�Ȼ��Ϊ��a�Լ������a��������ô����˼��
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
