//Problem link - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int nReq = 1<<k;//2^k
        int len = s.length();
        if((len-k+1)<nReq) return false;//first index of last window is (len-k) and the window number is (len-k+1) hence there are (len-k+1) 
										//windows of length k are possible in string s of length len
        
        int presNumber = 0;
        for(int i=0;i<k;i++)
        {
            presNumber = (presNumber<<1) + (s[i]-'0');
        }
        unordered_set<int> allNums;
        
        for(int i=0;i<len-k+1;i++)
        {
            allNums.insert(presNumber);//insert the current number
            presNumber = (presNumber- ((s[i]-'0')*(1<<(k-1))))*2 + (s[i+k] - '0');//re-evaluate the next number by dropping left most bit of 
																				//current window and adding upcoming bit with right place value
									/*
										Place value of MSB bit in present window = 2^(k-1) so after removing MSB from present number 
										we have to left shift the resultant value. <<1 in place of *2 gave error. Then we finally add
										the upcoming bit
									
									*/
        }
        return allNums.size()==nReq;
    }
};
