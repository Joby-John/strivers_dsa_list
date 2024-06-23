#include<bits/stdc++.h>

using namespace std;


    vector<vector<int>> fourSum(vector<int>& nums, int target) {



        //4sum = 3sum+1
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;

        for(int i = 0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j = i+1; j<n; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
               int k = j+1;
               int l = n-1;

               while(k<l)
               {
                  long sum = long(nums[i])+nums[j]+nums[k]+nums[l];

                  int oldK = nums[k];
                  int oldL = nums[l];


                  if(sum<target)
                  {
                    while(k<l && nums[k]==oldK)
                    {
                        k++;
                    }
                  }

                  else if(sum>target)
                  {
                    while(k<l && nums[l]==oldL)
                    {
                        l--;
                    }

                  }
                  else
                  {
                    vector<int>temp = {nums[i], nums[j], nums[k], nums[l]};
                    result.emplace_back(temp);

                    while(k<l && nums[k]==oldK)
                    {
                        k++;
                    }

                    while(k<l && nums[l]==oldL)
                    {
                        l--;
                    }


                  }
               }

            
               
            }
        }

        return result;

        // int n = nums.size();
        // //sort(nums.begin(), nums.end());
        // set<vector<int>>uniqueSet;

        // for(int i = 0; i<n; i++)
        // {
        //     for(int j = i+1; j<n; j++)
        //     {
        //         for(int k = j+1; k<n; k++)
        //         {
        //             for(int l=k+1; l<n; l++)
        //             {
        //                 long sum = long(nums[i])+nums[j]+nums[k]+nums[l];

        //                if(sum == target)
        //                {
        //                 vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
        //                 sort(temp.begin(),temp.end());
        //                 uniqueSet.insert(temp);
        //                }
        //             }
        //         }
        //     }
        // }

        // vector<vector<int>>result(uniqueSet.begin(), uniqueSet.end());

        // return result;
        
    }

    int main()
    {
        int n;
        int target;
        cin>>n;
        vector<int>nums(n);

        for(int i = 0; i<n; i++)
        {
           cin>>nums[i];
        }
        cin>>target;

        vector<vector<int>>result=fourSum(nums, target);

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
