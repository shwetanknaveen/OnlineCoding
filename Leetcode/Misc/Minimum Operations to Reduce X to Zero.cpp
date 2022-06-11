//Problem link - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
//See problem "Interviewbit/Pick from both sides!"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int ans = INT_MAX,currSum = 0,count = 0,n = nums.size(),i;
        for(i=0;i<n;i++)//from left side
        {
            if(currSum+nums[i]<x)
            {
                currSum += nums[i];
                count++;
            }
            else if(currSum+nums[i]==x)
            {
                currSum += nums[i];
                count++;
                ans = count;//Sum has reached x so we see by exploring right side that whether we can reach the same sum with less numbers
                break;
            }
            else 
            {
                i--;//i must point to the number which was picked in the last
                break;
            }
        }
        //Now i value in last point to a number which was picked
        for(int j=n-1;j>=0 && j>i;j--)//j>i because we can't pick the same number twice
        {
            if(currSum + nums[j] == x)
            {
                currSum += nums[j];
                count++;
                ans = min(ans,count);
            }
            else if(currSum + nums[j] < x)
            {
                currSum += nums[j];
                count++;
            }
            else
            {
                if(i==-1) break;//if we can't remove any number from the left window then there is no way to proceed further
                else
                {
                    currSum -= nums[i--];
                    count--;
                    j++;//We have to judge the same number nums[j] again after removing one number from the left window hence to counter 
                    	//counter the effect of j-- in for() loop, we do this here so that j remains same for next execution
                }
            }
        }
        
        return ans==INT_MAX?-1:ans;
    }
};
