//Problem link - https://www.interviewbit.com/problems/allocate-books/
//Video link - https://www.youtube.com/watch?v=gYmWHvRHu-s&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=70
//Time complexity O((no. of books)*log(sum of pages))

/*Here our search space will be minimum possible ans to maximum possible answer in which we will find minimum ans
Hence the given array need not be sorted*/

bool isValid(vector<int> &A,int &nStud,int &lim)//Can we allocate books to nStud students with limit = lim
{
    int nStudAllot = 0,thisStudBook=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>lim) return false;//if any book has more pages than this limit then there is no way that this book can be
        						//alloted to any student
        thisStudBook += A[i];//number of pages alloted to this student
        if(thisStudBook>lim)//if after alloting this book, number of pages to this student has exceeded the limit then
        					//allot this book to next student
        {
            thisStudBook = 0;//for next student, page count will now be 0
            nStudAllot++;//number of students who have been alloted books is now one more
            thisStudBook += A[i];//alloting this book to new student
        }
    }
    if(thisStudBook!=0) nStudAllot++;//for the last student, we wouldn't have entered the if block and wouldn't increased nStudAllot
    if(nStudAllot>nStud) return false;//if we were able to allot given books withing given limit but we required more no.
    								//of students than given then this won't be a valid allocation
    return true;//default case => Allotment possible with given limit
}
int Solution::books(vector<int> &A, int B) {
    int low = INT_MAX,high = 0,n=A.size(),mid,res;
    if(n<B) return -1;//if number of books are less than number of students then no way allocation is possible
    for(int i=0;i<n;i++)
    {
        low = min(low,A[i]);
        high += A[i];
    }
	//low ==> min(all values) ->Happens when there are more than one students and one student gets that book
	//high ==> sum(all values) ->Happens when there is only one student and he has to be alloted all the books

    while(low<=high)
    {
        mid = low + (high-low)/2;

        if(isValid(A,B,mid))//if allocation possible with limit = mid
        {
        	res = ans;//store this ans
            high = mid-1;//if with this limit, allocation is possible then for minimum ans, we can look on its left too
        }
        else 
        {
            low = mid +1;//if with that limit , allocation is not possible then we have to increase the limit
        }
    }
    return res;//return the stored ans
}

