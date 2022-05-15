//Problem link - https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//will sort the intervals values on basis of first value that is interval's starting value
        int size = intervals.size();//number of intervals
        vector<vector<int>> ans;
        for(int i=0;i<size-1;i++)//go to second last interval
        {
            if(intervals[i][1]>=intervals[i+1][0])/*if next interval's starting value is less than or equal
													to current interval's ending value then we can make the 
													next interval into bigger one by merging the current one
													with it*/
            {
                intervals[i+1][0] = min(intervals[i][0],intervals[i+1][0]);//starting of the merged interval will be minimum of starting values of both intervals to be merged
                intervals[i+1][1] = max(intervals[i+1][1],intervals[i][1]);//ending of the merged interval will be maximum of ending values of both interverls to be merged
                continue;//continue and try to make the merged interval into even bigger interval
            }
            ans.push_back({intervals[i][0],intervals[i][1]});//if current interval can't be merged with next one then add it directly to our answer
            
        }
        ans.push_back({intervals[size-1][0],intervals[size-1][1]});//we have to push the last interval in any case, whether it is some result of merging or lying alone
        return ans;
    }
};
