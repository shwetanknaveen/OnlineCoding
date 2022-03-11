/*
In this problem you have to write a program to check if two given binary trees are structurally equivalent.
Two trees are structurally equivalent if they are both null or if the left and right children of one are structurally 
equivalent to the RESPECTIVE children of the other. In other words, when you draw the trees on paper, they should LOOK alike 
(ignoring the values at the nodes).
Construct a binary search tree with the input in the second line and use this as the basis-tree. For each of the remaining N-1
lines, construct a binary search tree and compare against the basis tree for equivalence. If the trees are equivalent, print 
YES else print NO. Also print the depth difference between the two trees (ie, depth of the bigger tree minus the depth of the 
smaller tree). Both these for a given tree pair must be on one line separated by a space.
The answers for the different pairs must be on separate lines.

Input - 
The input to the program is a number N followed by N lines of input. Each line consists of a sequence of positive numbers 
terminated by -1. There will be no duplicate numbers in any of the lines.

Sample I/O - 
Input

5

1 3 2 4 -1

4 1 2 3 -1

3 2 1 4 -1

4 3 2 1 -1

1 3 4 2 -1

Output

NO 1
NO 0
NO 1
YES 0
(Note that the depth difference will be zero if the trees are equivalent.)

*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	Node(int val)
	{
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
}
int height(Node *root)
{
	if(!root) return 0;
	return 1+max(height(root->left),height(root->right));
}
bool isSame(Node *t1, Node *t2)
{
	if(!t1 || !t2)
		return t1==t2;
	return isSame(t1->left,t2->left && isSame(t1->right,t2->right));
}

void pushNode(int val,Node *root)
{
	while(root)
	{
		if(root->val >val)
		{
			if(root->left == NULL)
			{
				root->left = new Node(val);
				return;
			}
			else root = root->left;
		}
		else
		{
			if(root->right == NULL)
			{
				root->right = new Node(val);
				return;
			}
			else root = root->right;
		}
	}
}
Node *constrBinaryTree(vector<int> &vals)
{
	if(vals.size()==0)
		return NULL;
	Node *root = new Node(vals[0]);
	for(int i=1;i<vals.size();i++)
	{
		pushNode(vals[i],root);
	}
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> base;
	vector<vector<int> > bsts;
	int val = 0;
	while(1)
	{
		cin>>val;
		if(val == -1)
			break;
		base.push_back(val);
	}
	for(int i=0;i<n-1;i++)
	{
		val = 0;
		vector<int> vect;
		while(1)
		{
			cin>>val;
			if(val==-1)
			{
				bsts.push_back(vect);
				break;
			}
			vect.push_back(val);
		}
	}
	Node *baseRoot = constrBinaryTree(base);
	int baseHeight = height(baseRoot);
	for(int i=0;i<n-1;i++)
	{
		Node *thisTree = constrBinaryTree(bsts[i]);
		if(isSame(baseRoot,thisTree));
			cout<<"YES "<<0;
		else
			cout<<"NO "<<abs(baseHeight - height(thisTree));
		
		if(i != n-2)
			cout<<"\n";
	}
	return 0;
}
