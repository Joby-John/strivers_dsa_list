#include<bits/stdc++.h>

using namespace std;

    vector<vector<int>> threeSum(vector<int>& nums) {

        //optimal
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        //[-2 -2 -1 -1 -1 0 0 0 2 2 2 2]

        for(int i = 0; i<n; i++)
        {
            if( i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j = i+1;
            int k = n-1;

            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                int oldJ = nums[j];
                int oldK = nums[k];

                if(sum<0)
                {
                    while(j<k && nums[j] == oldJ)
                    {
                        j++;
                    }

                }
                else if(sum>0)
                {
                    //k--
                    while(j<k && nums[k] == oldK)
                    {
                        k--;
                    }
                }
                else
                {
                   result.push_back({nums[i],nums[j],nums[k]});
                   while(j<k && nums[j] == oldJ)
                    {
                        j++;
                    }
                     while(j<k && nums[k] == oldK)
                    {
                        k--;
                    }

                }
            }
        }

        

        return result;

        //BETTER
        //1. nums[i]+nums[j]+nums[k] = 0
        //2. nums[k] = -(nums[i]+nums[j])
        //3. [-1,0,1,2,-1,-4] we take such that k from the middle of i and j
        //4. we store middle elements in a map and check for nums[k] as condition 2
        //5. sort and put in a set
        //6.for next element iter of i, we clear the map and restart as from 3
        //7. copy elements from set to vector

        // int n = nums.size();

        // set<vector<int>>uniqueSet;

        // for(int i = 0; i<n; i++)
        // {
        //     int first = nums[i];
        //     unordered_set<int>eleInBetween;
        //     for(int j = i+1; j<n; j++)
        //     {
        //         int second = nums[j];

        //         int third = -1*(first+second);

        //         if(eleInBetween.find(third)!=eleInBetween.end())
        //         {
        //             vector<int>temp = {first, second, third};
        //             sort(temp.begin(), temp.end());
        //            uniqueSet.insert(temp);
        //         }

        //         eleInBetween.insert(second);

        //     }
        // }

        // vector<vector<int>>result(uniqueSet.begin(), uniqueSet.end());

        // return result;

        //BRUTE
        // int n = nums.size();
        // set<vector<int>>st;

        // for(int i = 0; i<n; i++)
        // {
        //     int first = nums[i];
        //     for(int j = i+1; j<n; j++)
        //     {
        //         int second = nums[j];
        //         for(int k = j+1; k<n; k++)
        //         { 
        //             int third = nums[k];

        //             if(first+second+third == 0)
        //             {
        //                 vector<int>temp = {first, second, third};
        //                 sort(temp.begin(),temp.end());
        //                 st.insert(temp);
        //             }

        //         }
        //     }
        // }
        // vector<vector<int>>result(st.begin(), st.end());
        // return result;
        
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

        vector<vector<int>>result=threeSum(nums);

      cout<<"[";
        for(auto it:result)
        {
            cout<<"[";
            for(auto ele:it)
            {
            cout<<ele<<" ";
            }
            cout<<"], ";
        }
        cout<<"]";
    }