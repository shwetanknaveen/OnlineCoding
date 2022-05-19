//Problem link - https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

//Approach 1
int Solution::solve(vector<int> &A) {
    int maxi=INT_MIN,mini = INT_MAX;
    for(int i:A)
    {
        maxi = max(maxi,i);
        mini = min(mini,i);
    }
    return maxi+mini;
}




//Approach 2 - > Divide and conquer
pair<int,int> findMinMax(vector<int> &A, int start, int end){
    if(start == end)
        return make_pair(A[start], A[start]);//the only number pointed by both start and end is both min and max

    int mid = (end-start)/2 + start;
    //Find Min and Max pair for left sub-array
    pair<int,int> mm1 = findMinMax(A,start,mid);
    //Find Min and Max pair for right sub-array
    pair<int,int> mm2 = findMinMax(A,mid+1,end);

    //Compare the value to get the max and min for the entire array.
    int minNum = mm1.first < mm2.first ? mm1.first : mm2.first;
    int maxNum = mm1.second > mm2.second ? mm1.second : mm2.second;

    //Return max and min values as a pair.
    return make_pair(minNum,maxNum);
}

int Solution::solve(vector<int> &A) {
    pair<int,int> minMax = findMinMax(A,0,A.size()-1);
    return minMax.first + minMax.second;
}



