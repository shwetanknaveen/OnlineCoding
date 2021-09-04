//Problem link - 
class Solution
{
public:
    void insert(int arr[], int i)//insert ith index element at its proper place
    {
        //code here
        int toBeInserted = arr[i];
        int j=i-1;//start looking from its immediate left
        while(j>=0 && arr[j]>toBeInserted)//until we keep on getting elements greater than it, we shift them to right
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = toBeInserted;//after coming out from loop either j will be -1 or j will be pointing to a element which
        						//is less than toBeInserted so we don't shift it to the right rather we insert the element
        						//on the right itself i.e., at j+1
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        if(n==1) return;//one element is already sorted
        
        for(int i = 1;i<n;i++)
        insert(arr,i);
    }	
};
