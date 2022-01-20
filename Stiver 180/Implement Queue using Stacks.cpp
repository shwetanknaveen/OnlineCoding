//Problem link - https://leetcode.com/problems/implement-queue-using-stacks/
//Video link - https://www.youtube.com/watch?v=3Et9MrMc02A&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty() && s2.empty()) return -1;
        int retVal;
        if(!s2.empty()) 
        {
            retVal = s2.top();
            s2.pop();
            return retVal;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        retVal = s2.top();
        s2.pop();
        return retVal;
    }
    
    //peek() returns the front of queue
    int peek() {//it is given that it will always be valid operation hence peek() won't be called if both stacks empty
        if(!s2.empty()) return s2.top();
        int retVal;
        while(!s1.empty())//if s2 is empty then what has to be at its top is at bottom of s1
        {
            s2.push(s1.top());
            s1.pop();
        }
        retVal = s2.top();//store the top
        while(!s2.empty())//restore the previous state so that further pushes don't go in wrong order
        {
            s1.push(s2.top());
            s2.pop();
        }
        return retVal;//return the stored value
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
