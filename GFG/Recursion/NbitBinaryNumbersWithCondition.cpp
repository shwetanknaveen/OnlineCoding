//Problem link- https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1#
//Aditya Verma link- https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=18
class Solution{
public:	
    void generateStrings(int ones,int zeroes,int N,string output,vector<string> &list)
	{
		//since output is getting build from left to right then it keep on checking for all the prefixes
		
	    if(output.length()==N && ones>=zeroes)//output has reached the desired length with given condition then add this outp-
	    									//-ut in the list and return
	    {
	        list.push_back(output);
	        return;
	    }
	    if(zeroes>ones) return;//condition violated for current prefix hence return
	    
	    string output1 = output;
	    string output2 = output;
	    output1.push_back('1');//ouput1 chooses 1 as next append
	    output2.push_back('0');//output 2 chooses 0 as next append
	    generateStrings(ones+1,zeroes,N,output1,list);//same no. of zeroes but +1 no. of ones called forward on output1
	    generateStrings(ones,zeroes+1,N,output2,list);//same no. of ones with +1 no. of zeroes called forward on output2
	}
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> list;
	    generateStrings(1,0,N,"1",list);//it's given that minimum length given will be 1 so we can keep the intial string as 1
	    								//with initial no. of 1's(ones) = 1 and 0's (zeroes) = 0
	    return list;
	}
};
