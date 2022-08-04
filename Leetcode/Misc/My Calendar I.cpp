//Problem link - https://leetcode.com/problems/my-calendar-i/

class MyCalendar {
public:
    map<int,int> diff;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        /*
        We know that in difference array concept, if we wish to make a change of x from i to j we add
        x at index i in difference array and subtract x at index j+1. When we wish to see the actual
        difference, we do prefix sum of the difference array.
        See platform question
        */
        diff[start]++;
        diff[end]--;
        int maxi = 0,sum = 0;
        for(auto p:diff)
        {
            sum += p.second;
            maxi = max(maxi,sum);
        }
        if(maxi>=2)//We can't have more than one interval simultaneously
        {
         diff[start]--;
         diff[end]++;
         return false;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
