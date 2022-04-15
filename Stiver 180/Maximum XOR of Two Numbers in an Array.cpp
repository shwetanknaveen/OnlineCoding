//Problem link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
//Video link - https://www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7

//Time complexity = O(n)
struct Node
{
    struct Node *links[2];//each node has either 0 or 1
    bool flag;
    Node *getLink(int i)
    {
        return links[i];
    }
    void setLink(int i,Node *node)
    {
        links[i] = node;
    }
    void setEnd()
    {
        flag = true;
    }
};
class Trie
{
    public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    bool getBitVal(int bit,int num)//return 0 or 1
    {
        return num&(1<<bit);//tells whether bit at position = bit(0 based) in num is 0 or 1?
    }
    void insert(int i)//We will store the MSB on top of trie tree and so on
    {
        Node *node = root;
        for(int count=31;count>=0;count--)//int is of 32 bits
        {
            int bitVal = getBitVal(count,i);
            if(node->getLink(bitVal)==NULL)
            {
                node->setLink(bitVal,new Node());
            }
            node = node->getLink(bitVal);
        }
        node->setEnd();//We can skip this as each number inserted will be of 32 bits
    }
    int getMaxXOR(int x)//returns maximum XOR value which can be obtained XORing x with all numbers in the trie
    {
    	//Starting from top of trie tree(MSB bits), we will try to find opposite of bits of x in trie numbers for maximum XOR
        Node *node = root;
        int ans = 0;
        for(int i=31;i>=0;i--)//x is of 32 bits and MSB bit number is 31
        {
            int bitVal = getBitVal(i,x);
            if(node->getLink(!bitVal))//if opposite bit exists
            {
                ans = (ans<<1)+1;//opposite bit exists hence XOR at this bit will give 1 hence adding 1, before adding we
                				//shift the previous ans to right so that we add 1 at right place value
                node = node->getLink(!bitVal);
            }
            else//if opposite bit doesn't exists
            {
                ans = (ans<<1);//We don't add 1 as XOR at this place will be 0 and we just shift previous ans to right
                				//by 1 bit
                node = node->getLink(bitVal);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *obj = new Trie();
        for(int i:nums)//complexit is 32 x n
            obj->insert(i);
        int ans = 0;
        for(int i:nums)//complexity is 32 x n so total = O(32n + 32n) = O(n)
            ans = max(ans,obj->getMaxXOR(i));//find maximum XOR of each number with all numbers in the array
        return ans;
    }
};
