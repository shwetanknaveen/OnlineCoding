//Problem link - https://practice.geeksforgeeks.org/problems/set-bits0143/1
class Solution {
  public:
  	//In order to count number of  set bits, we just need to count the number of 1(s) in the binary representation of the nu-
  	//-mber
    int setBits(int N) {
        int count = 0;
        while(N)
        {
            if(N%2==1)
            count++;
            N /= 2;
        }
        return count;
        // Write Your Code here
    }
};
