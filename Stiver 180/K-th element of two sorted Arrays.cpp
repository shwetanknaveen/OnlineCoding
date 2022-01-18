//Problem link - https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
//Video link - https://www.youtube.com/watch?v=nv7F4PiLUzo&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=67

//Time complexity -> O(min(m,n))	Space complexity -> O(1)
/*
This problem is same as previous problem "Median of Two Sorted Arrays" with some minor modifications.
Only intialization of low,high and cut2 is different
There we imagined the merged arrays into two partitions with equal halves(1 more on left if odd numbers) here we have to 
imagine it being partitioned in two halves and left half having k numbers.
Now these k numbers will be made up by cut1 numbers from array1 and cut2 numbers from array2.
*/

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n) return kthElement(arr2,arr1,m,n,k);
        
        int low = max(0,k-m),//If arr2's size can't make up k numbers then we must choose atleast k-m numbers from arr1.
							// But if arr2 has more than or equal to k numbers then we are not forced to choose numbers from
							//arr1 and we can choose 0 numbers also
		high = min(k,n),//if we require only k numbers then we can choose at max k numbers from arr1 but if there are less 
						//numbers in arr1 than k i.e., n<k then we can choose all numbers from arr1
		cut1,cut2,left1,left2,right1,right2;
        
        while(low<=high)
        {
            cut1 = low + (high-low)/2;
            
            cut2 = k-cut1;
            
            left1 = cut1==0 ? INT_MIN : arr1[cut1-1];
            left2 = cut2==0 ? INT_MIN : arr2[cut2-1];
            
            right1 = cut1==n ? INT_MAX : arr1[cut1];
            right2 = cut2==m ? INT_MAX : arr2[cut2];
            
            if(left1<=right2 && left2<=right1)
            {
                    return max(left1,left2);//partitioned happened in right way and we have to return the last element
                    						//of left half as kth element as left half as k numbers
            }
            else if(left1>right2)
            {
                high = cut1-1;
            }
            else
            {
                low = cut1+1;
            }
        }
        return 0;//default case to return anything on all execution paths
    }
};
