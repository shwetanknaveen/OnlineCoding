//Problem link - https://leetcode.com/problems/3sum/
//Time complexity -> O(n^2) Space complexity -> O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> triplet(3,0);
        int n = nums.size();
        if(nums.empty()) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            int front = i+1,back = n-1;
            while(front<back)
            {
                int secondThirdSum = nums[front] + nums[back];
                if(secondThirdSum< (-nums[i]))
                {
                    front++;
                }
                else if(secondThirdSum> (-nums[i]))
                {
                    back--;
                }
                else//nums[i] + nums[front] + nums[back] = 0
                {
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    ans.push_back(triplet);
                    
                    while(front<back && nums[front] == triplet[1])//avoiding duplicates for second number
                        front++;
                    while(front<back && nums[back] == triplet[2])//avoiding duplicates for third number
                        back--;
                }
                
            }
            while(i+1<n && nums[i] == nums[i+1])//avoiding duplicates for first number
                i++;
        }
        return ans;
    }
};
