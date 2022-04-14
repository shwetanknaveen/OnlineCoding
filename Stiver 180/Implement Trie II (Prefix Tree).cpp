//Problem link - Leetcode premium question - https://leetcode.com/problems/implement-trie-ii-prefix-tree/
//Video link - https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=3
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset 
of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
void erase(String word) Erases the string word from the trie.
 

Example 1:

Input
["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", 
"countWordsStartingWith", "erase", "countWordsStartingWith"]
[[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
Output
[null, null, null, 2, 2, null, 1, 1, null, 0]

Explanation
Trie trie = new Trie();
trie.insert("apple");               // Inserts "apple".
trie.insert("apple");               // Inserts another "apple".
trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
trie.erase("apple");                // Erases one "apple".
trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
trie.countWordsStartingWith("app"); // return 1
trie.erase("apple");                // Erases "apple". Now the trie is empty.
trie.countWordsStartingWith("app"); // return 0
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, countWordsEqualTo, countWordsStartingWith, and erase.
It is guaranteed that for any function call to erase, the string word will exist in the trie.
*/


struct Node 
{
    struct Node *links[26];
    int countWord;
    int countPref;
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
        countWord++;//No increment in countPref as it has already been increased in insert()
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
            node->countPref++;//Count of prefix increases at each stage in the pointed node
        }
        node->setEnd();
    }
    
    int countWordsEqualTo(string word) {
        Node *node = root;
        for(char ch:word)
        {
            if(node->getLink(ch)==NULL)
                return 0;
            node = node->getLink(ch);
        }
        return node->countWord;
    }
    
    int countWordsStartingWith(string prefix) {
        Node *node = root;
        for(char ch:prefix)
        {
            if(node->getLink(ch)==NULL)
                return 0;
            node = node->getLink(ch);
        }
        return node->countPref;
    }
    
    void erase(string word) {
        Node *node = root;
        for(char ch:word)
        {
            node = node->getLink(ch);
            node->countPref--;//countPref is decreased at each level in the pointed node
        }
        node->countWord--;//countPref is not decreased here as it has already been decreased in the above loop for the end
        				//node too
        if(node->countWord==0)//if now word count for this word is zero then we set the end flag as false
            node->flag = false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
