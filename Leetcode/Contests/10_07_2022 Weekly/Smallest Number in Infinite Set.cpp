//Problem link - https://leetcode.com/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet {
public:
    int smallest;
    set<int> setOfDeleted;
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int retVal = smallest;
        while(setOfDeleted.find(++smallest)!=setOfDeleted.end());//We have to skip all those values which have been deleted for the next smallest value
        setOfDeleted.insert(retVal);//Now the value which is being returned will now be deleted
        return retVal;
    }
    
    void addBack(int num) {
        smallest = min(smallest,num);//Now the upcoming value can be the smallest one
        if(setOfDeleted.find(num)!=setOfDeleted.end())
            setOfDeleted.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
