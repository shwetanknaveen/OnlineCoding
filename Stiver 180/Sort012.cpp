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


//Same question at leetcode
//Problem link - https://leetcode.com/problems/sort-colors/
//Video link - https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

//We are keeping low to point after stream of 0s and high to point before stream of 2s
//mid is always at same or ahead with low hence it has seen whatever low will see or low has seen hence when we are swapping mid with low
//we increase both of them(we know that after swap, either 1 will come to mid's place or it will swap it with itself but in any case
//2 can't come at mid's place after swapping with mid and low) but when we are swapping mid with high we don't know that what's coming after 
//swap at mid's place hence we don't increase the mid after swap 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        
        while(mid<=high)
        {
            if(nums[mid]==0)//send this 0 to low and look forward
                swap(nums[mid++],nums[low++]);
            else if(nums[mid]==1)//just look next towards right
                mid++;
            else//send this 2 to high
                swap(nums[mid],nums[high--]);//no increment of mid
            								//exchanged value is coming from right side which may be greater hence mid should not
            								//be increased and value at mid index should be checked again
        }
    }
};
