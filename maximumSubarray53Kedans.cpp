#include<bits/stdc++.h>

using namespace std;

int kedan(vector<int>&nums)
{
    int n = nums.size();
    int max = nums[0];
    int sum = 0;

    for (int i = 0; i<n; i++){
        sum+=nums[i];

        if(sum>max){
            max = sum;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }
    return max;
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

    int result = kedan(nums);
    cout<<result;
}