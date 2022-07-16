//Problem link - https://leetcode.com/problems/intersection-of-two-arrays-ii/

/*
What if elements of nums2 are stored on disk, and the memory is
limited such that you cannot load all elements into the memory at
once?

If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the 
intersections.

If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each 
array at a time in memory, record intersections.
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size(), n2= nums2.size();
        for(int i=0,j=0;i<n1 && j<n2;)
        {
            if(nums1[i]==nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else j++;
        }
        return ans;
    }
};
