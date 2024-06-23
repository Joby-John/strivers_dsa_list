#include<bits/stdc++.h>

using namespace std;


int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int max = 0;

        if(n==0)
        {
            return 0;
        }

        unordered_set<int>uniqueNums;

        for(int i = 0; i<n; i++)
        {
            uniqueNums.insert(nums[i]);
        }

        for(auto it:uniqueNums)
        {
            if(uniqueNums.find(it-1) == uniqueNums.end())
            {
                int num = it;
                int count = 1;
    
                while(uniqueNums.find(num+1) != uniqueNums.end())
                {
                    count++;
                    num = num+1;

                }
                if(max<count)
                    {
                        max = count;
                    }
            }
        }

        return max;

        



        //[1,2,3,4,100,200]

        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // int currSmall = INT_MIN;
        // int count = 0;
        // int max = 0;

        // for(int i = 0; i<n; i++)
        // {
        //     //0, 1,1
        //     if(nums[i]-1 == currSmall)
        //     {
        //         count++;
        //         currSmall = nums[i];
        //         if(max<count)
        //         {
        //             max = count;
        //         } 
        //         //count = 2
        //         //currSmall = 1
        //     }

        //     //[0,1,1,2]
        //     else if(nums[i]!=currSmall)
        //     {
        //         //currSmall = 0
        //         //count = 1
        //         count = 1;
        //         if(max<count)
        //         {
        //             max = count;
        //         } 
                
        //         currSmall = nums[i];
        //     }
        // }

        // return max;

        
    }

    int main()
    {
        int n ;
        int result;
        cin>>n;
        

        vector<int>nums(n);

        for(int i = 0; i<n; i++)
        {
            cin>>nums[i];
        }
        result = longestConsecutive(nums);
        cout<<"Length of longest consecutive sequence: "<<result;

        return 0;
    }