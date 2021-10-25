//Problem link - https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1#
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos,neg;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    int n1=pos.size();
	    int n2=neg.size();
	    int i=0,j=0;
	    int posTurn = true;
	    for(int k=0;k<n;k++)
	    {
	        if(posTurn)
	        {
	            if(i<n1)//there are positive numbers to fill
	            {
	                arr[k] = pos[i++];
	                posTurn = !posTurn;//next time negative numbers has to be stored
	            }
	            else//no more positive numbers to fill
	            {
	                while(j<n2)//keep on filling the remaining slots with negative numbers
	                {
	                    arr[k++] = neg[j++];//here k has to increased as while loop is executing and for loop is not increasing k
	                }
	            }
	        }
	        else
	        {
	            if(j<n2)//there are negative numbers to fill
	            {
	                arr[k] = neg[j++];
	                posTurn = !posTurn;//next time positive number has to be filled
	            }
	            else//no more negative numbers to fill
	            {
	                while(i<n1)//keep on filling the remaining slots with positive numbers
	                {
	                    arr[k++] = pos[i++];//here k has to increased as while loop is executing and for loop is not increasing k
	                }
	            }
	        }
	    }
	    
	}
};

/*Following approach in O(1) space and O(N^2) time complexity using right rotation
class Solution{
public:

    void negativeAtEvenIndex(int arr[],int n,int i)
    {
        int temp;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>=0)
            {
                temp = arr[j];
                while(j>i)
                {
                    arr[j] = arr[j-1];
                    j--;
                }
                arr[j] = temp;
                return;
            }
        }
    }
    void positiveAtOddIndex(int arr[],int n,int i)
    {
        int temp;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<0)
            {
                temp = arr[j];
                while(j>i)
                {
                    arr[j] = arr[j-1];
                    j--;
                }
                arr[j] = temp;
                return;
            }
        }
    }
	void rearrange(int arr[], int n) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        if((i&1) && arr[i]>=0)//positive number at odd index
	        positiveAtOddIndex(arr,n,i);
	        else if(!(i&1) && arr[i]<0)//negative number at even index
	        negativeAtEvenIndex(arr,n,i);
	    }
	}
};
*/
