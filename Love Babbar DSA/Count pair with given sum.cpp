//Problem link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
//Video link - https://www.youtube.com/watch?v=Tqa9pilFrhY

//map[non existing key] returns 0(default value)

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int twice_count=0;
        unordered_map<int,int> frequency;
        for(int i=0;i<n;i++)
        frequency[arr[i]]++;
        
        for(int i=0;i<n;i++)
        {
            //if we need k=3 and we have 2,1,1 then (2,1),(2,1) are counted different
            //but it will count (1,2) and (1,2) again which is not a different pair than (2,1)
            //hence we are counting twice here
            
            twice_count += frequency[k-arr[i]];//k-arr[i] is the other number which can pair up with arr[i] to make sum = k
                                                //but how many such numbers are there--> it is its frequency.
            
            if(k-arr[i]==arr[i])//in this case, we have already used one arr[i] and the other number which
                                //is needed to pair up with arr[i] to give sum= k is arr[i] itself
                                //so we have used one arr[i] hence its frequncy is 1 less thus 
                                //we have to reduce the twice count by 1
            twice_count--;
        }
        return twice_count/2;
    }
};

