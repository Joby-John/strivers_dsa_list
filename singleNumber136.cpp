#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {

        int n = nums.size();
        int xor1 = 0;

        for(int i = 0; i<n; i++)
        {
            cout<<xor1<<"^"<<nums[i]<<" = ";
            xor1 ^= nums[i];
            cout<<xor1<<endl;
        }

        return xor1;
        
    }

    int main()
    {
        int size;
        cin>>size;
        vector<int>nums(size);

        for(int i = 0; i<size; i++)
        {
            cin>>nums[i];
        }

        singleNumber(nums);
         
       return 0;
    }