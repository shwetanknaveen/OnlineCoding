//Problem link - https://leetcode.com/problems/4sum/ 
//Video link - https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22
//Time complexity -> O(n^3) Space complexity -> O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target2 = target - (nums[i] + nums[j]);
                
                int front = j+1, back = n-1;
                while(front<back)
                {
                    int thirdFourtSum = nums[front] + nums[back];
                    if(thirdFourtSum<target2)
                        front++;
                    else if(thirdFourtSum>target2)
                    {
                        back--;
                    }
                    else{//found the target2
                        vector<int> quadraplet(4,0);
                        quadraplet[0] = nums[i];
                        quadraplet[1] = nums[j];
                        quadraplet[2] = nums[front];
                        quadraplet[3] = nums[back];
                        ans.push_back(quadraplet);
                        
                        while(front<back && nums[front] == quadraplet[2])
                            front++;//avoiding duplicates for third number
                        while(front<back && nums[back] == quadraplet[3])
                            back--;//avoiding duplicates for fourth number
                    }
                }
                while(j+1<n && nums[j] == nums[j+1]) j++;//avoiding duplicates for second number
            }
            while(i+1<n && nums[i] == nums[i+1]) i++;//avoiding duplicates for first number      
        }
        return ans;
    }
};
