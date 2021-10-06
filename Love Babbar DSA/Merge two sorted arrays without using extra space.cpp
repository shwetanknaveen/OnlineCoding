//Problem link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
//Video link - https://www.youtube.com/watch?v=hVl2b3bLzBw
class Solution{
public:
	int nextGap(int gap) {
	    if (gap <= 1) return 0;
	    return (gap / 2) + (gap % 2);
	}
public:
	void merge(int arr1[], int arr2[], int n, int m) {
		//we will see the lists as second list appended in end of the first one
		//shell sort for the combined list
		//shell sort is modified insertion sort. While insertion sort exchanges elements which are adjacent, shell sort exchanges at a distance of gap
	    int i, j, gap = n + m;
	    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
	        for (i = 0; i + gap < n; i++)//doing swaps in the first list only
	            if (arr1[i] > arr1[i + gap]) swap(arr1[i], arr1[i + gap]);

	        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)//now (i+gap) has crossed the first list but we have to compare the remaining elements of first list to +gap elements in the second list
	            if (arr1[i] > arr2[j]) swap(arr1[i], arr2[j]);//here i and j are initialised such that they are at distance = gap

	        if (j < m) {//we haven't covered all elements of 2nd list.

	            for (j = 0; j + gap < m; j++)//start looking from the beginning of the second list
	                if (arr2[j] > arr2[j + gap]) swap(arr2[j], arr2[j + gap]);
	        }
	    }
	}
};
