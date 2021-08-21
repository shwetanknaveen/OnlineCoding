//PROBLEM LINK - https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1/?track=sp-recursion&batchId=105
//Aditya verma video link - https://www.youtube.com/watch?v=Yg5a2FxU4Fo 
//Aditya verma initial and more explanation - https://www.youtube.com/watch?v=kHi1DUhp9kM&t=1503s
void solve(string inp,string output,vector<string> &v)
{
    if(inp.length()==0)//if we have made all possible decisions on input and input string is empty then we add output to 
    					//output list
    {
        v.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;//at next step we have two outputs
    output2.push_back(inp[0]);//first output remains same as previous stage output as it doesn't choose next symbol (first sym
							//-bol from remaining inp string) but second output chooses it
    inp.erase(inp.begin()+0);//input is shortened by removing first symbol of input as decisions on that have been made
    solve(inp,output1,v);//calls with new input and outputs
    solve(inp,output2,v);
}

vector <string> powerSet(string s)
{
   //Your code here
   vector<string> list;
   solve(s,"",list);
   return list;
}

