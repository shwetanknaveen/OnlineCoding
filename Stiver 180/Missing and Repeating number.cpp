//Problem link - https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_873366?topList=striver-sde-sheet-problems&leftPanelTab=1
//Video link - https://www.youtube.com/watch?v=5nMGY4VUoRY


pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
       /* Will hold xor of all elements
       and numbers from 1 to n  */
        int xor1;
 
        /* Will have only single set bit of xor1 */
        int set_bit_no;
 
        int i;
        int x = 0;
        int  y = 0;
 
        xor1 = arr[0];
 
        /* Get the xor of all array elements  */
        for (i = 1; i < n; i++)
            xor1 = xor1 ^ arr[i];
 
        /* XOR the previous result with numbers from
       1 to n*/
        for (i = 1; i <= n; i++)
            xor1 = xor1 ^ i;
 
        /* Get the rightmost set bit in set_bit_no
		LEARN BELOW TECHNIQUE TO GET RIGHT MOST SET BIT OF A NUMBER */
		
        set_bit_no = xor1 & ~(xor1 - 1);//AND the 2's complement with no. itself
        
        /*set_bit_no will have numeric value after setting the right most set bit
 		Like if xor1 = 3 then set_bit_no = 1
 		if xor1 = 4 then set_bit_no = 4 and so on
 		*/
        /* Now divide elements into two sets by comparing
    rightmost set bit of xor1 with the bit at the same
    position in each element. Also, get XORs of two
    sets. The two XORs are the output elements. The
    following two for loops serve the purpose */
        for (i = 0; i < n; i++) {
            if ((arr[i] & set_bit_no) != 0)//bucketing numbers given in the list
                /* arr[i] belongs to first set */
                x = x ^ arr[i];
 
            else
                /* arr[i] belongs to second set*/
                y = y ^ arr[i];
        }
        for (i = 1; i <= n; i++) {//bucketing numbers given in from 1 to n
            if ((i & set_bit_no) != 0)
                /* i belongs to first set */
                x = x ^ i;
 
            else
                /* i belongs to second set*/
                y = y ^ i;
        }
        bool flag = false;
      for(i=0;i<n;i++){//traversing array again to find that the found number is 
      					//missing or the repeated one
          if(arr[i]==x){
              flag = true;
              break;
          } 
           
      }
       
      pair<int,int> ans;//first one is missing one and second one is repeated
      if(flag)
      {
          ans.first = y; ans.second = x;
      }
      else
      {
          ans.first = x; ans.second = y;
      }
      return ans;
}

