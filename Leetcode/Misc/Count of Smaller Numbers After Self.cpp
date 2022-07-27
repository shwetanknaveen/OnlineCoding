//Problem link - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
//See also - "Love Babbar DSA/Count inversion"
class Solution {
public:
    void merge(vector<pair<int,int>> &arr, int l, int m, int r,vector<int> &count)
    {
        int n1 = m-l+1;	//sub-array 1 will contain elements upto m
        int n2 = r-m;	//sub-array 2 will contain elements from m+1
        vector<pair<int,int>> arrL(n1+1),arrR(n2+1);
        
        int i,j;
        for(i=0;i<n1;i++)
        arrL[i] = arr[l+i];	//notice the indexes
        
        for(i=0;i<n2;i++)
        arrR[i] = arr[m+i+1];	//since sub-array 2 will contain elements from m+1
        
        arrL[n1].first = arrR[n2].first = INT_MAX;	//store infinity at the end of sub-arrays
        
        i=j=0;
        //At each stage, left and right arrays are sorted in themselves
        int countThis = 0;
        for(int k=l;k<=r;k++)
        {
            if(arrL[i].first<=arrR[j].first)
            {
                count[arrL[i].second] += countThis;//Seeing the ith element in arrL for the last time in this merge hence store the count of smaller number than it
                arr[k] = arrL[i];				//Obviously those numbers will also be counted for it which were smaller than numbers on left of ith number
                i++;							//in arrL because number at i in arrL is larger than numbers on its left as arrL and arrR is sorted
            }
            else
            {   //element in right array is smaller
                countThis++;
                arr[k] = arrR[j];
                j++;
            }
        }
    }
    public:
    void mergeSort(vector<pair<int,int>> &arr, int l, int r,vector<int> &count)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            mergeSort(arr,l,m,count);
            mergeSort(arr,m+1,r,count);
            merge(arr,l,m,r,count);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);
        vector<pair<int,int>> numInd;
        for(int i=0;i<n;i++)
            numInd.push_back({nums[i],i});
        mergeSort(numInd,0,n-1,count);
        return count;
    }
};
