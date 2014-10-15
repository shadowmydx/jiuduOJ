#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
    friend class BinaryTree;
public:
    Node(char num)
    {
        this->num = num;
        this->left = NULL;
        this->right = NULL;
    }
protected:
    char num;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
    }
    ~BinaryTree()
    {
        lastOrderDelete(root);
    }
    void addNum(char num)
    {
        Node *data = new Node(num);
        Node *tmp;
        if(root == NULL)
        {
            root = data;
        }
        else
        {
            tmp = root;
            Node *pre;
            while(tmp != NULL)
            {
                pre = tmp;
                if(tmp->num > num)
                    tmp = tmp->left;
                else
                    tmp = tmp->right;
            }
            if(pre->num > num)
                pre->left = data;
            else
                pre->right = data;
        }
    }

    Node* getRoot()
    {
        return root;
    }

    void getLastOrder(Node *p,vector<char> &v)
    {
        if(p == NULL)
            return;
        getLastOrder(p->left,v);
        getLastOrder(p->right,v);
        v.push_back(p->num);
    }

    bool isEqual(BinaryTree *tmp)
    {
        vector<char> v1;
        vector<char> v2;
        Node *root1 = tmp->getRoot();
        getLastOrder(root,v1);
        getLastOrder(root1,v2);
        for(int i = 0;i < v1.size();i++)
        {
            if(v1[i] != v2[i])
                return false;
        }
        return true;
    }
private:
    Node *root;
    void lastOrderDelete(Node *root)
    {
        if(root == NULL)
            return;
        lastOrderDelete(root->left);
        lastOrderDelete(root->right);
        delete root;
    }
};


int main(void)
{
    int n;

    string input;
    string test;
    BinaryTree *start;
    BinaryTree *each;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cin >> input;
        start = new BinaryTree;
        for(int i = 0;i < input.length();i++)
            start->addNum(input[i]);
        while(n--)
        {
            each = new BinaryTree;
            cin >> test;
            for(int i = 0;i < test.length();i++)
                each->addNum(test[i]);
            if(each->isEqual(start))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            delete each;
        }
    }
    return 0;
}
