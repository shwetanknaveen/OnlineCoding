//Problem link - https://practice.geeksforgeeks.org/problems/merge-sort/1#
class Solution{
	{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int arrL[n1],arrR[n2];
        
        int i,j;
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
