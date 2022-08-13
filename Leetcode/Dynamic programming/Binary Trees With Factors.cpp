//Problem link - https://leetcode.com/problems/binary-trees-with-factors/

class Solution {
public:
    int mod = 1e9+7;
    long solve(int num,set<int> &allNums,unordered_map<int,long> &numAsBaseTreeCount)
    {
    	//numAsBaseTreeCount[num] ->Number of binary trees keeping num as the root node
        if(numAsBaseTreeCount.find(num) != numAsBaseTreeCount.end()) return numAsBaseTreeCount[num];
        
        long ans = 1;
        for(auto fact:allNums)//let's see that what other child nodes we can put if num is taken as root node
        {
            if(fact>num) break;//child nodes should be factor of num hence they can't be bigger than num itself
            if(num%fact==0 && allNums.find(num/fact) != allNums.end())//if fact is factor of num then let's say fact x j = num => j should also be existing in the array
                ans = ans%mod + (solve(fact,allNums,numAsBaseTreeCount)%mod)*(solve(num/fact,allNums,numAsBaseTreeCount)%mod);
        }
        return numAsBaseTreeCount[num] = ans%mod;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        set<int> allNums;
        for(int num:arr)
            allNums.insert(num);
        unordered_map<int,long> numAsBaseTreeCount;
        int ans = 0;
        for(auto i:arr)//fix all the numbers in base one by one
            ans =(ans + solve(i,allNums,numAsBaseTreeCount))%mod;
        return ans;
    }
};


//We can remove the usage of set and utilise our dp map for the same purpose
class Solution {
public:
    int mod = 1e9+7;
    long solve(int num,map<int,long> &numAsBaseTreeCount)
    {
        if(numAsBaseTreeCount[num] != 0) return numAsBaseTreeCount[num];
        
        long ans = 1;
        for(auto p:numAsBaseTreeCount)
        {
            int fact = p.first;
            if(fact>num) break;
            if(num%fact==0 && numAsBaseTreeCount.find(num/fact) != numAsBaseTreeCount.end())
                ans = ans%mod + (solve(fact,numAsBaseTreeCount)%mod)*(solve(num/fact,numAsBaseTreeCount)%mod);
        }
        return numAsBaseTreeCount[num] = ans%mod;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        map<int,long> numAsBaseTreeCount;
        for(int num:arr)
            numAsBaseTreeCount[num] = 0;
        
        int ans = 0;
        for(auto i:arr)
            ans =(ans + solve(i,numAsBaseTreeCount))%mod;
        return ans;
    }
};
