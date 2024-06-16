#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeInts(vector<vector<int>>& intervals) {

        
        sort(intervals.begin(), intervals.end());

        int j = 0;
        int i = 1;

        while(i<intervals.size()) // bc the size of array changes as i delete array elements while in loop
        {
            if(intervals[j][1]>=intervals[i][0])
            {
                intervals[j][1] = max(intervals[j][1],intervals[i][1]);
                intervals.erase(intervals.begin()+i);
            }
            else{
                i++;
                j++;
            }
        }

        return intervals;
        
    }


    int main()
    {
        vector<vector<int>>qn = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
        vector<vector<int>>result;

        result = mergeInts(qn);

        for(int i = 0; i<result.size(); i++)
        { 
            for(int j = 0; j<2; j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }