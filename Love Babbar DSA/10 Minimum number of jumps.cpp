//Problem link - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
//See this problem also on leetcode - https://leetcode.com/problems/jump-game/submissions/
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        int jumps,halt,maxi;
        maxi = jumps = halt = 0;
        if(n==1) return 0;//if size of array itself is 1 then no jump is needed
        if(arr[0] == 0) return -1;//end state is not reachable as first value is 0 and size of array is not 1
        
        for(int i=0;i<n-1 && i<=halt;i++)//iterate to the second last element and we can't iterate over those elements where we can't halt
        {
            maxi = max(maxi,i+arr[i]);//update the maximum reach
            if(maxi>=n-1)
            {
                ++jumps;
                return jumps;//if max reach is greater than array's last element then end is reachable with this jump
            }
            if(i==halt)
            {
                halt = maxi;//we have explored all max reach options upto halt so update new halt with max reach
                jumps++;//case of first element as destination is dealt with if(n==1) return 0;
                        //So that won't happen here
            }
        }
        if(halt>=n-1)
        return jumps;//if finally halted at the end or beyond end then return no. of
                    //of jumps taken
        
        return -1;//otherwise in default case return -1
    }
};
