//Problem link - https://www.interviewbit.com/problems/maximum-absolute-difference/
//Self explanation video - https://www.youtube.com/watch?v=1M70LVD-R7M&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=6

int Solution::maxArr(vector<int> &A) 
{
    int n=A.size();
    int miniInPlus,maxiInPlus,miniInMinus,maxiInMinus;
    miniInMinus = miniInPlus = INT_MAX;
    maxiInMinus = maxiInPlus = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int plus = A[i]+i, minus = A[i]-i;
        miniInMinus = min(miniInMinus,minus);
        miniInPlus = min(miniInPlus,plus);
        maxiInMinus = max(maxiInMinus,minus);
        maxiInPlus = max(maxiInPlus,plus);
    }
    return max(abs(miniInMinus-maxiInMinus),abs(miniInPlus-maxiInPlus));
}

