#include<bits/stdc++.h>

using namespace std;


void pascalTriangleRow(int row)
{
    int element;
    
    for(int i = 0; i<row; i++)
    {
        if(i == 0)
        {
            cout<<1<<" ";
            element = 1;
        }
        else{
            element = (element*(row-i))/i;
            cout<<element<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int rows;
    cin>>rows;

    for(int i = 1; i<=rows; i++)
    {
        pascalTriangleRow(i);
    }

    return 0;
}