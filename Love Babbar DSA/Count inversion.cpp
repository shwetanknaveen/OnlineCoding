//Problem link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
//Video link - https://www.youtube.com/watch?v=kQ1mJlwW-c0

//duplicate pairs are also counted here which is allowed
class Solution{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], int l, int m, int r,long long int &count)
    {
        int n1 = m-l+1;	//sub-array 1 will contain elements upto m
        int n2 = r-m;	//sub-array 2 will contain elements from m+1
        long long arrL[n1+1],arrR[n2+1];
        
        int i,j;
        for(i=0;i<n1;i++)
        arrL[i] = arr[l+i];	//notice the indexes
        
        for(i=0;i<n2;i++)
        arrR[i] = arr[m+i+1];	//since sub-array 2 will contain elements from m+1
        
        arrL[n1] = arrR[n2] = LLONG_MAX;	//store infinity at the end of sub-arrays
        
        i=j=0;
        //At each stage, left and right arrays are sorted in themselves
        for(int k=l;k<=r;k++)
        {
            if(arrL[i]<=arrR[j])
            {
                arr[k] = arrL[i];
                i++;
            }
            else
            {//element in right array is smaller
                arr[k] = arrR[j];
                j++;
                count += n1-i;//remaining element in the left array upto its end including current element
                			//which all will form inverted count
            }
        }
         // Your code here
    }
    public:
    void mergeSort(long long arr[], int l, int r,long long int &count)
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
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int count = 0;
        mergeSort(arr,0,N-1,count);
        return count;
    }

};
