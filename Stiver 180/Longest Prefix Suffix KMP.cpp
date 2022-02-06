//Problem link - https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#
//Video link - https://www.youtube.com/watch?v=V5-7GzOfADQ&t=471s


class Solution{
  public:		
	int lps(string s) {
	    int len = s.length();
	    vector<int> lps(len);
	    lps[0] = 0;
	    int i = 0,j = 1;//j is from where matching suffix ends and i is the length of matching prefix
	    while(j<len)//we assume that characters are numbered as 1,2....
	    {
	        if(s[i] == s[j])
	        {
	            lps[j] = i+1;//jth index character is equal to ith character in the string
	            i++;//compare the next character hence advance both pointers
	            j++;
	        }
	        else
	        {
	            if(i==0)//matching was being done with first index character
	            {
	                lps[j] = 0;//jth index character is not same to prefix style character from start hence we store 0 here
	                j++;//we will look forward to compare next character with first character so that suffix equal to 
	                		//prefix starts making up as we know matching suffix ends at jth index
	            }
	            else
	            {
	                i = lps[i-1];
	                
	                /*
	                index			0 1 2 3 4 5 6 7 8 9 10 11
					string			Y Y C G I C G Y Y Y  C G
	                lps value		0 1 0 0 0 0 0 1 2 2  3 4
	                
	                When C at index=2 didn't match with Y at index=9, we can't set i again to 0 to look for the prefix from 
	                begining. We know that j never returns back hence the suffix character which is at index j is not matching
	                with prefix character at index i, can match if we reduce current length of prefix. Now lps of index just
	                before i gives index of character after that longest prefix which was prefix and suffix upto j. Hence
	                now this character can be compared to jth index character
	                */
	            }
	        }
	    }
	    return lps[len-1];
	    
	    /*
	    If overlapping wasn't allowed, we would have returned the value as following
	    
	    return lps[len-1] > len/2 ? len/2 : lps[len-1];
	    */
	}
};

