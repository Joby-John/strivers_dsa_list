#include<bits/stdc++.h>

using namespace std;


    int paths = 0;
    int destRow;
    int destCol;


    int pathFinder(int robRow, int robCol, vector<vector<int>>&dp)
    {
        if(robRow == destRow && robCol == destCol)
        {
            return 1;
        }
        else if(robRow > destRow || robCol>destCol)
        {
            return 0;
        }
        if(dp[robRow][robCol]!=-1)
        {
            return dp[robRow][robCol];
        }
        else
        {
            dp[robRow][robCol] = pathFinder(robRow+1, robCol, dp)+pathFinder(robRow, robCol+1 , dp);
           return dp[robRow][robCol];
        }

        

    }
    int uniquePaths(int m, int n) {
        destRow = m-1;
        destCol = n-1;
        vector<vector<int>>dp(m, vector<int>(n, -1));

        int result = pathFinder(0,0, dp);

        return result;
        
    }

    int main()
    {
        int row, col;
        int possiblePaths;
        cin>>row;
        cin>>col;

        possiblePaths = uniquePaths(row, col);
        cout<<"unique travel path in a "<<row<<"x"<<col<<" matrix = "<<possiblePaths;
    }