// -> given a string pwd, which contain binary characters
// -> minimum number of changes to make it secure
//     ->to make it secure
//         -> pwd should be divided to even lengthed substrings
//         ->each entire substring should conatin either entire 1 or 0 not a mix
// -> inorder to divide in such a way how many minimum flips should be made.

// solution Thought
// -> what we do is we consider pairs(given qn conditions are met iff total size is even).
// -> we take first pair check if mixed if mixed then we flip once(just add to flip count).
//     ->else just avoid (no incrementing the flip counter)


#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int minFlips(string& pwd)
    {
        int n = pwd.length();

        if(n%2 != 0)
        {
            return -1; //as it can't be divided to non overlapping even intervals
        }

        int i = 1;
        int flipCounter = 0;
        while(i<n)
        {
            if(pwd[i]=='1'&&pwd[i-1]=='0' || pwd[i]=='0'&&pwd[i-1]=='1')
            {
                flipCounter++;
            }

            i+=2;
            
        }

        return flipCounter;
    }

};

int main()
{
    Solution sol;
    string pwd;
    cin>>pwd;
    int result = sol.minFlips(pwd);
    cout<<result;
    return 0;
}