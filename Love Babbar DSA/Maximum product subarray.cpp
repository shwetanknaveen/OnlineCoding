//Problem link - https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
//Video link - https://www.youtube.com/watch?v=hJ_Uy2DzE08

class Solution{
public:

    //here subarray has to be continuous

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans,max_pos,max_neg,temp;
	    ans = max_pos = max_neg = arr[0];
	    for(int i=1;i<n;i++)
	    {
	        temp = max_pos;	//next line will change max_pos value hence store it.
	        max_pos = max({(long long)arr[i],arr[i]*max_pos,arr[i]*max_neg});
	        //pass as list in max() or min() when there are more than 2 arguments
	        /*
			either max_pos will start from current element or max_pos will 
	        multiply itself with arr[i] if arr[i]>0 or it will get value of max_neg
	        *arr[i] if arr[i]<0. It will get maximum of all these possibilities.
	        */
	        
	        max_neg = min({(long long)arr[i],arr[i]*max_neg,arr[i]*temp});
	        /*
			either max_neg will start from current element or max_neg will 
	        multiply itself with arr[i] if arr[i]>0 or it will get value of max_pos
	        *arr[i] if arr[i]<0. It will get minimum of all these possibilities.
	        NOTE- Here we are using temp value of max_pos as max_pos has been changed
	        in the last line.
	        */
	        
	        ans = max(ans,max_pos);
	    }
	    return ans;
	}
};
