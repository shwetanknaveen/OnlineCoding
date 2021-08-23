//Problem link - https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1
class Solution{
    public:
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        //code here
        map<int,int> elements;
        int minIndex=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(elements.find(arr[i])==elements.end())//find() return end iterator if- 
            elements[arr[i]]=i+1;                 //-doesn't find the given key
            
            else minIndex = min(minIndex,(elements.find(arr[i]))->second);//find() return iterator
                                                        //from where ->second give
                                                        //value at key
        }
        if(minIndex!=INT_MAX) return minIndex;
        return -1;//no element is repeated
    }
};
