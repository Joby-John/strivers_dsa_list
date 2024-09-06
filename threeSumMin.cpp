// 259. 3Sum Smaller

// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

// Example:

// Input: nums = [-2,0,1,3], and target = 2
// Output: 2
// Explanation: Because there are two triplets which sums are less than 2:
//              [-2,0,1]
//              [-2,0,3]

// Follow up: Could you solve it in O(n2) runtime?


#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<vector<int>>ThreeSumSmaller(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<vector<int>>result;
        int count = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++)
        {
            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<target)
                {
                    for(int l=j; l<k;l++)
                    {
                        result.push_back({nums[i], nums[l], nums[k]});
                        count++;
                    }
                    
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        cout<<count<<endl;

        return result;
    }
};
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

    Solution sol;

    vector<vector<int>>result = sol.ThreeSumSmaller(nums, target);

    for(int i = 0; i<result.size(); i++)
    {
        cout<<"[";
        for(int j = 0; j<3; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"], ";
    } 
    return 0;
}