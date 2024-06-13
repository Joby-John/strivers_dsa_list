// follow up qn to print the index of the array elements that constitute the max subarray

#include<bits/stdc++.h>

using namespace std;

int kedan(vector<int>&nums)
{
    int n = nums.size();
    int max = nums[0];
    int sum = 0;
    int startIndex = -1; //for follow up qn
    int endIndex = -1;// for follow up qn

    for (int i = 0; i<n; i++){

        
        sum+=nums[i];

        if(sum>max){
            max = sum;
            endIndex = i; // for follow up qn
            
        }
        if(sum<0)
        {
            sum = 0;
            startIndex = i+1; // for follow up qn, as sum resets everytime when sum gets negative
        }
    }
    cout<< startIndex<<","<< endIndex<<endl;
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