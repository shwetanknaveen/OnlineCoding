//Problem link - https://leetcode.com/problems/sell-diminishing-valued-colored-balls/
//Self video explanation - https://www.youtube.com/watch?v=-nTwVp05mAo&list=PLudlC33BR8eEiSWH654z2GKEF3Ckz6QWB&index=14&t=31s
//See similar question - "Leetcode/Contests/09_07_2022 Biweekly/Minimum Sum of Squared Difference"
class Solution {
public:
    long computeSum(long r,long m,long b)
    {
        long fullGroupSum,leftGroupSum;
        long fullGroupCount = (b/r),leftGroupMemCount = b%r;
        fullGroupSum = r*( (  fullGroupCount  * ( m + ( m - ( fullGroupCount - 1 ) ) ) )/2);          //n/2(firstTerm+lastTerm)
        leftGroupSum = leftGroupMemCount * (m-(fullGroupCount));
        return fullGroupSum+leftGroupSum;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        map<int,int> countColors;//<How many colors are there -> which have count this>
        for(int i:inventory)
            countColors[i]++;
        long ans = 0;
        int mod = 1e9+7;
        countColors[0] = 0;//Insert a dummy value
        for(auto itr=countColors.rbegin();itr!=countColors.rend() && orders>0;itr++)
        {
            auto secondMaxItr = itr;
            secondMaxItr++;
            int secondMax = secondMaxItr->first;
            long nextAvailableToBuy = long(itr->second)*long(itr->first-secondMax);
            long buy = min(long(orders),nextAvailableToBuy);//from how many places we can pick this top profit ball
            ans += computeSum(itr->second,itr->first,buy);//Profit for each ball picked is itr->first
            orders -= buy;//these many balls have been bought
            countColors[secondMax] += itr->second;//previous max towers got reduced to secondMax value
        }
        cout<<computeSum(3,9,8);
        return ans%mod;
    }
};
