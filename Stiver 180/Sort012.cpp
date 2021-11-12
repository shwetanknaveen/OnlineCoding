//Question link - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here 
        int zeroes,ones,twos;
        zeroes = ones = twos = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] == 0)
                zeroes++;
            if(a[i] == 1)
                ones++;
            if(a[i] == 2)
                twos++;
        }
        int ind = 0;
        while(zeroes--)
        {
            a[ind] = 0;
            ind++;
        }
        while(ones--)
        {
            a[ind] = 1;
            ind++;
        }
        while(twos--)
        {
            a[ind] = 2;
            ind++;
        }
    }
    
};
/*
These are the folowing steps:

Maintain 3 variables low, high and mid
low - all elements before low are 0
mid - all elements between low and mid are 1
high - all elements after high are 2
Initially low, mid are set at 0 and high is at n-1
Now, we iterate mid from 0 to high, and for every element
if it is equal to 0, we swap it with element at low, and increement low and mid
else if it is equal to 2, we swap it with element at high, and decreement high
else we just increement mid (i.e element is equla to 1)
This method ensures partition, as low and high maintain elements according to their values,
and then change their positions, ensuring all elements before low are lower than low_value and all elements after high
are higher than high_value

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int a[], int n)
{
    int low = 0, high = n-1, mid = 0;

    while(mid <= high){

        if(a[mid]==0)
            swap(&a[mid++], &a[low++]);
       
        else if(a[mid]==1)
            mid++;

        else
            swap(&a[mid], &a[high--]);
    }
}

*/

