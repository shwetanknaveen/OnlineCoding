//Question link - https://www.hackerrank.com/contests/iiit-bangalore-1/challenges/demo-53/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void getAns(vector<vector<char>> &maze,int currRow,int currColumn,int m,int n,int &ans)
{
    if(currRow==m && currColumn == n)
    {
        ans = ans +1;//reached bottom right column then increase no. of ways to reach here and return
        return;
    }
    if(currRow>m || currColumn>n || maze[currRow][currColumn] == '*') return;//found puddle or limits exceeding. Here maze[currRow][currColumn] == '*' won't
    																		//cause out of bound exception as before that currRow>m || currColumn>n would have 
    																		//evaluated true hence maze[currRow][currColumn] == '*' won't be evaluated
    getAns(maze,currRow+1,currColumn,m,n,ans);//He can go down
    getAns(maze,currRow,currColumn+1,m,n,ans);//He can go right
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
    int ans = 0;
    int n,m;
    cin>>m>>n;
    vector<vector<char>> maze(m+1,vector<char>(n+1));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>maze[i][j];
        }
    }
    getAns(maze,1,1,m,n,ans);
    cout<<ans;
        if(testCases!=0) cout<<endl;
    }
    return 0;
}

