//Problem link - https://leetcode.com/problems/max-number-of-k-sum-pairs/

//Approach 1
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> nCount;
        for(int i:nums)
            nCount[i]++;
        
        int ans = 0;
        for(auto itr=nCount.begin();itr!=nCount.end();itr++)
        {
            int n1 = itr->first, n2 = k-itr->first;//n1 + n2 = k
            if(nCount.find(n2)==nCount.end())
                continue;//if pair doesn't exist then look for next number
            if(nCount[n1]>0 && nCount[n2]>0)
            {
                int n;
                /*
                For testcase [3,1,3,4,3]
							k = 6
							3 and 3 makes up 6 and count of 3 is 3 so it will increase answer by half of its count i.e., 3/2 = 1
                */
                if(n1==n2)
                {
                    ans = ans + nCount[n1]/2;
                    nCount[n1]=0;
                }
                else
                {
                    n = min(nCount[n1],nCount[n2]);//to increase count in ans, bottleneck will be that number which has lesser count
                    ans = ans+n;
                    nCount[n1] -= n;//reduce count of both numbers
                    nCount[n2] -= n;
                }
            }
        }
        return ans;
    }
};

//Approach 2 -> Neat and short
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int result = 0;
        for(int elem: nums){
            int complement = k-elem;
            if(freq[complement]>0){
                result++;
                freq[complement]--;
            }
            else
                freq[elem]++;
        }
        
        return result;
    }
};
