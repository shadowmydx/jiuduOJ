#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
1、分配序号
2、需要合并则合并集合，更新集合总权重，更新单个结点权重
3、寻找各个集合中权重最大的点
*/
int n,k;
int gang[2001];
int start = 1;
int sum[2001];
int weight[2001];
map<string,int> order;
map<int,string> reOrder;

void init()
{
    order.clear();
    reOrder.clear();
    start = 1;
    for(int i = 0;i <= n;i++)
    {
        gang[i] = -1;
        sum[i] = 0;
        weight[i] = 0;
    }
}

int getNum(string &name)
{
    if(order.find(name) == order.end())
    {
        order[name] = start;
        reOrder[start] = name;
        start ++;
    }
    return order[name];
}

int findRoot(int num)
{
    if(gang[num] == -1)
        return num;
    else return gang[num] = findRoot(gang[num]);
}

void printResult()
{
    int all = 0;
    int gangHead[2001];
    int member[2001];
    string head[2001];
    vector<int> rootNum;
    map<string,int> person;
    for(int i = 1;i <= n;i++)
    {
        gangHead[i] = i;
        member[i]   = 0;
        if(gang[i] == -1 && sum[i] > k)
        {
            rootNum.push_back(i);
            all ++;
        }
    }
    if(all == 0)
        cout << all << endl;
    if(all != 0)
    {
        int top = -1;
        for(int i = 1;i <= n;i++)
        {
            int root = findRoot(i);
            member[root] ++;
            if(weight[gangHead[root]] < weight[i])
            {
                gangHead[root] = i;
            }
        }
        for(int i = 0;i < rootNum.size();i++)
        {
            int now = rootNum[i];
            if(member[now] < 3)
            {
                all --;
                continue;
            }
            int nameNum = gangHead[now];
            head[++top] = reOrder[nameNum];
            person[head[top]] = member[now];
        }
        if(top != -1)
            sort(head,head+top+1);
        cout << all << endl;
        for(int i = 0;i <= top;i++)
        {
            cout << head[i] << " " << person[head[i]] << endl;

        }
    }
}

int main(void)
{
    while(cin >> n >> k)
    {
        init();
        string name1,name2;
        int Time,numName1,numName2;
        for(int i = 0;i < n;i++)
        {
            cin >> name1 >> name2 >> Time;
            numName1 = getNum(name1);
            numName2 = getNum(name2);
            weight[numName1] += Time;
            weight[numName2] += Time;

            //cout << name1 << " " << weight[numName1] << endl;
            //cout << name2 << " " << weight[numName2] << endl;

            int root1 = findRoot(numName1);
            int root2 = findRoot(numName2);
            if(root1 != root2)
            {
                gang[root2] = root1;
                sum[root1] += sum[root2]; //若需要合并，则要把两个集合的现有权重相加
            }
            sum[root1] += Time; //将当前Time的权重加入集合
        }
        printResult();
    }
    return 0;
}
