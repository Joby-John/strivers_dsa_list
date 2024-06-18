#include<bits/stdc++.h>

using namespace std;

    int findDuplicate(vector<int>& nums) {

        //The round race method(linked list)
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);

        fast = nums[0];

        while(fast!=slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

        //extra array :- brute but better time
        //[1,3,4,2,2] , size 
        // int extra;
        // vector<int>repeatRegister(nums.size()+1, 0);
        

        // for(int i = 0; i<nums.size(); i++)
        // {
        //     repeatRegister[nums[i]] += 1;
        //     if(repeatRegister[nums[i]]>1)
        //     {
        //         extra = nums[i];
        //     } 
        // }
        // return extra;


        //Brute:- hashing
        //iterate and add to hash when count for specific element gets greater than 1 break and return 

        // unordered_map<int, int>numMap;
        // int extra;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     numMap[nums[i]]+=1;
        //     if(numMap[nums[i]]>1)
        //     {
        //         extra = nums[i];
        //         break;
        //     }
        // } 
        // return extra;


        // Better approach:- sorting and linear iteration (i and i+1 comparison)
        // int n = nums.size();
        // int extra;
        
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i<n-1; i++)
        // {
        //     extra = nums[i];
        //     if(extra == nums[i+1])
        //     {
        //         break;
        //     }
        //     else
        //     {
        //         extra = nums[i+1];
        //     }
        // }
        // return extra;
        
    }


int main()
{
    int n;
    vector<int>nums(n);
    cin>>n;

    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }

    cout<<findDuplicate(nums);
}