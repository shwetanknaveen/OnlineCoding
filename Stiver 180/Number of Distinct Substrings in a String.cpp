//Problem link - https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/ (Premium Question)
//https://bit.ly/3ocRQW0
//Video link - https://www.youtube.com/watch?v=RV0QeTyHZxo&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=4

//Brute force method - 
class Solution {
public:
    int countDistinct(string s) {
        unordered_set<string> st;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
			st.insert(s.substr(i,j-i+1));
	}
	return st.size();
    }
};

//Trie method -->This also threw TLE. It can be just understood as an approach
struct Node 
{
    struct Node *links[26];
    bool flag;
    Node *getLink(char ch)
    {
        return links[ch-'a'];
    }
    void setLink(char ch,Node *node)
    {
        links[ch-'a'] = node;
    }
    void setEnd()
    {
        flag = true;
    }
    
};
class Trie {
public:
    int distinctSubStrs;
    Node *root;
    Trie() {
        root = new Node();
        distinctSubStrs = 0;
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)
            {
                node->setLink(ch,new Node());
                distinctSubStrs++;//whenever a new character is inserted then new subtring is counted
            }
            node = node->getLink(ch);
        }
        node->setEnd();
    }
};
class Solution {
public:
    int countDistinct(string s) {
        Trie *obj = new Trie();
        for(int i=0;i<s.length();i++)//insert all substrings
	    {
		    for(int j=i;j<s.length();j++)
			    obj->insert(s.substr(i,j-i+1));
	    }
        return obj->distinctSubStrs;
    }
};
