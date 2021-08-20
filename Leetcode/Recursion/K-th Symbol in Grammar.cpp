//Poblem link - https://leetcode.com/problems/k-th-symbol-in-grammar/submissions/
//Aditya verma link - https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1) return 0;//only element in first row is 0 hence it's first element will be zero
        int prevIndex = k&1 ? (k/2+1) : k/2;/*
        									The index which is responsible for generating the kth symbol in nth row would be
        									(k/2+1)th symbol in (n-1)th row if k is odd or it would be (k/2)th sybmol in (n-1)th
											row. It can be understood with example
											*/
        int prev = kthGrammar(n-1,prevIndex);/*
        									get the previous symbol from (n-1)th row which is reposible for generating kth sym
        									-bol in this nth row.
        									*/
        if(prev==0) return k&1 ? 0 : 1;		/*
        									0 produces 01. Hence if responsible symbol was 0 then kth symbol is 0 at first place
        									and 1 at second place
        									*/
        else return k&1 ? 1 : 0;			/*This case deals prev = 1
        									1 produces 10. Hence if responsible symbol was 0 then kth symbol is 1 at first place
        									and 0 at second place
        									*/
        
    }
};
