//Problem link - https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int nBuild = h.size(),sum = 0,diff;
        priority_queue<int> pq;//max heap
        for(int i=0;i<nBuild-1;i++)
        {
            if(h[i+1]>h[i])
            {
                diff = h[i+1]-h[i];
                sum += diff;
                pq.push(diff);
            }
            if(sum>b)//sum is exceeding number of bricks
            {
                if(l>0)//if there is ladder to use then use it for largest jump
                {
                    l--;//use ladder for the largest jump
                    sum = sum-pq.top();//sum reduces for largest jump
                    pq.pop();//largest jump removed from list of jumps upto here
                }
                else//now there is no ladder to use and sum exceeds bricks count hence we can't move ahead
                {
                    return i;
                }
            }
        }
        return nBuild-1;//if no condition failed in above loop it means we can reach to the end
    }
};
