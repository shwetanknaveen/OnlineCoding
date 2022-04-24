//Problem link - https://leetcode.com/problems/design-underground-system/

//Approach 1
struct Passenger
{
    int id;
    int src,checkInTime;
    int dest,checkOutTime;
    bool isCompleted;
    Passenger(int id)
    {
        this->id = id;
        isCompleted = false;
    }
    void setSrc(int src,int checkInTime)
    {
        this->src = src;
        this->checkInTime = checkInTime;
    }
    void setDest(int dest,int checkOutTime)
    {
        this->dest = dest;
        this->checkOutTime = checkOutTime;
        isCompleted = true;
    }
};
class UndergroundSystem {
public:
    unordered_map<string,int> stnCode;
    int code;
    vector<Passenger*> trips;
    UndergroundSystem() {
        code = 0;//Stations will get codes as 1,2,3....and so on
    }
    void checkIn(int id, string stationName, int t) {
        Passenger *psngr = new Passenger(id);
        
        if(stnCode.find(stationName)==stnCode.end())
            stnCode[stationName]= ++code;
        psngr->setSrc(stnCode[stationName],t);
        trips.push_back(psngr);
    }
    
    void checkOut(int id, string stationName, int t) {
        if(stnCode.find(stationName)==stnCode.end())
            stnCode[stationName]= ++code;
        for(auto p:trips)
        {
            if(p->id==id && p->isCompleted==false)
            {
                p->setDest(stnCode[stationName],t);
                break;
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        int srcCode = stnCode[startStation], destCode = stnCode[endStation];
        double totalTime = 0.0;
        int count = 0;
        for(auto p:trips)
        {
            if(p->src==srcCode && p->dest == destCode)//p->dest default value will be zero and destCode value >=1 hence this if condition will
            										//evaluate true for only those trips which are completed and whose src,dest codes match
            {
                totalTime += p->checkOutTime - p->checkInTime;
                count++;
            }
        }
        return totalTime/count;
    }
};

//Approach 2
class UndergroundSystem {
public:
    unordered_map<string,int> time,count;//src_dest->time       and         src_dest->count
    unordered_map<int,pair<int,string>> inJourney;//id -> <checkInTime,src> 
    
    void checkIn(int id, string stationName, int t) {
        auto p = make_pair(t,stationName);
        inJourney[id] = p;
    }
    
    void checkOut(int id, string stationName, int t) {
        int checkInTime = inJourney[id].first;
        string srcName = inJourney[id].second;
        inJourney.erase(id);
        string key = srcName + "_" +stationName;
        time[key] += t-checkInTime;
        count[key]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "_" + endStation;
        return double(time[key])/double(count[key]);
    }
};


