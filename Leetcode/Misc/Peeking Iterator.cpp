//Problem link - https://leetcode.com/problems/peeking-iterator/

class PeekingIterator : public Iterator {
public:
    
    int currElement;
    bool isNextExists;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
        if( Iterator::hasNext() ) currElement = Iterator::next(), isNextExists = true;
        else isNextExists = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return currElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
        int curr = currElement;
        if( Iterator::hasNext() ) currElement = Iterator::next();
        else isNextExists = false;
        
        return curr;
	}
	
	bool hasNext() const {
	    return Iterator::hasNext() | isNextExists;//We have to take "OR" with isNextExists because if there is only one element in the 
	    										//nums then iterator will already be pointing to it and hence hasNext() will return false
	    										//hence we OR with isNextExists
	}
};
