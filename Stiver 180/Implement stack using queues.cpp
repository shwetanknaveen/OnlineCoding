//Problem link - https://leetcode.com/problems/implement-stack-using-queues/
//Video link - https://www.youtube.com/watch?v=jDZQKzEtbYQ&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=75

//Following implementation is done by implementing push() in O(1) and pop() in O(n) while it can be done other way around
//See same question in GFG/Must do for Oracle

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int q1siz=q1.size();
        if(q1siz==0) return -1;
        while(q1siz>1)
        {
            q2.push(q1.front());
            q1.pop();
            q1siz--;
        }
        int retVal = q1.front();
        q1.pop();
        swap(q1,q2);
        return retVal;
    }
    
    int top() {
        if(q1.empty()) return -1;
        return q1.back();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 
 
 
 
 //Implementing stack using single queue
 
 class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int qSiz=q.size();
        if(qSiz==0) return -1;
        while(qSiz>1)//push back all the elements in the same queue in same order except the last pushed element
        {
            q.push(q.front());
            q.pop();
            qSiz--;
        }
        int retVal = q.front();//store the last pushed element
        q.pop();//now remove that last pushed element too
        return retVal;//return the stored value
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.back();//return the value of last pushed element
    }
    
    bool empty() {
        return q.size()==0;
    }
};


