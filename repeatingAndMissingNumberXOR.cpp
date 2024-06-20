#include<bits/stdc++.h>

using namespace std;

//[4,3,6,2,1,1] [1,2,3,4,5,6]
//1^5 = 001^101 = 100 = 4, 
//number = 4&(~(4-1)) => 100&100 = 100
// 0 - class, 1- class
// without 0- class 1n, 1-class
// zero in nums => repeating, one =>missing
// zero not in nums => missing. one repeating

void RepeatingAndMissing(vector<int>&nums)
{
  int n = nums.size();
  int xr = 0;
  int zero = 0;
  int one = 0;

  for(int i = 0; i<n; i++)
  {
     xr = xr^nums[i];
     xr = xr^(i+1);
  }

  

  int number = xr&(~(xr-1));

  for(int i = 0; i<n; i++)
  {
    //one class
    if((nums[i] & number) != 0)
    {
        one ^= nums[i];
    }
    else{
        zero ^= nums[i];
    }

    if(((i+1) & number) != 0)
    {
        one ^= (i+1);
    }
    else{
        zero ^= (i+1);
    }
  }

  int count = 0;

  for(int i = 0; i<n; i++)
  {
    if(nums[i] == zero)
    {
        count++;
        break;
    }
  }

  if(count>0)
  {
    cout<<"missing: "<<one<<endl;
    cout<<"repeating: "<< zero<<endl;
  }
  else
  {
    cout<<"missing: "<<zero<<endl;
    cout<<"repeating: "<<one<<endl;
  }
}


int main()
{
    int n ;
    cin>>n;

    vector<int>nums(n);

    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }

    RepeatingAndMissing(nums);
    return 0;
}