//Problem link - https://leetcode.com/problems/video-stitching/

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
    //Each clip offers jump starting from index v[0] of length (v[1]-v[0]).Index of inp is value is time. Now we wish to cover the whole
    //timeline in minimum number of clips i.e., we wish to reach at the end in minimum number of jumps
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> inp(time+1,0);
        for(auto v:clips)
        {
            if(v[0]>time) continue;//if starting point of this clip is greater than time itself then this clip is of no use 
            inp[v[0]] = max(inp[v[0]],v[1]-v[0]);//the clip which offers jump of largest length should store its value here
        }
        return jump(inp);
    }
};
