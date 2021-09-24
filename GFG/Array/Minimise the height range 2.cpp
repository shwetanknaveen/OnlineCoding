//Problem link - https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        sort(arr,arr+n);
        n=n-1;//now n is the last index
        int result = arr[n]-arr[0];
        int maxiInNewArray,miniInNewArray;
        for(int i=1;i<=n;i++){//i will go from first to last element
                            //Obviously we won't increase the last that is maximum element
            if(arr[i]-k>=0)
            {
            maxiInNewArray = max(arr[i-1]+k,arr[n]-k);//last element has to be decreased anyhow in order to take it closer to min and minimise the difference(max-min)
                                                    //in the new array. Maximum in new array can be either last number-k 
                                                    //or other numbers+k
            miniInNewArray = min(arr[i]-k,arr[0]+k);//first element has to be increased anyhow in order to take it closer to the max and minimise the difference (max-min)
                                                    //in the new array.Minimum in new array can be either first number+k o
                                                    //other numbers-k
            result = min(result,abs(maxiInNewArray-miniInNewArray));
            }
            
        }
        return result;
    }
};
