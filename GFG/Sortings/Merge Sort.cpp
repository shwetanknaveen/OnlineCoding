//Problem link - https://practice.geeksforgeeks.org/problems/merge-sort/1
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m-l+1;	//sub-array 1 will contain elements upto m
        int n2 = r-m;	//sub-array 2 will contain elements from m+1
        int arrL[n1+1],arrR[n2+1];
        
        int i,j;
        for(i=0;i<n1;i++)
        arrL[i] = arr[l+i];	//notice the indexes
        
        for(i=0;i<n2;i++)
        arrR[i] = arr[m+i+1];	//since sub-array 2 will contain elements from m+1
        
        arrL[n1] = arrR[n2] = INT_MAX;	//store infinity at the end of sub-arrays
        
        i=j=0;
        for(int k=l;k<=r;k++)
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
         // Your code here
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r)
        {
            int m = (l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
};

