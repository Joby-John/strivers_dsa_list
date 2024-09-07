// ->traingle sides are given as string inside a vector
//     -> if isosceles or equilateral push that name to corresponding place.
//     -> if couldnt form or none of these, push none of these.


// solution thought
//  -> for each triangle take max, 
//     ->then do other two side sum - max if its greater 1 its triangle.
//         -> if all three sides are equal its equilateral.
//         ->if two side equal isosceles
//         -> else none of these.
//     ->else none of these.
    
#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> triangleType(vector<string>& dimensions)
    {
        vector<string>result;
        int n = dimensions.size();
        for(int i = 0; i<n; i++)
        {
            vector<int>sides;
            int side;
            stringstream sideString (dimensions[i]);
            while(sideString>>side)
            {
                sides.push_back(side);
            }

            if(sides.size() != 3)
            {
                result.push_back("None of these");
                continue;
            }
            

            if(sides[0]+sides[1]<sides[2] || sides[0]+sides[2]<sides[1] || sides[1]+sides[2]<sides[0])
            {
                result.push_back("None of these");
                continue;
            }
            else if((sides[0] == sides[1]&& sides[1] == sides[2]))
            {
                result.push_back("Equilateral");
                continue;
            }
            else if(sides[0] == sides[1] || sides[1]==sides[2]||sides[2]==sides[0])
            {
                result.push_back("Isoceles");
                continue;
            }
            else
            {
                result.push_back("None of these");
            }
        }

        return result;
        
    }
};


int main()
{
    // int n;
    // cin>>n;
    vector<string>sides = {"2 2 1", "3 3 3", "3 4 5", "1 1 3"};

    Solution sol;
    // for(int i = 0; i<n; i++)
    // {
    //     cin>>sides[i];
    // }

    vector<string> result = sol.triangleType(sides);

    for(string type:result)
    {
        cout<<type<<",";
    }

    return 0;
}