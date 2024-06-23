#include <bits/stdc++.h>
using namespace std;

    int maxLen(vector<int>&A, int n, int target)
    {   //better
    
    //[15,-2,2,-8,1,7,10,23]
    //target = 0
    //15 => to substract = 15 (15->0)
    //13 => to substract = 13 (13->1)
    //15 => to substract = 15 (15->0) //2
    //7 => to substarctt = 7 (7->3)
    //8 => to substarct = 8  (8->4)
    //15 => to substract = 15 (5)
    
    int sum = 0;
    //int target = 0;
    int maxLength = 0;
    
    unordered_map<long long, int>preSumMap;
    
    for(int i =0; i<n; i++)
    {
        sum += A[i];
        
        if(sum == target)
        {
            maxLength = max(i+1, maxLength);
        }
        int rem = sum-target;
        
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int len = i-preSumMap[rem];
            
            maxLength = max(len,maxLength);
        }
        else
        {
            preSumMap[sum] = i;
        }
        
        
    }
    return maxLength;
    
    
    
     
     
     
     
     
     
     
     
     
     
        
        // //brute
        // int sum;
        // int count;
        // int max = 0;
        // for(int i = 0; i<n; i++)
        // {
        //     sum = A[i]; 
        //     count = 1;
        //     if(sum == 0 && count>max)
        //         {
        //             max = count;
        //         }
            
        //     for(int j = i+1; j<n; j++)
        //     {
        //         sum+=A[j];
        //         count++;
                
        //         if(sum == 0 && count>max)
        //         {
        //             max = count;
        //         }
        //     }
        // }
        // return max;
    }


//{ Driver Code Starts.

int main()
{
    int n;
    int target;
    cin>>n;
    vector<int>nums(n);

    for(int i = 0; i<n; i++)
    {
       cin>>nums[i];
    }
    cin>>target;

    int max = maxLen(nums, n, target);
    cout<<max; 
    return 0; 
}



// } Driver Code Ends