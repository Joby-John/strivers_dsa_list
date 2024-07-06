//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void calculateSum(int ind, int sum, vector<int> &arr, int n, vector<int> &sumArray)
    {
        if(ind == n)
        {
            sumArray.push_back(sum);
            return;
        }
        
        //taking element
        calculateSum(ind+1, sum+arr[ind], arr, n, sumArray);
        //not taking element
        calculateSum(ind+1, sum, arr, n, sumArray);
        
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>sumArray;
        
        calculateSum(0, 0, arr, n, sumArray);
        
        return sumArray;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends