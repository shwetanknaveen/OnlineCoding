//Problem link - https://leetcode.com/problems/majority-element-ii/
//Video link - https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18
////Boyer-Moore voting algorithm

//We know that there can be at max 2 numbers among n numbers which have occurence greater than n/3
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int count1=0,count2=0,num1,num2;
        for(int i: nums)
        {
            //keep these increment part if(s) above than other if clauses
            if(i==num1) count1++;
            else if(i==num2) count2++;
            else if(count1==0) 
            {
                num1=i;
                count1=1;   
            }
            else if(count2==0)
            {
                num2=i;
                count2=1;
            }
            
            else 
            {
                count1--;
                count2--;
            }
        }
        count1=count2=0;
        for(int i: nums)//now storing the actual frequency of numbers which survived the voting
        {
            if(i==num1) count1++;
            else if(i==num2) count2++;
        }
        //if there frequency is greater than the required frequency then add them to ans
        if(count1> n/3) ans.push_back(num1);
        if(count2> n/3) ans.push_back(num2);
        return ans;
        }
};
