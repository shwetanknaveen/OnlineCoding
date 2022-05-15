//Problem link - https://www.interviewbit.com/problems/minimum-lights-to-activate/

int getCount(vector<bool> &on,vector<int> &A,int &B,int ind)
{
    int siz = A.size();
    for(int i=max(ind-B+1,0);i<=min(ind+B-1,siz-1);i++)//if there is any bulb which is already switced on and which can lighten up this point
    {													//then no additional bulb is needed
        if(on[i]) return 0;
    }
    
    //Minimum bulbs will be switced on if they are distributed as far as possible. We lighten up a bulb as far as possible on the right
    //end of the current point since we are looking for indices in left to right fashion in calling function solve().
    //We would have lighten a bulb as left as possible if we have been looking indices in right to left fashion in calling function solve()
    for(int i=min(ind+B-1,siz-1);i>=max(ind-B+1,0);i--)//if no bulb is already on which can lighten up this point then we search for a bulb
    {												//which is in right condition (A[i]=1) and which can be switched on so that it can lighten
        if(A[i])									//up this point
        {
            on[i] = true;//switch on that bulb
            return 1;//count is increased by 1
        }
    }
    return -1;//no bulb is already on and there is no bulb which can be switced on and which can lighten up this point
}
int Solution::solve(vector<int> &A, int B) {
    int ans = 0;
    vector<bool> on(A.size(),false);
    for(int i=0;i<A.size();i++)
    {
        int val = getCount(on,A,B,i);
        if(val==-1) return -1;//no possible solution to lighten up this point
        ans += val; 

    }
    return ans;
}

