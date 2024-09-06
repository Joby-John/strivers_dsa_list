#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int  n = nums.size();
        vector<vector<int>>triplets;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j = i+1; 
            int k = n-1;

            
            while(j<k)
            {
            
                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0)
                {
                    triplets.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
            
        }

        return triplets;

        
    }
};

int main() {
    vector<int> nums = {2, -1, -1, 3, -1};
    
    // Create an instance of Solution class
    Solution sol;
    
    vector<vector<int>> ans = sol.threeSum(nums);

    cout<<"[";
    
    // Print the result
    for (auto& triplet : ans) {
        cout << "[";
        for (auto& num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout<<"]";
    cout << "\n";
    
    return 0;
}
