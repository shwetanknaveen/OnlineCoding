//Problem link - https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1

class Solution{
    public:
    vector<int> kthSmallestNum(vector<vector<int>>&ranges, vector<int>queries)
    {
        sort(ranges.begin(),ranges.end());
        vector<vector<int>> mergedIntrs;
        for(int i=0;i<ranges.size()-1;i++)
        {
            if(ranges[i][1]>=ranges[i+1][0])//if end limit of this range overlaps start of next range
            {
                ranges[i+1][0] = ranges[i][0];//give the start of merged range as minimum one
                ranges[i+1][1] = max(ranges[i][1],ranges[i+1][1]);//end as maximum one
            }
            else
            {
                mergedIntrs.push_back(ranges[i]);//push this unoverlapping interval
            }
        }
        mergedIntrs.push_back(ranges[ranges.size()-1]);//push the last interval
        int nIntrs = mergedIntrs.size();
        vector<int> countOfNumsInIntrs(nIntrs,0);
        countOfNumsInIntrs[0] = mergedIntrs[0][1] - mergedIntrs[0][0] + 1;
        for(int i=1;i<nIntrs;i++)//store the prefix sum
        {
            countOfNumsInIntrs[i] = (mergedIntrs[i][1] - mergedIntrs[i][0] + 1) + countOfNumsInIntrs[i-1];
        }
        vector<int> ans;
        for(auto query:queries)
        {
            int intrInd = lower_bound(countOfNumsInIntrs.begin(),countOfNumsInIntrs.end(),query)-countOfNumsInIntrs.begin();//required value lies in interval at intrInd
            if(intrInd==nIntrs) ans.push_back(-1);//there are total numbers less than query itself hence there is no ans for this query
            else
            {
                int beforeThisIntr = intrInd>0?countOfNumsInIntrs[intrInd-1]:0;//how many numbers are there before this interval
                ans.push_back(mergedIntrs[intrInd][0]+(query-beforeThisIntr-1));//this interval starts from mergedIntrs[intrInd][0]
            }
        }
        return ans;
    } 
};


