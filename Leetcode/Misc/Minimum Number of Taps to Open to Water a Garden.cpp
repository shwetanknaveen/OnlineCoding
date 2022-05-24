//Problem link - https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
//Function in "Leetcode/Array/MinJumps" is used here -> That problem link - https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        int jumps,halt,maxi;
        maxi = jumps = halt = 0;
        
        if(n==1) return 0;//if size of array itself is 1 then no jump is needed
        if(arr[0] == 0) return -1;//end state is not reachable as first value is 0 and size of array is not 1
        for(int i=0;i<n-1 && i<=halt;i++)//iterate to the second last element and we can't explore those options where we can't halt
        {
            maxi = max(maxi,i+arr[i]);//update the max reach
            if(maxi>=n-1)
            {
                ++jumps;
                return jumps;//if max reach is greater than array's last element then end is reachable with this jump
            }
            if(i==halt)
            {
                halt = maxi;//we have explored all max reach options upto halt so update new halt with max reach
                jumps++;//case of first element as destination is dealt with                //if(n==1) return 0; So that won't happen here
            }
        }
        if(halt>=n-1)
        return jumps;//if finally halted at the end or beyond end then return no. of
                    //of jumps taken
        
        return -1;//otherwise in default case return -1
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<int> mp(n+1,0);
        for( int i=0; i<=n ; i++ )
        {
            int start = max( 0, i - ranges[i] );//This tap will start from i-ranges[i] (0 if it is negative) index
            int len = i-start+ranges[i];//this will be length of jump from start which this tap offeres.(i-start) on tap's left and 
            							//ranges[i] on tap's right hence total length of jump offered by this tap is (i-start+ranges[i])
            mp[start] = max( len, mp[i]);//A tap which offers greatest length of jump should store its value of length which it offers
        }
        return jump(mp);
    }
};
