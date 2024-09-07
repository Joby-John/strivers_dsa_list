#include<bits/stdc++.h>

using namespace std;

// ->for each element of an array , a counter is set to 0.
// -> the element is compared to each element to its left
//     ->if element to left is greater the absolute difference is substracted from counter
//     -> if element to left is less absolute difference is added
// -> for each element in the array repeat this steps and return the counter array

// solution thought
// -> need an extra array with initial set to 0
// -> let counter[0] remain 0 as nothing is left to 0.
// -> if i greater than 0, do a loop till left 

// -> no need of abs function as any way if greater is substarcted from smaller itll be negative.
//     -> like wise if smaller substarcted from greater itll be positive.
// ->all you have to do is add it to correct index of the counter array

class Solution{
public:
    vector<int>absDiffrences(vector<int>& nums)
    {
        int n = nums.size();

        vector<int>result(n, 0);

        if(n<1)
        {
            return result;
        }

        int prefixSum = 0;
        
        //iterating through the array
        for(int i = 1; i<n; i++)
        {   
            prefixSum += nums[i-1];

            result[i] = i*nums[i]-prefixSum;
            
        }

        return result;
    }
};

int main()
{
    int n;
    vector<int>nums;
    cin>>n;

    Solution sol;

    for(int i = 0; i<n; i++)
    {
        int num;
        cin>>num;
        nums.push_back(num);
    }

    vector<int> result = sol.absDiffrences(nums);

    for(int i = 0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}