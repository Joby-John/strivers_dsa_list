#include<bits/stdc++.h>

using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int col0 = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;

                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        // for(int i = 0; i<rows; i++)
        // {
        //     for(int j = 0; j<cols; j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // across the row
        for (int j = 1; j < cols; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // down the column
        for (int i = rows - 1; i >= 0; i--) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // above both combined:-

        // for(int i = 1; i<rows; i++)
        // {
        //     for(int j = 1; j<cols; j++)
        //     {
        //         if(matrix[0][j]==0 || matrix[i][0]==0)
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // if(matrix[0][0] == 0)
        // {
        //     for(int j = 0; j<cols; j++)
        //     {
        //         matrix[0][j] = 0;
        //     }
        // }
        if (col0 == 0) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }


    int main()
    {
        int rows, cols;
        cin>>rows;
        cin>>cols;

        vector<vector<int>>matrix(rows, vector<int>(cols));
        //vector<vector<int>>result(rows, vector<int>(cols));

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
              cin>>matrix[i][j];
            }
        }

        setZeroes(matrix);

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
              cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

        return 0;
    }