#include<bits/stdc++.h>

using namespace std;


    void superSetCreator(int ind , int n, vector<int> &nums, vector<int>& subSet, vector<vector<int>>&superSet )
    {

        // the logic for left path we have to emplace all until last index.
        // for right path, since we are certain levels up from previous left path insertion ,
        // we need to remove elements relative to the level 
        //like id 2nd last level remove last one element, if 3rd last remove 2 element
        //say on level 2 of 3 we should remove 1 element  

        //vector<int>subSet;
        if(ind == n)
        {
            superSet.emplace_back(subSet);

            return;
        }

            
        
        subSet.emplace_back(nums[ind]);
        //take element
        superSetCreator(ind+1, n, nums, subSet, superSet);

        //up to previous level and remove elements according to level. say if its level 1 0f 3 reoves 2 elements
        for(int i = ind; i<n; i++)
        {
            subSet.pop_back();
        }
        
        //not to take element
        superSetCreator(ind+1, n, nums, subSet, superSet);
        subSet.emplace_back(nums[ind]);
        


    }


    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
        //sort(nums.begin(), nums.end());

        vector<vector<int>>superSet;
        vector<int>subSet;

        superSetCreator(0, n, nums,subSet, superSet);
        
        return superSet; 
    }

int main()
{
    int n ;
    cin>>n;
    vector<int>theSet(n);

    for(int i = 0; i<n; i++)
    {
        cin>>theSet[i];
    }

    vector<vector<int>>superSet  = subsets(theSet);

    n = superSet.size();

    for(int i = 0; i<n; i++)
    {
        int m = superSet[i].size();
        cout<<"{";

        for(int j = 0; j<m; j++)
        {
            cout<<superSet[i][j];
        }
        cout<<"} ";
    }

    return 0;
}