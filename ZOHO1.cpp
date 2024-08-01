#include<bits/stdc++.h>

using namespace std;


void spiralDisplayer(vector<vector<int>>& matrix, int rows, int cols, vector<int>& result)
{
    int top = 0, bottom = rows-1, left = 0, right = cols-1;

    while(top<=bottom && left<=right)
    {
        //top row left to right

        for(int i = left; i<=right; i++)
        {
            //cout<<matrix[top][i]<<" ";
            result.push_back(matrix[top][i]);
        }
        top++;

        //top to bottom last column

        for(int i = top; i<= bottom; i++)
        {
            //cout<<matrix[i][right]<<" ";
            result.push_back(matrix[i][right]);
        }

        right--;

        //right to left
        
            for(int i = right; i>=left; i--)
            {
                //cout<<matrix[bottom][i]<<" ";
                result.push_back(matrix[bottom][i]);
            }
        bottom--;

        //bottom to top

            for(int i = bottom; i>=top; i--)
            {
                //cout<<matrix[i][left]<<" ";
                result.push_back(matrix[i][left]);
            }
        left++;   
    }
}
int main()
{
    int rows, cols;
    cin>>rows;
    cin>>cols;
    vector<vector<int>>matrix(rows, vector<int>(cols));
    vector<int>result;
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            cin>>matrix[i][j];
        }
    }

    spiralDisplayer(matrix, rows, cols, result);

    for(int elements:result)
    {
        cout<<elements<<" ";
    }
    return 0;
}
