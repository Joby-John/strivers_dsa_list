//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool comparator(struct Job j1, Job j2)
    {
        if(j1.profit>j2.profit)
        {
            return true;
        }
        else if(j1.profit<j2.profit)
        {
            return false;
        }
        // else
        // {
        //     if(j1.dead<j2.dead)
        //     {
        //         return true;
        //     }
        // }
        return false;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sort basedd on deadline
        sort(arr, arr+n, comparator);
        int maxi = arr[0].dead;
        
        for(int i = 1; i<n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        
        int profit = 0;
        int jobs = 0;
        vector<int>slots(maxi, -1);
        
        // for(int i = 0; i<n; i++)
        // {
        //     cout<<"("<<arr[i].id<<","<<arr[i].dead<<","<<arr[i].profit<<")";
        // }
        // cout<<endl;
        
        for(int i = 0; i<n; i++)
        {
            int deadLine = arr[i].dead-1;
            
            for(int j = deadLine; j>=0; j--)
            {
                if(slots[j]!=-1)
                {
                    continue;
                }
                else
                {
                    slots[j] = arr[i].id;
                    profit+=arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        
        // for(int i = 0; i<maxi; i++)
        // {
        //     cout<<slots[i]<<" ";
        // }
        // cout<<endl;
        
        return {jobs, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends