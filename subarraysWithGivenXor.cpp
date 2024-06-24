#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B) {
    
    int n = A.size();
    unordered_map<int, int>previousXORS;
    int xr = 0;
    int count = 0;
    
    //x^k = xr
    //x = xr^k
    
    previousXORS[0]+=1; //adding default for B's
    for(int i = 0; i<n; i++)
    {
        xr = xr^A[i];
        int x = xr^B;
        if(previousXORS.find(x) != previousXORS.end())
        {
            count += previousXORS[x];
        }
        previousXORS[xr]+=1;
    }
    return count;
    
    
    // int n = A.size();
    // int xr = B;
    // int count = 0;
    
    
    // for(int i = 0; i<n; i++)
    // {
        
    //     for(int j = i; j<n; j++)
    //     {
    //         xr ^= A[j];  
        
    //         if(xr == 0)
    //         {
                
    //             count++;
    //         }
    //     }
    //     xr = B;
    // }
    // return count;
}


int main()
{
    int n;
    int equalityXor;
    int result;
    cin>>n;

    vector<int>nums(n);

    for(int i = 0; i<n; i++)
    {
       cin>>nums[i];
    }
    cin>>equalityXor;
    result = solve(nums, equalityXor);

    cout<<result;



    return 0;
}