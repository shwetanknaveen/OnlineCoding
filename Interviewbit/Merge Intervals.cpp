//Problem link - https://www.interviewbit.com/problems/merge-intervals/
/*
Three possible 
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = intervals.size();
    int interToMergeWith;
    vector<Interval> ans;
    for(interToMergeWith=0;interToMergeWith<n;interToMergeWith++)//Push all the intervals which are on left of newInterval
    {
        if(intervals[interToMergeWith].end>=newInterval.start)
            break;
        else ans.push_back(intervals[interToMergeWith]);
    }
    if(interToMergeWith == n)//if all the intervals are on it's left only then just push this newInterval to extreme right and return
    {
        ans.push_back(newInterval);
        return ans;
    }
    int start = min(intervals[interToMergeWith].start,newInterval.start);//new start of merged interval will be like this
    int i;
    for(i=interToMergeWith;i<n;i++)
    {
        if(intervals[i].end>=newInterval.end)//newInterval ends in this interval or before it
        {
            if(intervals[i].start>newInterval.end)//it ends before it
            {
                ans.push_back(Interval(start,newInterval.end));//push with end limit of merged interval as end of newInterval itself
            }
            else//newInterval ends in this interval
            {
                ans.push_back(Interval(start,intervals[i].end));//end of merged interval will be same as end of this interval
                i++;//We have dealt with this interval hence increase the i value
            }
            break;
        }
    }
    while(i<n)//push all the intervals on the right side of newInterval
    {
        ans.push_back(intervals[i]);
        i++;
    }
    if(newInterval.end>intervals[n-1].end)//this is a corner case if newInterval expands beyond the right most interval
        ans.push_back(Interval(start,newInterval.end));
    return ans;
}

