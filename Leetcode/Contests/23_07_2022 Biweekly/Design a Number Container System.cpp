//Problem link - https://leetcode.com/problems/design-a-number-container-system/

class NumberContainers {
public:
    unordered_map<int,int> holder;//index -> number
    unordered_map<int,set<int>> numIndices;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int prevNum = INT_MAX;
        if(holder.find(index) != holder.end())
            prevNum = holder[index];
        if(prevNum != INT_MAX)
        {
            numIndices[prevNum].erase(index);
            if(numIndices[prevNum].size()==0)
                numIndices.erase(prevNum);
        }
        holder[index] = number;
        numIndices[number].insert(index);
        
    }
    
    int find(int number) {
        if(numIndices.find(number) == numIndices.end()) return -1;
        return *(numIndices[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
