//Problem link - https://www.interviewbit.com/problems/matrix-median/
//Video link - https://www.youtube.com/watch?v=63fPPOdIr2c&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=63

/*
Time complexity - O(log2(10^9) x N x log(M)) 		=	 O(N x log(M))
				BS in [1-1e9]	BS for each row
								having M columns
								and there are N
								rows
*/

//Here it is given that there are odd number of numbers in the matrix hence there will always be only one median which 
//is a definite number and not the average of two middle numbers
int countNumsLessThanEqualToN(vector<vector<int>> &A,int n)//returns count of those numbers which are <= n
{
    int count = 0;
    for(vector<int> row:A)//take count in each row
    {
        int low=0,high=row.size()-1,mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            if(row[mid]<=n)//When we assign low in this fashion that {<= (what we are looking for)} and don't break once we 
        				//find and leave the breaking condition on (low<=high) then when loop breaks, low points to what we 
        				//are looking for
                low = mid+1;
            else 
                high = mid-1;
        }
        //at the end low will be pointing to a number just greater than n
        count += low;
    }
    return count;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1,high = 1e9;//initial search space is [1,1e9]
    int m=A.size(),n=A[0].size(),half=(m*n)/2,count,mid;
    while(low<=high)
    {
        count = 0;
        mid = low + (high-low)/2;
        count = countNumsLessThanEqualToN(A,mid);
        if(count<=half)	//When we assign low in this fashion that {<= (what we are looking for)} and don't break once we find
        				//and leave the breaking condition on (low<=high) then when loop breaks, low points to what we are
        				//looking for USUALLY
            low = mid+1;
        else
            high = mid-1;
    }
    return low;//in the end low is a number including which there are just >half numbers on its left hence
    			//when we don't count that number then there are exactly half numbers on its left hence low is the median
}

