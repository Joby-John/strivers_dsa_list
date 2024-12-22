#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void stringReverser(string& sentence)
    {
        int left = 0; 
        int right = sentence.size()-1;

        while(left<right)
        {
            swap(sentence[left], sentence[right]);
            left++;
            right--;
        }

        cout<<sentence;
    }
};

int main()
{
    string sentence = "This is a sample test.";
    Solution sol;
    sol.stringReverser(sentence);
    return 0;
}