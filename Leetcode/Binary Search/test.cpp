/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct BinaryTree
{
    BinaryTree *left,*right;
    int value;
    BinaryTree(int val)
    {
        value = val;
        left = right = NULL;
    }
}
vector<int> helper(BinaryTree *node)
{
    vector<int> ans;
    queue<BinaryTree*> qu;
    if(!node) return ans;
    BinaryTree *thisNode;
    qu.push(node);
    while(!qu.empty())
    {
        int sum = 0, siz = qu.size();
        while(siz--)
        {
            thisNode = qu.front();
            qu.pop();
            sum += thisNode->value;
            if(thisNode->left) qu.push(thisNode->left);
            if(thisNode->right) qu.push(thisNode->right);
        }
        ans.push_back(sum);
    }
    return ans;
}

int main()
{
    BinaryTree *root = new BinaryTree(1);
    BinaryTree *leftChild = new BinaryTree(2);
    BinaryTree *rightChild = new BinaryTree(3);
    
    root->left = leftChild;
    root->right = rightChild;
    vector<int> ans = helper(root);
    for(int i: ans)
    cout<<i<<"\t";

    return 0;
}

