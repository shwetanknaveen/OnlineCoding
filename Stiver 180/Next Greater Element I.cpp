//Problem link - https://leetcode.com/problems/next-greater-element-i/
//Video link - https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76

//Method 1- Brute force method
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
            mp[nums2[i]] = i;
        
        bool flag;
        for(int i:nums1)
        {
            flag=true;
            for(int j=mp[i]+1;j<n;j++)
            {
                if(nums2[j]>i)
                {
                    ans.push_back(nums2[j]);
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(-1);
        }
        return ans;
    }
};

//Method 2

//Time Complexity -> If nums1.size() = n1 and nums2.size() = n2 then T(n) = O(n1 + n2)
//Each number will be pushed at max once onto the stack
//It is given that all the numbers in nums1 and nums2 are unique
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stc;
        map<int,int> mp;
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--)//we go from right to left in nums2 and save next greater element of each number
        								//in map
        {
            while(!stc.empty() && stc.top()<nums2[i])//if stack is not empty and numbers on it are less than this number then
            										//keep popping as it means we didn't saw number greater than this number
            										//ahead of this. They can't be answer to other numbers also as this number
            										//is already greater than them and nearest next
                stc.pop();
            if(stc.empty())//it means there is no next greater element for this number
            {
                mp[nums2[i]] = -1;//-1 will be its NGE as given in question
                stc.push(nums2[i]);//as we saw this greater number then push it onto the stack
            }
            else//top of stack is larger than this number
            {
                mp[nums2[i]] = stc.top();
                stc.push(nums2[i]);//this number can be next greater for other numbers which are on its left
            }
        }
        for(int i: nums1)
            ans.push_back(mp[i]);//store the NGE for each number in nums1 by finding it from the map
        return ans;
    }
};
