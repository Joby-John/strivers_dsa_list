// -> given square matrix on size n.

// -> given directions
//     ->if direction makes rover outside grid rover shouldnt move.
//     -> else move.
// -> rover start from 0;
// -> at end of manuever return position
//     -> position = row*size-col.

// solution Thought:
// -> four boundaries :- top, right, bottom , left
//     -> top is 0, right is size-1, bottom is size-1, left is 0.
// ->I can use a matrix.
//     ->I can use a pair .
//         ->first for row, second for col.

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int moveRover(int n, vector<string>& directions)
    {
        int limit = n;
        pair<int,int>position = {0,0};

        for(int i = 0; i<directions.size(); i++)
        {
            if(directions[i] == "LEFT")
            {
                if(position.second-1 >= 0)
                {
                    position.second --;
                }
            }
            else if(directions[i] == "RIGHT")
            {
                if(position.second+1 < n)
                {
                    position.second++;
                }
            }
            else if(directions[i]=="UP")
            {
                if(position.first-1 >= 0)
                {
                    position.first --;
                }
            }
            else{
                if(position.first+1 < n)
                {
                    position.first++;
                }
            }
        }

        cout<<position.first<<","<<position.second<<endl;
        return position.first*n + position.second;
    }
};


int main()
{
    int n = 4;
    vector<string>commmands = {"RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN", "RIGHT", "UP"};
    Solution sol;
    
    cout<<sol.moveRover(n, commmands);
    return 0;
}