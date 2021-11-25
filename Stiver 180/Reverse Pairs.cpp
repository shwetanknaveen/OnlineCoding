//Problem link - https://leetcode.com/problems/reverse-pairs/
//Video link - https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=20
//Time Complexity - O(nlog(n)+n) 	Space complexity - O(n)
//This problem is similar to inversion count but little different than it
class Solution {
public:
    void merge(vector<int> &arr, int l, int m, int r,int &count)
    {
    	 /*We know that at each step left array and right array are sorted in themselves.Left array is left half of
		 arr and right one is right half*/
         int j = m + 1; //second array starts from m+1 index
         for(int i = l;i<=m;i++) {
            while(j<=r && arr[i] > 2LL * arr[j]) {//2LL so that multiplication don't result in overflow
            										//notice that j is NOT initialised each time because if it was less than
													//previous i values in left array then next i values in left array will
													//be greater than previous one hence no need to reinitialise j to m+1 
                j++;//read below why j is being incremented
            }
            //now j in second array(right half in same array) is at such index which is not less than with given condition
            //hence all numbers in right half before j must be less than arr[i] and no. of such numbers = (j - (m+1)) since
            //right half start at m+1
            
            count += (j - (m+1));//done for each i
        }//for loop ends here
        
        //now onwards simple merge logic of merge sort
        int n1 = m-l+1;
        int n2 = r-m;
        int arrL[n1],arrR[n2];
        
        int i;
        for(i=0;i<n1;i++)
        arrL[i] = arr[l+i];
        
        for(i=0;i<n2;i++)
        arrR[i] = arr[m+i+1];
        
        i=j=0;
        int k;
        for(k=l;k<=r && i<n1 && j<n2;k++)
        {
            if(arrL[i]<arrR[j])
            {
                arr[k] = arrL[i];
                i++;
            }
            else
            {
                arr[k] = arrR[j];
                j++;
            }
        }
        while(i<n1)//if arrR was exhausted then storing remaining elements of  arrL in merged array
        {
            arr[k++] = arrL[i++];
        }
        while(j<n2)////if arrL was exhausted then storing remaining elements of  arrR in merged array
        {
            arr[k++] = arrR[j++];
        }
         // Your code here
    }
    public:
    void mergeSort(vector<int> &arr, int l, int r,int &count)
    {
        //code here
        if(l<r)
        {
            int m = (l+r)/2;
            mergeSort(arr,l,m,count);
            mergeSort(arr,m+1,r,count);
            merge(arr,l,m,r,count);
        }
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int N = nums.size();
        mergeSort(nums,0,N-1,count);
        return count;
    }
};
