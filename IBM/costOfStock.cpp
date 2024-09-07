// -> the price of stock of each day is given in array.
// -> want to buy stock triplets such that sum of cost of three days is divisible by d.
// -> goal is to find number of distinct triplets.

// solution Thought
// ->could use a O(n3)
// ->could reduce to O(n2) using map, storing each number and looking for 

#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int countTriplets(vector<int>& prices, int d)
    {
        int count = 0;
        int n = prices.size();

        for(int i = 0; i<n-2; i++)
        {
            unordered_map<int,int>middleElements;
            for(int j = i+1; j<n; j++)
            {
                int requiredElement = (d-(prices[i]+prices[j])%d)%d;

                if(middleElements.find(requiredElement)!=middleElements.end())
                {
                    count++;
                }
                
                middleElements[prices[j]]++;
            }
        }

        return count;
    }

};

int main()
{
    Solution sol;
    int n;
    int d;
    cin>>n;


    vector<int>prices(n);

    for(int i = 0; i<n; i++)
    {
        cin>>prices[i];
    }

    cin>>d;

    int result = sol.countTriplets(prices, d);
    cout<<result;
    return 0;
}