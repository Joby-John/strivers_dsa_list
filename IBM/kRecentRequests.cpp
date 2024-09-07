// -> given n request ids and an integer k.
// -> find k most recent requests, also skip already counted ids.

// ie eg: 
//  suppose n = 5
//  requests = ["item1", "item2", "Item3", "item1", "item3"]
//  and k = 3
//  o/p = ["item3", "item1", "item2"], we skipped second item3 as its already in there.


//  solution thought:
//  -> we can use a set to iterate from last and till set.size()==k

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string>getLatestKOrders(vector<string>orders, int k)
    {
        int n = orders.size();

        set<string>uniqueLatestOrders;
        vector<string> latestOrders;

        int i = n-1;
        while(i>=0)
        {
            if(uniqueLatestOrders.find(orders[i])==uniqueLatestOrders.end())
            {
                uniqueLatestOrders.insert(orders[i]);
                latestOrders.push_back(orders[i]);
            }

            if(uniqueLatestOrders.size()>=k)
            {
                break;
            }
            i--;
        }

        

        return latestOrders;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string>orders(n);
    for(int i = 0; i<n; i++)
    {
        cin>>orders[i];
    }
    int k;
    cin>>k;

    Solution sol;
    vector<string> result = sol.getLatestKOrders(orders, k);

    for(int i = 0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;
}