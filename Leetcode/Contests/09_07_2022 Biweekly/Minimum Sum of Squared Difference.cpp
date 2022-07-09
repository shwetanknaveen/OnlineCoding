//Problem link - https://leetcode.com/problems/minimum-sum-of-squared-difference/

/*
Difference will only be minimised if we reduce the maximum difference to lower value and we can reduce the maximum differece by 1 by consuming one value from either k1 or k2. Here sign doesn't matters or it doesn't matter because diff's square will be added in ans
*/
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        map<int,int> diffTimes;
        for(int i=0;i<n;i++)
            diffTimes[abs(nums1[i]-nums2[i])]++;
        int k = k1+k2;
        long long ans = 0;
        for(auto itr = diffTimes.rbegin();itr != diffTimes.rend(); itr++)
        {
            if(k>0 && itr->first>0)//difference should be greater than 0 then only it would be beneficial to decrease it so as to minimise
            {
                int canBeReducedByOne = min(k,itr->second);//let's say there are 4 differences having 5 value i.e.,
                                                            //diffTimes[5] = 4 and we have k=3 therefore we can reduce
                                                            //three 5s to 4 or if k was 5 then we could reduce all 5s to 4
                k -= canBeReducedByOne;//these many k have been used
                itr->second = itr->second - canBeReducedByOne;
                diffTimes[itr->first-1] += canBeReducedByOne;//this value is reduced to one less value hence update that value
            }
            ans += long(itr->second) * long(itr->first) * long(itr->first);//After update add the square of this difference and multiply it with number of times it occurs i.e., if diffTimes[5] = 4, 4 x 5^(2) will be added in ans
        }
        return ans;
    }
};
