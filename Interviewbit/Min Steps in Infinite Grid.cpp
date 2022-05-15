//Problem link - https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
//Video link - https://www.youtube.com/watch?v=yxIfPXReuoo&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=5

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int ans = 0;
    for(int i=1;i<A.size();i++)
    {
        int delX = abs(A[i]-A[i-1]);
        int delY = abs(B[i]-B[i-1]);
        ans += max(delX,delY);
    }
    return ans;
}

