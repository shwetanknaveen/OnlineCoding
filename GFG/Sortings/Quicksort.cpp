//Problem link - https://practice.geeksforgeeks.org/problems/quick-sort/1
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high)
        {
            int q = partition(arr,low,high);//q is the index where pivot = arr[high] has
                                        //been inserted such that all elements on its
                                        //left are smaller than it
            quickSort(arr,low,q-1);
            quickSort(arr,q+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int i,j,temp;
       i = low -1;
       
       //We know that our end element will be pivot hence to make randomized selection of pivot we can do following
       int p = rand () % (high - low + 1) + low;
       int t = arr[high];
       arr[l] = arr[p];
       arr[p] = t;
       //end of logic for using randomized pivot
       
       
       for(j=low;j<=(high-1);j++)// Pivot = arr[high]
       {
           if(arr[j]<arr[high])
           {
               temp = arr[++i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
       //when scan has been done to whole left of pivot element then swap the pivot ele-
       //ment at its right place
       temp = arr[high];
       arr[high] = arr[++i];
       arr[i] = temp;
       return i;//return the index where the pivot element has been inserted so that
                //further quicksorts will be called on its left and right
    }
};

