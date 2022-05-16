//Problem link - https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    bool allNeg = true;
    int thisSum = 0,leastNeg = INT_MIN,ans = 0;
    for(int i:A)
    {
        if(i>=0)
            allNeg = false;
        else leastNeg = max(leastNeg,i);//i is negative

        if(thisSum + i < 0)
        {
            thisSum = 0;
        }
        else
        {
            thisSum += i;
            ans = max(ans,thisSum);
        }
    }
    if(allNeg) return leastNeg;
    return max(thisSum,ans);
}

