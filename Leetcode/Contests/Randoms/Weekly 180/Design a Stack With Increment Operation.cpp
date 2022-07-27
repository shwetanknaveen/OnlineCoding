//Problem link - https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    vector<int> stack;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size()<maxSize) stack.push_back(x);
    }
    
    int pop() {
        if(stack.empty()) return -1;
        int retVal = stack.back();
        stack.pop_back();
        return retVal;
    }
    
    void increment(int k, int val) {
        int size = stack.size();
        int mini = min(k,size);
        for(int i=0;i<mini;i++)
            stack[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
