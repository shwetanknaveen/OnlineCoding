//Problem link - https://leetcode.com/problems/two-sum/
//Video link - https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=3
//Time and space complexity -> O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numbers;//it will save numbers in nums and their index
        int siz = nums.size();
        vector<int> ans;
        for(int i = 0;i<siz;i++)
        {
            if(numbers.find(target-nums[i])!= numbers.end())//if its pair exist in the map which will add up with this
            												//number to give target then add this number's index and
            												//its pair's index in the answer vector
            {
                ans.push_back(i);
                ans.push_back(numbers[target-nums[i]]);
                break;
            }
            else
            {
                numbers.insert({nums[i],i});
            }
        }
        return ans;
    }
}; 
