#include<bits/stdc++.h>

using namespace std;


void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        int rotations = k%length;
        vector<int>temp(rotations);
        int j = 0;

        for(int i = length-rotations; i<length; i++)
        {
           temp[i-(length-rotations)]=nums[i]; // we could use j but mathematically we could get 0,1,2.. by i-(length - rotations) eg:- 3-3=0, 4-3=1, 5-3=2
           j++;
        }

        for(int i = length-rotations-1; i>=0; i--)
        {
            nums[i+rotations] = nums[i];
        }

        for(int i = 0; i<rotations; i++)
        {
            nums[i] = temp[i];
        }

        for(int i = 0; i<length; i++)
        {
            cout<<nums[i]<<" ";
        }
    }

    int main()
    {
        int size;
        cin>>size;
        vector<int> arr(size);
        int k;

        for(int i = 0 ;i<size; i++)
        {
            cin>>arr[i];
        }

        cin>>k;

        rotate(arr, k);
    }