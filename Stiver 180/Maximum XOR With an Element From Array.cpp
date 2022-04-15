//Problem link - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
//Video link - https://www.youtube.com/watch?v=Q8LhG9Pi5KM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=8

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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int nQueries = queries.size();
        vector<int> ans(nQueries);
        vector<vector<int>> newQueries(nQueries);
        for(int i=0;i<queries.size();i++)
        {
            newQueries[i].push_back(queries[i][1]);//push limit on the first index
            newQueries[i].push_back(queries[i][0]);//push number with which XOR has to be taken on second index
            newQueries[i].push_back(i);//push index of the query also on the third index
        }
        sort(newQueries.begin(),newQueries.end());//sort queris on the basis of their limits of maximum value
        sort(nums.begin(),nums.end());
        
        Trie *obj = new Trie();
        int j=0;
        for(int i=0;i<newQueries.size();i++)
        {
            int lim = newQueries[i][0];
            for(;nums[j]<=lim && j<nums.size();j++)//obviously next member will have higher limit hence no need to reinsert those numbers from begining again
            {
                obj->insert(nums[j]);
            }
            if(!obj->root->getLink(0) && !obj->root->getLink(1))//if no number in nums was bigger than limit for this query
                ans[newQueries[i][2]]=-1; //this ans is for query number newQueries[i][2]
            else
                ans[newQueries[i][2]]=obj->getMaxXOR(newQueries[i][1]);
        }
        return ans;
    }
};
