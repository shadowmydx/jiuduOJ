#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    string myStr;
    map<string,int> myMap;
    vector<string> myVec;
    map<string,int>::iterator it;
    vector<string>::iterator myIt;
    while(cin >> myStr)
    {
        for(int i = 0;i < myStr.length();i++)
        {
            for(int j = i;j < myStr.length();j++)
            {
                string myTmp = myStr.substr(i,j - i + 1);
                it = myMap.find(myTmp);
                if(it != myMap.end())
                {
                    myMap[myTmp] ++;
                }
                else
                    myMap[myTmp] = 1;
            }
        }
        for(it = myMap.begin();it != myMap.end();it++)
        {
            myVec.push_back(it->first);
        }
        sort(myVec.begin(),myVec.end());
        for(myIt = myVec.begin();myIt != myVec.end();myIt++)
        {
            if(myMap[*myIt] > 1)
                cout << *myIt  << " " << myMap[*myIt] << endl;
        }
        myVec.clear();
        myMap.clear();
    }
    return 0;
}
