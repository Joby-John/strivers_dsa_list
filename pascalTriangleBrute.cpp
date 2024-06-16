#include<bits/stdc++.h>

using namespace std;


int findNcR(int n, int c)
{
    //n = 4
    //c=0
   int num = 1; // 4
   int denom = 1; // 0
  for(int i = 0; i<c; i++)
  {
      num*=n-i;//4*3
      denom*=c-i;//2*1
  }

  return num/denom;
}
int pascalTriangleElement(int row, int col)
{
    //to find the combination
   return findNcR(row-1, col-1);
}

void pascalTriangleRow(int row)
{
    int n = row-1;//3
    int r = row-1;//3
    for(int i = 0; i<=n; i++)
    {
        cout<<(findNcR(n, 0+i))<<" ";
    }
    cout<<endl;
}

void pascalTriangle(int n)
{
    for(int row = 1; row<=n; row++ )
    {
        pascalTriangleRow(row);
    }
}

int main()
{
    int row, col;
    cin>>row;
    cin>>col;

    //cout<<pascalTriangleElement(row, col)<<endl;
    pascalTriangle(row);


}