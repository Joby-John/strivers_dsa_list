// -> takes a number that specifies how many times transformation needed to occur.
// -> here we take the number of elements as number of transformation
// -> on each transformation we add 3 if number is odd.
//     ->else we substract 3


// solution approach
// -> say we have even number of element then we need to do even number of transformation.
//     ->on even number of transformation as we are not cahnging the added and subtracted number it will eventual be the same array only
// -> for odd we have to do only a single transformation.

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int>oddEvenTranformation(vector<int>& nums)
    {
        int n = nums.size();

        if(n%2==0)
        {
            return nums;
        }
        else
        {
            for(int i = 0; i<n; i++)
            {
                if(nums[i]%2 == 0)
                {
                    nums[i] -= 3;
                }
                else
                {
                    nums[i] += 3;
                }
            }
            return nums;
        }
    }
        

};


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    Solution sol;

    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }

    vector<int>result = sol.oddEvenTranformation(nums);

    for(int i = 0; i<n; i++)
    {
        cout<<result[i]<<" ";
    } 

    return 0;

}