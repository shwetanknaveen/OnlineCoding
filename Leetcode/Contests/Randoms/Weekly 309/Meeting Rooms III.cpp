//Problem link - https://leetcode.com/problems/meeting-rooms-iii/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> availRooms;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>>  endTimeRoomNo;
        //<meeting end time,in which room no.>
        for(int i=0;i<n;i++)//initially all rooms are available
            availRooms.push(i);
        vector<int> count(n,0);
        for(auto meet:meetings)
        {
            while(!endTimeRoomNo.empty() && endTimeRoomNo.top().first<=meet[0])
            {
                availRooms.push(endTimeRoomNo.top().second);
                endTimeRoomNo.pop();
            }
            //Now all meetings which should have ended have ended
            if(endTimeRoomNo.size()<n)//get a new room as room is available
            {
                endTimeRoomNo.push({meet[1],availRooms.top()});
                count[availRooms.top()]++;
                availRooms.pop();
            }
            else//wait for the room which will be free at the earliest
            {
                auto soonFreeRoom = endTimeRoomNo.top();
                endTimeRoomNo.pop();
                soonFreeRoom.first += (meet[1]-meet[0]);
                endTimeRoomNo.push(soonFreeRoom);
                count[soonFreeRoom.second]++;
            }
        }
        return (max_element(count.begin(),count.end()) - count.begin());
    }
};
