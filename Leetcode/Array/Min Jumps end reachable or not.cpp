//Problem link - https://leetcode.com/problems/jump-game/
//See this problem also - https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    bool canJump(vector<int>& A) {
    int n=A.size();
    int maxi,halt;
        maxi = halt = 0;
        if(n==1) return true;//if array has only one element then it's obviously always reachable
        if(A[0]==0) return false;//if array has not only one element and first element in 0 then we can't reach its end
        for(int i=0;i<(n-1) && i<=halt;i++)//iterate to the end and we can't explore those options where we can't halt
        {
            maxi = max(maxi,i+A[i]);//update the maximum reach
            
            if(maxi >= (n-1))
                return true;//if max reach is greater than array's last element then end is reachable
            if(halt==i)
            {
                halt=maxi;//we have explored all max reach options upto halt so update new halt with max reach
            }
        }
        if(halt>=n-1)//after exploring all options if halt is greater than equal to end of array then obviously end is reachable
            return true;
        return false;//in default case return false
    }
};
