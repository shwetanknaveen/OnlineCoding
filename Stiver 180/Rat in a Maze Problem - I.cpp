//Problem link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
//Video link - https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=60

/*
Time Complexity: O(3^(n^2)). 
As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. So the time complexity O(3^(N^2).

Space Complexity: O(n^2) ->All cells can be at stack at max
*/
class Solution{
    public:
    void solve(vector<vector<int>> &m,int &n,int i,int j,string &s,vector<string> &ans)
    {
        if(i==n-1 && j==n-1)//reached to the final cell
        {
            ans.push_back(s);
            return;
        }
        if(i-1>=0 && m[i-1][j]!=0)//can go UP as it doesn't cross boundary and it is not blocked
        {
            m[i][j]=0;//mark this cell blocked so that this path doesn't cross itself
            s.push_back('U');//push U in the path string as going upward
            solve(m,n,i-1,j,s,ans);//solve by decreasing the row index
            s.pop_back();//for exploring next option when recursion call returns to this level
            m[i][j]=1;//unbloking the cell so that next option can be explored when recursion call returns to this level
        }
        
        if(i+1<n && m[i+1][j]!=0)//can go DOWN as it doesn't cross boundary and it is not blocked
        {
            m[i][j]=0;//mark this cell blocked so that this path doesn't cross itself
            s.push_back('D');//push D in the path string as going downward
            solve(m,n,i+1,j,s,ans);//solve by increasing the row index
            s.pop_back();//for exploring next option when recursion call returns to this level
            m[i][j]=1;//unbloking the cell so that next option can be explored when recursion call returns to this level
        }
        if(j-1>=0 && m[i][j-1]!=0)//can go LEFT as it doesn't cross boundary and it is not blocked
        {
            m[i][j]=0;//mark this cell blocked so that this path doesn't cross itself
            s.push_back('L');//push L in the path string as going leftward
            solve(m,n,i,j-1,s,ans);//solve by decreasing the column index
            s.pop_back();//for exploring next option when recursion call returns to this level
            m[i][j]=1;//unbloking the cell so that next option can be explored when recursion call returns to this level
        }
        if(j+1<n && m[i][j+1]!=0)//can go RIGHT as it doesn't cross boundary and it is not blocked
        {
            m[i][j]=0;//mark this cell blocked so that this path doesn't cross itself
            s.push_back('R');//push R in the path string as going rightward
            solve(m,n,i,j+1,s,ans);//solve by increasing the column index
            s.pop_back();//for exploring next option when recursion call returns to this level
            m[i][j]=1;//unbloking the cell so that next option can be explored when recursion call returns to this level
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s;
        if(m[0][0]==0)//if the starting cell itself is blocked then return
        {
            ans.push_back("-1");
            return ans;
        }
        solve(m,n,0,0,s,ans);
        return ans;
    }
};





//Above code in a neat way as below

class Solution{
    void solve(int i, int j, vector<vector<int>> &a, int &n, vector<string> &ans, string &move, 
     int di[], int dj[],string &dir) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return; 
        }
         
        for(int ind = 0; ind<4;ind++) {
            int nexti = i + di[ind]; 
            int nextj = j + dj[ind]; 
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && a[nexti][nextj] == 1) {
                a[i][j] = 0;
                move.push_back(dir[ind]);
                solve(nexti, nextj, a, n, ans, move,di, dj,dir);
                move.pop_back();
                a[i][j] = 1; 
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string dir = "DLRU";
        int di[] = {+1, 0,  0,  -1}; 
        int dj[] = {0, -1,  1,   0}; 
        //			D	L	R	 U
        string move="";
        if(m[0][0] == 1) solve(0,0,m,n, ans,move,di, dj,dir); 
        return ans; 
    }
};
