//Problem link - https://www.interviewbit.com/problems/maximum-area-of-triangle/
//Self video explanation - https://youtu.be/_hJMyZ3yl58
int Solution::solve(vector<string> &A) {
    int rows = A.size(),cols = A[0].size();
    map<char,int> maxRow[cols],minRow[cols],maxCol,minCol;
    
    /*When we save maxRow and minRow for any character, we do it column wise because base of the triangle can be in any particular
    column at a time. Hence we declare maxRow and minRow as array of maps so as to accomodate values separately for each column.
    maxCol or minCol for any character will be required when we will be calculating maxHeight of the triangle and looking for third 
    vertex and hence it can be anywhere in the matrix and has nothing to do with certain column hence maxCol and minCol are simple maps
    and not array of maps*/
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            maxRow[j][A[i][j]] = max(maxRow[j][A[i][j]],i);
            if(minRow[j].count(A[i][j]))//since default value of minRow[j][A[i][j]] is 0 and i>=0 hence if we directly update minRow[j][A[i][j]]
            							//without checking that whether it exists or not, it will always remain 0 because min(minRow[j][A[i][j]],i);
            							//will always give 0
            {
                minRow[j][A[i][j]] = min(minRow[j][A[i][j]],i);
            }
            else//If minimum value is not existing then whatever value this is for this character, it has to be minimum as of now
            {
                minRow[j][A[i][j]] = i;
            }
            maxCol[A[i][j]] = max(maxCol[A[i][j]],j);
            if(minCol.count(A[i][j]))//since default value of minCol[A[i][j]] is 0 and j>=0 hence if we directly update minCol[A[i][j]]
            							//without checking that whether it exists or not, it will always remain 0 because min(minCol[A[i][j]],j);
            							//will always give 0
            {
                minCol[A[i][j]] = min(minCol[A[i][j]],j);
            }
            else//If minimum value is not existing then whatever value this is for this character, it has to be minimum as of now
            {
                minCol[A[i][j]] = j;
            }
        }
    }
    int ans = 0;
    for(int col = 0;col<cols;col++)//let's check that in which column, the base of triangle can lie so as to maximise the area
    {
        int maxBase,maxHeight;
        //When we are checking that maxRow[col]['r'] exists or not we are also implicitly checking that minRow[col]['r'] exists or not
        //because the way we have set max and min values for certain character, if one value is set, other must has been set
        
        //R,G as base vertices and B as third vertex
        if(maxRow[col].count('r') and maxRow[col].count('g') and maxCol.count('b'))
        {
            maxBase = max(abs(maxRow[col]['r']-minRow[col]['g']),abs(minRow[col]['r']-maxRow[col]['g']))+1;
            maxHeight = max(abs(col-maxCol['b']),abs(col-minCol['b']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
        //G,B as base vertices and R as third vertex
        if(maxRow[col].count('g') and maxRow[col].count('b') and maxCol.count('r'))
        {
            maxBase = max(abs(maxRow[col]['g']-minRow[col]['b']),abs(minRow[col]['g']-maxRow[col]['b']))+1;
            maxHeight = max(abs(col-maxCol['r']),abs(col-minCol['r']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
        //B,R as base vertices and G as third vertex
        if(maxRow[col].count('b') and maxRow[col].count('r') and maxCol.count('g'))
        {
            maxBase = max(abs(maxRow[col]['b']-minRow[col]['r']),abs(minRow[col]['b']-maxRow[col]['r']))+1;
            maxHeight = max(abs(col-maxCol['g']),abs(col-minCol['g']))+1;
            ans = max(ans,maxBase*maxHeight);
        }
    }
    return ceil(ans/2.0);
}

