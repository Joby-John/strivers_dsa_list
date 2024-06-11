#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            int compliment = target - nums[i];
            if(numMap.count(compliment))
            {
                return {i, numMap[compliment]};
            }
            numMap[nums[i]] = i; // key:value , value:index
        }

        return {};
        
    }

    int main()
    {

        int n;
        int target;
        cin>>n;
        vector<int>nums(n);
        

        for( int i = 0 ; i<n ; i++)
        {
            cin>>nums[i];
        }
        cin>>target;
        
        vector<int>result = twoSum(nums, target);

        for ( int i = 0; i<result.size(); i++ )
        {
            cout<<result[i]<<" ";
        }
        
        return 0;
    }