#include<bits/stdc++.h>

using namespace std;


    int NcR(double n, double r)
    {
        double num = 1;
        double denom = 1;

        for(int i = 1; i<=r; i++)
        {
            num *= (n-r+i);
            denom *= i;
        }
        return num/denom;
    }

    int uniquePaths(int m, int n) {

        double N = m+n-2;
        double R = min(n-1,m-1);
        int paths;

        paths = NcR(N,R);
        return paths;
        
    }


    int main()
    {
        int rows, cols;
        cin>>rows;
        cin>>cols;

        int paths = uniquePaths(rows, cols);
        cout<<"The unique paths are : "<<paths;

    }