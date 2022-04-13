//Problem link - https://leetcode.com/problems/implement-trie-prefix-tree/
//Video link - https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp

struct Node 
{
    struct Node *links[26];
    bool flag;
    Node *getLink(char ch)
    {
        return links[ch-'a'];
    }
    void setLink(char ch,Node *node)//don't allocate node = new Node() here rather pass it here and attach to the links
    {
        links[ch-'a'] = node;
    }
    void setEnd()//word has ended hence mark flag = true;
    {
        flag = true;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();//initialise root
    }
    
    void insert(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)//if link for this character is not set already then set it with new Node()
            {
                node->setLink(ch,new Node());
            }
            node = node->getLink(ch);//either link was previously set or set in the above step, we have to move our node
            						//to that set link
        }
        node->setEnd();//once word is completed, we have to mark the flag as true so as to indicate that word comletion
    }
    
    bool search(string word) {//search is this word is exists as it is or not
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)
                return false;//here from this character itself, word doesn't exist
            node = node->getLink(ch);
        }
        return node->flag;//if this was last i.e., it shouldn't exist as prefix
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char ch:prefix)
        {
            if(node->getLink(ch)==NULL)//here from this character itself, word doesn't exist
                return false;
            node = node->getLink(ch);
        }
        return true;//once we have found whole word and reached here then we need not check that this was end or not because
        			//we are looking for prefix hence we just return true
    }
};
