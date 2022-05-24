//Problem link - https://leetcode.com/problems/insert-interval/
//Same question -> "Interviewbit/"Merge Intervals"
/*
There are three steps for doing it
Step - 1 -> Push all the intervals on the left of this newInterval
Step - 2 -> Merge this newInterval with all possible intervals with which it can be merged
Step - 3 -> Push all the intervals on the right of merged intervals
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n = intervals.size();
	    int interToMergeWith;
	    vector<vector<int>> ans;
	    for(interToMergeWith=0;interToMergeWith<n;interToMergeWith++)//Push all the intervals which are on left of newInterval
	    {
	        if(intervals[interToMergeWith][1]>=newInterval[0])
	            break;
	        else ans.push_back(intervals[interToMergeWith]);
	    }
	    if(interToMergeWith == n)//if all the intervals are on it's left only then just push this newInterval to extreme right and return
	    {
	        ans.push_back(newInterval);
	        return ans;
	    }
	    int start = min(intervals[interToMergeWith][0],newInterval[0]);//new start of merged interval will be like this
	    int i;
	    for(i=interToMergeWith;i<n;i++)
	    {
	        if(intervals[i][1]>=newInterval[1])//newInterval ends in this interval or before it
	        {
	            if(intervals[i][0]>newInterval[1])//it ends before it
	            {
	                ans.push_back({start,newInterval[1]});//push with end limit of merged interval as end of newInterval itself
	            }
	            else//newInterval ends in this interval
	            {
	                ans.push_back({start,intervals[i][1]});//end of merged interval will be same as end of this interval
	                i++;//We have dealt with this interval as this has been covered in merged interval hence increase the i value
	            }
	            break;
	        }
	    }
	    while(i<n)//push all the intervals on the right side of newInterval
	    {
	        ans.push_back(intervals[i]);
	        i++;
	    }
	    if(newInterval[1]>intervals[n-1][1])//this is a corner case if newInterval expands beyond the right most interval
	        ans.push_back({start,newInterval[1]});
	    return ans;
    }
};
