//Problem link - https://www.interviewbit.com/problems/maximum-sum-triplet/

//Approach 1 -> Brute Force -> Gives TLE ->O(n^3)

int Solution::solve(vector<int> &A) {
    int n = A.size(),ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(A[i]<A[j] && A[j]<A[k])
                    ans = max(ans,A[i]+A[j]+A[k]);
            }
        }
    }
    return ans;
}

//Approach 2 -> Optimized Brute Force -> Still gives TLE -> O(n^2)
int Solution::solve(vector<int> &A) {
    int n = A.size(),ans = 0;
    for(int i=1;i<n-1;i++)
    {
        int fir,thir;
        fir = thir = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[j]<A[i])
            {
                fir = max(fir,A[j]);
            }
        }
        for(int k=i+1;k<n;k++)
        {
            if(A[k]>A[i])
            {
                thir = max(thir,A[k]);
            }
        }
        if(fir!=0 && thir!=0)
        ans = max(ans,fir+A[i]+thir);
    }
    return ans;
}

//Approach 3 -> https://www.geeksforgeeks.org/find-maximum-sum-triplets-array-j-k-ai-aj-ak/
int getLowValue(set<int>& lowValue, int& n)
{
    auto it = lowValue.lower_bound(n);//THIS IS THE WAY TO CALL LOWER_BOUND() W.R.T TO A SET
    								//When calling for vector, it is called as lower_bound(vect.begin(),vect.end(),val) and returns the 
    								//required iterator
 
    // Since 'lower_bound' returns the first
    // iterator greater than 'n', thus we
    // have to decrement the pointer for
    // getting the minimum value
    --it;
 
    return (*it);
}
int Solution::solve(vector<int> &arr) {
    int n = arr.size();
    int maxSuffArr[n + 1];
 
    // Set the last element
    maxSuffArr[n] = 0;
 
    // Calculate suffix-array containing maximum
    // value for index i, i+1, i+2, ... n-1 in
    // arr[i]
    for (int i = n - 1; i >= 0; --i)
        maxSuffArr[i] = max(maxSuffArr[i + 1], arr[i]);
 
    int ans = 0;
 
    // Initialize set container
    set<int> lowValue;
 
    // Insert minimum value for first comparison
    // in the set
    lowValue.insert(INT_MIN);
 
    for (int i = 0; i < n - 1; ++i) {
        if (maxSuffArr[i + 1] > arr[i]) {
            ans = max(ans, getLowValue(lowValue,
                                       arr[i])
                               + arr[i] + maxSuffArr[i + 1]);
 
            // Insert arr[i] in set<> for further
            // processing
            lowValue.insert(arr[i]);
        }
    }
    return ans;
}


