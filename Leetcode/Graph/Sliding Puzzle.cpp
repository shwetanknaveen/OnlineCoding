//Problem link - https://leetcode.com/problems/sliding-puzzle/
class Solution {
public:
    vector<int> dir1 = {0 , 0, 1, -1};//right -> left -> down -> up
    vector<int> dir2 = {1, -1 ,0,  0};
    vector<vector<int>> lastState = {{1,2,3},{4,5,0}};
    bool isValid(vector<vector<int>> &board)//is this state the final state
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j] != lastState[i][j]) return false;
            }
        }
        return true;
    }
    pair<int,int> findZeroPos(vector<vector<int>> &board)//find the position of zero in the board
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==0) return {i,j};
            }
        }
        return {};
    }
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        set<vector<vector<int>>> visStates;
        queue<vector<vector<int>>> qu;
        visStates.insert(board);
        qu.push(board);
        int ans = 0;
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
                auto thisState = qu.front();
                qu.pop();
                
                if(isValid(thisState)) return ans;//if this state is the final state then this must be min ans as this is BFS
                
                pair<int,int> posOfZero = findZeroPos(thisState);
                int i = posOfZero.first, j= posOfZero.second;
                for(int x=0;x<4;x++)
                {
                    int adjI = i+dir1[x], adjJ = j+dir2[x];
                    if(adjI<0||adjI>=2||adjJ<0||adjJ>=3) continue;//this adjacent cell is not in board to swap
                    
                    swap(thisState[i][j],thisState[adjI][adjJ]);//swap with the adjacent cell
                    if(visStates.find(thisState)==visStates.end())//if this state after swapping is not previously visited
                    {
                        visStates.insert(thisState);//make it visited
                        qu.push(thisState);//push on the queue for processing
                    }
                    swap(thisState[i][j],thisState[adjI][adjJ]);//swap back so as to find other states of swapping with adjacent cells
                }
            }
            ans++;//on level of swapping with adjacent cells has been done
        }
        return -1;//not possible to reach the final state
    }
};
