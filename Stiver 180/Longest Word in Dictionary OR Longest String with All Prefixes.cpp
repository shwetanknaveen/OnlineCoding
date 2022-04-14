//Problem link - https://leetcode.com/problems/longest-word-in-dictionary/
//See problem from coding ninja also - https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos
//Video link - https://www.youtube.com/watch?v=AWnBa91lThI&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=3

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
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)
            {
                node->setLink(ch,new Node());
            }
            node = node->getLink(ch);
        }
        node->setEnd();
    }
    
    bool searchWord(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)
                return false;
            node = node->getLink(ch);
        }
        return node->flag;
    }
    
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *obj = new Trie();
	for(string s: words)//insert all words in the trie data structure
		obj->insert(s);
	string ans;
	bool flag;
	for(string str:words)
	{
		if(str.length()<ans.length()) continue;//for optimisation as no need to check for those word's prefixes which is 
											//smaller than present ans
		flag = true;//let's suppose that this word has all its prefixes in words
		for(int i=0;i<str.length();i++)
		{
			if(!obj->searchWord(str.substr(0,i+1)))//if this prefix is not in the words
			{
				flag = false;
				break;
			}
		}
		if(flag)//if all the prefixes of last word was in words
		{
			if(ans.length()<str.length())
				ans = str;//largest word has to be taken
			else if(ans.length()==str.length())//if two contenders have same length then lexicographically smaller one should
												//be taken as ans;
			{
				if(ans.compare(str)>0)
					ans = str;
			}
		}
	}
	return ans;
    }
};
