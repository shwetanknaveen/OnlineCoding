//Problem link - https://leetcode.com/problems/merge-sorted-array/

//Approach 1 -> Using linear space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(nums1[i]<nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m)//fill remaining elements of nums1
        {
            res.push_back(nums1[i]);
                i++;
        }
        while(j<n)//fill remaining elements of nums2
        {
            res.push_back(nums2[j]);
                j++;
        }
        nums1 = res;
    }
};

//Approach 2 -> Using O(1) space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j= n-1, k = m+n-1;//start from end of both the arrays
        while(j>=0)//fill all the elements of nums2 in nums1 at right position as nums1 is having extra space for nums2 elements
        {
            nums1[k--] = (i>=0 && nums1[i]>nums2[j]) ? nums1[i--] : nums2[j--];
            			/*if number in nums1 is larger
            			then fill that first otherwise
            			if nums1 is over or nums2 element
            			is larger then fill nums2 remaining
            			element or nums2 larger element first
            			correspondingly.
            			*/
        }
    }
};
