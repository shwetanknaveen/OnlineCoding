//Question link - https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
class Solution{
public:
    
    int search(int A[], int l, int r, int target)
    {
        // Complete this function
        if (target < A[l] && target > A[r]) return -1;
    
    while (l < r) 
    {
        int mid = l+(r-l)/2;
        if (A[mid] <= A[r]) //means array from mid to r is sorted
        {
            if (target >A[mid] && target <= A[r]) 
            {
                l = mid+1;//if target lies in this sorted right part then  simply do binary search for that part
            } 
            else 
            {
                r = mid;//if target doesn't lies in the right part  then by changing r to mid, we will now look to left subpart
            }
            
        } 
        else//means arry from l to mid is sorted
        {
            if (target <= A[mid] && target >= A[l]) 
            {
                    r = mid;//if target lies in this sorted right part then  simply do binary search for that part
            } 
            else 
            {
                l = mid+1;//if target doesn't lies in the right part  then by changing l to mid+1, we will now look to left subpart
            }
        }
    }
    if (A[l] == target) return l;//here l=r as then only above loop will terminate
    else return -1;
    }
}; 
