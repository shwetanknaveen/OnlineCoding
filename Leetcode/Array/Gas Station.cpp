//Problem link - https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int currSum = 0,totalSum = 0,ans = 0,diffAtI;
        for(int i=0;i<n;i++)
        {
            diffAtI = gas[i] - cost[i];
            totalSum += diffAtI;
            
            //If this value is zero at some index it means after reaching that station, the tank becomes empty
            if(currSum+diffAtI<0)//We can't reach here from where we thought of starting i.e., ans
            {
                currSum = 0;//diffAtI must be negative which is making currSum -ve hence from the index
                            //'ans' where we have thought of starting, we can't start from there
                ans = -1;//unset the ans index
                continue;//look ahead that from where we can start
            }
            currSum += diffAtI;//We had started from 'ans' index and maintaining a +ve sum
            if(ans == -1) ans = i;//If this the index from where we have to start then ans must have been
                                    //in unset position and hence we need to set it here
        }
        if(totalSum<0) return -1;//if totalSum is -ve, there won't be any answer
        return ans;
    }
};
