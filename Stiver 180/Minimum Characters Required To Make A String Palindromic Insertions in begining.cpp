//Problem link - https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/


//Brute force method - O(n^2)
bool isPalin(string str)
{
    int i=0,j=str.length()-1;
    while(i<j)
    {
        if(str[i++]!=str[j--])
            return false;
    }
    return true;
}
int Solution::solve(string A) {
    string pref = "";
    string newString = A;
    int lenA = A.length();
    int j = lenA-1;
    while(!isPalin(newString))
    {
       pref = pref+A.substr(j,1);
       newString = pref + A;
       j--;
    }
    return pref.length();
}


//Approach 2 Using LPS table.Length of longest prefix which is also a suffix
//Time complexity = O(n)

//If we find the lps value of following string
// A + "$" + reverseOfA
// It gives length of that right part of A which is already palindromic.Now the remaining part can be reversed and appended
//in the beginning of A and in this way A can be converted into palindrome

int Solution::solve(string A) {
    string revStr = A;
    reverse(revStr.begin(),revStr.end());
    string newString = A + "$" + revStr;
    int len = newString.length();
    vector<int> lps(len);
    lps[0] = 0;
    int i=0,j=1;
    while(j<len)
    {
        if(newString[i] == newString[j])
        {
            lps[j] = i+1;
            i++;
            j++;
        }
        else
        {
            if(i==0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i-1];
            }
        }
    }
    return (A.length()-lps[len-1]);
}

