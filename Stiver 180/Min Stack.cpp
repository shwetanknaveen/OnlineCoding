//Problem link - https://leetcode.com/problems/min-stack/
//Video link - https://www.youtube.com/watch?v=V09NfaGf2ao

//Approach 1 ->Using two stacks...one to store minimum at top and one to store like regular stack
class MinStack {
public:
    stack<int> minStack,normStack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minStack.empty() || (!minStack.empty() && minStack.top()>=val))
        {
            minStack.push(val);//calling push() of library for stack
            normStack.push(val);//in normal stack, we have to push the value only once hence keeping it in base condition
            					//calling push() of library for stack
            cout<<"\npushed "<<normStack.top()<<" in normStack\n";
            cout<<"\npushed "<<minStack.top()<<" in minStack\n";
            return;
        }
        int top = minStack.top();//calling top() of library for stack
        minStack.pop();//calling pop() of library for stack
        push(val);//calling push() defined here
        minStack.push(top);//calling push() of library for stack
    }
    void popFromMinStack(int val)
    {
        if(minStack.top() == val)//if value to be deleted is at top
        {
            minStack.pop();//calling pop() of library for stack
            return;
        }
        int top = minStack.top();//calling top() of library for stack
        						//store the top value
        minStack.pop();//remove the top value //calling pop() of library for stack
        popFromMinStack(val);//Recursively delete the value
        minStack.push(top);//push the stored value using regular push() library function for stack as minStack was already
        					//in order and we just removed one value from inbetween and storing back other popped off values
        					//in same order
    }
    void pop() {
        int top = normStack.top();//calling pop() of library for stack
        normStack.pop();//calling pop() of library for stack
        popFromMinStack(top);//popFromMinStack() is defined here
    }
    
    int top() {
        return normStack.top();//calling top() of library for stack
    }
    
    int getMin() {
        return minStack.top();//calling pop() of library for stack //minimum value is at top of minStack
    }
};



//Approach 2 -> Storing value and minimum till this point in pairs
class MinStack {
public:
    stack<pair<int,int>> stac;//<value,min value till here>
    MinStack() {
        
    }
    
    void push(int val) {
        if(stac.empty())
        {
            stac.push(make_pair(val,val));//if stack is empty then the value being pushed will also be minimum itself
        }
        else
        {
            stac.push(make_pair(val,min(val,stac.top().second)));//minimum value will be minimum of minimum till here and this value
        }
    }
    
    void pop() {
        stac.pop();
    }
    
    int top() {
        return stac.top().first;
    }
    
    int getMin() {
        return stac.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 
 
 
 
