//Problem link - https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
public:
    map<int,int> diff;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
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
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
