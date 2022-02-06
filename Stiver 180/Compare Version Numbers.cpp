//Problem link - https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int verNum(string s)
    {
        int ans = 0,i=0,len = s.length();
        while(i<len)//removing intial 0s
        {
            if(s[i]==0)
                i++;
            else break;
        }
        s=s.substr(i,len-i);
        for(char c:s)
        {
            ans = 10*ans + (c-'0');
        }
        return ans;
    }
    int compareVersion(string version1, string version2) {
        int len1=version1.length(), len2=version2.length();
        int i1=0,i2=0,j1,j2,num1,num2;
        while(i1<len1 && i2<len2)
        {
            j1=i1;
            j2=i2;
            while(j1<len1)
            {
                if(version1[j1]!='.')
                    j1++;
                else 
                    break;
            }
            num1 = verNum(version1.substr(i1,j1-i1));
            i1 = j1+1;
            
            while(j2<len2)
            {
                if(version2[j2]!='.')
                    j2++;
                else 
                    break;
            }
            num2 = verNum(version2.substr(i2,j2-i2));
            i2 = j2+1;
            
            if(num1<num2) return -1;
            if(num1>num2) return 1;
            if(num1 == num2 && j1==len1 && j2 == len2) return 0;//both string ended with last same last revision number
            //We can't return 0 on same revision number if strings didn't end becasue further revisions after . may vary
        }
        
        while(i1<len1)//version1 didn't end ans version2 ended
        {
            j1=i1;
            while(j1<len1)
            {
                if(version1[j1]!='.')
                    j1++;
                else 
                    break;
            }
            num1 = verNum(version1.substr(i1,j1-i1));
            i1 = j1+1;
            if(num1>0) return 1;
        }
         while(i2<len2)//version2 didn't end ans version1 ended
        {
            j2=i2;
            while(j2<len2)
            {
                if(version2[j2]!='.')
                    j2++;
                else 
                    break;
            }
            num2 = verNum(version2.substr(i2,j2-i2));
            i2 = j2+1;
            if(num2>0) return -1;
        }
        return 0;//default case
    }
};
