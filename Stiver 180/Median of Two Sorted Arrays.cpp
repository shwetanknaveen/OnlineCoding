//Problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/
//Video link - https://www.youtube.com/watch?v=NTop3VTjmxk&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=66
//Time complexity - O(min(m,n))
//See the modification of this algorithm in next question "K-th element of two sorted Arrays"
/*
We divide numbers into two half. If numbers are even then equal half otherwise left half contains one extra number.
Left part numbers will always be smaller than numbers in right part
Case 1-> If numbers are even then median is average of largest number of left half and smallest number of right half
Case 2-> If numbers are odd then median is largest of left half as it will contain 1 more number than right half

Here cut1 is dividing the first arrray and cut2 is dividing the second array.

Here we assume that nums1 is smaller array.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	
    	//In order to implement the idea that in case of total numbers are odd then we have to keep one extra number in 
    	//left half, cut2 is defined in such a way that if nums2 becomes empty then there will be out of bound error
    	//hence we alway keep smaller array to nums1 and in this way we manage time complexity as O(min(m,n)) as search
    	//space for binary search is only our first array
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);
        int n1 = nums1.size();
        int n2 = nums2.size(); 
        int low = 0, high = n1;//we can pick all the numbers from first array and put the cut1 after it(high=n1)
        						//or we can pick no number from first array (low=0)
        						
        //Here low and high are not used as indices rather they are number of numbers picked from first array for left half
        //In this search space when cut1 is assigned and then cut2 is assigned accordingly,and we use them as index, we
        //do required appropriate changes
        while(low <= high) {
            int cut1 = (low+high) >> 1;
            int cut2 = (n1 + n2 + 1) / 2 - cut1; //cut1 is numbers from first array in contributed left half now we know that
            									//number of numbers in contributed left half should be equal to half of 
            									//total numbers hence if first array contributed cut1 then remaining in left
            									//half will be contributed by second array.
            									//We also know that if total numbers are odd then left half should have one
												//more number than right half	
            
        	/*
			Combined array     (Left half)	|	(Righ half)
							cut1 from first		n1-cut1 from first array
							array and cut2		and n2-cut2 from second array
							from second array
			*/
			
			//if there is no left1,left2 and others then they are assigned accordingly so that they don't violate the
			//conditions being checked below
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];//last element of left half of first array
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1]; //last element of left half of second array
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];//first element of right half of first array
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2]; //first element of right half of second array
            
            //left1 will obviously be less than right1 as they are from different half of same sorted array and same case
            //with left2 and right2
            if(left1 <= right2 && left2 <= right1) {//if partition is right
                if( (n1 + n2) % 2 == 0 ) //if total no. of numbers is even
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
                else 
                    return max(left1, left2); 
            }
            //We are doing binary search only on first array and then accordingly no. selection in second array is adjusted
            else if(left1 > right2) {
                high = cut1 - 1; 
            }
            else {
                low = cut1 + 1; 
            }
        }
        return 0.0; 
    }
};
