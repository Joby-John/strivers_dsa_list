#include<bits/stdc++.h>

using namespace std;

void NextPermutation(vector<int>&nums){

    int n = nums.size();
    int swappingPos = -1;

    for(int i = 1; i<n-1; i++)
    {
        if(nums[i-1]<nums[i])
        {
            swappingPos = i-1;
        }
    }

    if(swappingPos!=-1)
    {
        int nextMin = swappingPos+1; 
        for(int j = swappingPos+1; j<n; j++)
        {
            if(nums[j]>nums[swappingPos] && nums[j]<=nums[nextMin])
            {
                nextMin = j;
            }
        }

        swap(nums[nextMin], nums[swappingPos]);
        reverse(nums.begin()+swappingPos+1, nums.end());
    }

    else{
        reverse(nums.begin(), nums.end());
    }

    for(auto it:nums)
    {
       cout<<it<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);

    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }

    NextPermutation(nums);
}