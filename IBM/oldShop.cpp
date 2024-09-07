// -> given product and actual prices.
// -> also product sold and soldPrices
// -> we ahve to determine how many sold price is different from actual price.

// solution thought
// ->use a map to store actual product and price.
// ->check on that map with sold item and sold prices if different add 1 to error count;

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int errorDetection(vector<string>& products, vector<double>& productPrices, vector<string>& productSold, vector<double>& soldPrice)
    {
        int n = products.size();

        unordered_map<string, double>actualPrices;
        for(int i = 0; i<n; i++)
        {   
            actualPrices[products[i]] = productPrices[i];
        }

        int errorCount = 0;

        for(int i = 0; i<productSold.size(); i++)
        {
            
                if(actualPrices[productSold[i]]!=soldPrice[i])
                {
                    errorCount++;
                }
               
        }

        return errorCount;
    }
};

int main()
{

    vector<string>products ={"eggs", "milk", "cheese"};
    vector<double>productPrices = {2.89, 3.29, 5.79};
    vector<string>productSold = {"eggs", "eggs", "cheese", "milk"};
    vector<double> soldPrice = {2.89, 2.99, 5.79, 3.39};

    Solution sol;
    cout<<sol.errorDetection(products, productPrices, productSold, soldPrice);
    return 0;
}