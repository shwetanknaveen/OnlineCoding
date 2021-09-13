#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int help(vector<vector<char>> &a, vector<vector<int>> &dp, int x, int y, int r, int c){
    // base cases
    if(x >= r || y >= c || a[x][y] == '*') return 0;
    if(x == r-1 && y == c-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = help(a, dp, x+1, y, r, c) + help(a, dp, x, y+1, r, c);
}

int main() {
    int n;
    cin>>n;
    while(n--){
        int r,c;
        cin>>r>>c;
        // input the array
        vector<vector<char>> a(r, vector<char>(c));
        for(int i = 0 ; i < r ; i++)
            for(int j = 0; j < c; j++) 
                cin>>a[i][j];
        
        vector<vector<int>> dp(r, vector<int>(c, -1));
        // start from 0, 0 and use dp to store answer
        int ans = help(a, dp, 0, 0, r, c);
        cout<<ans<<endl;
    }
    return 0;
}

