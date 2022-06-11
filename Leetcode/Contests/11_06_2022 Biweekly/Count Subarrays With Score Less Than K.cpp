//Problem link - https://leetcode.com/problems/count-subarrays-with-score-less-than-k/

/*
We use a sliding window technique, tracking the sum of the subarray in the window.

The score of the subarray in the window is sum * (i - j + 1). We move the left side of the window, decreasing sum, if that score is equal or 
greater than k.

Note that element i forms i - j + 1 valid subarrays. This is because subarrays [j + 1, i], [j + 2, i] ... [i, i] are valid if subarray [j, i] 
is valid

It adds all the subarrays that ends at i starting at j both inclusive that are valid.
eg [1,2,3,4,5,6,7,8,9,10]
let j = 0, i = 9;
total subarrays ending at i starting at j is 10

[1,2,3,4,5,6,7,8,9,10]
[2,3,4,5,6,7,8,9,10]
[3,4,5,6,7,8,9,10]
[4,5,6,7,8,9,10]
[5,6,7,8,9,10]
[6,7,8,9,10]
[7,8,9,10]
[8,9,10]
[9,10]
[10]

We are not taking [1,2] and others as subset because it would have already been included when i=0 and j=1 was window size
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    long long sum = 0, res = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {//window is expanding on right with i and left boundary of window is j
        sum += nums[i];
        while (sum * (i - j + 1) >= k)
            sum -= nums[j++];
        res += i - j + 1;
    }
    return res;
}
};
