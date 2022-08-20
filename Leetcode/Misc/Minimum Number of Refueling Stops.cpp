//Problem link - https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> fuelInStock;
        int currPos = 0,stnsCovered = 0,currFuel = startFuel,nStops = 0,nStns = stations.size();
        while(currFuel>0)//Move the vehicle untill it has fuel
        {
            while(stnsCovered<nStns && stations[stnsCovered][0]<=currPos+currFuel)//add all those fuel stations' fuel amount which are reachable with current fuel in the tank
            {
                fuelInStock.push(stations[stnsCovered][1]);
                stnsCovered++;
            }
            currPos += currFuel;//Since it takes one unit fuel to cover one unit distance hence in currFuel it will cover currFuel unit of distance
            currFuel = 0;//Now fuel is used
            if(currPos>=target) return nStops;//if target reached then return current number of stops taken
            nStops++;//It should have stopped at one of the station to take fuel(the stations which offers maximum fuel)
            if(!fuelInStock.empty())
            {
                currFuel = fuelInStock.top();//take the maximum fuel
                fuelInStock.pop();//now that fuel is no more available
            }
        }
        return -1;//Can't reach the end
    }
};
