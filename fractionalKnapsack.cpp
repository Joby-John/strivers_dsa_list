//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
class Solution {
    
    static bool comparator(struct Item it1, Item it2) {
        double r1 = (double)it1.value / (double)it1.weight;
        double r2 = (double)it2.value / (double)it2.weight;
        return r1 > r2;
    }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // sort by density => value/weight
        
        sort(arr, arr+n, comparator);
        double totalProfit = 0;
        double currWeight = 0;
        double itemWeight  = 0;
        double itemProfit = 0;
        
        for(int i = 0; i<n; i++)
        {
            itemWeight = arr[i].weight;
            itemProfit = arr[i].value;
            
            if(currWeight+itemWeight>w)
            {
                break;
            }
            else
            {
                currWeight += itemWeight;
                totalProfit += itemProfit;
            }
            itemWeight = 0;
            itemProfit = 0;
        }
        
        if(currWeight+itemWeight > w)
            {
                double fractWeight = (w - currWeight)/itemWeight;
                double totalWeight = currWeight+ fractWeight;
                
                if(totalWeight<=w)
                {
                    totalProfit += fractWeight*itemProfit;
                }
            }
            
            return totalProfit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends