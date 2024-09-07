// -> provided a string word, in one move can choose any index
// -> lets say we select c of the given string.
//     ->what we want to do is select first index to the left of current index that conatin c
//     -> and also to the right and delete both.
// -> what we are to return is the minimum move to acheive minimum length
// -> and the result should be like no repeated characters.

// solution Thought
// -> we can use hashmap to store occurance of a character.
//     ->if found in the hashmap we delete that occurance and replace it with current index.
//     -> also we iterate to front and delete first find in right


#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int minLength(string& word)
    {
        int moves = 0;
        int n = word.length();
        unordered_set<char>previousOccurance;
        for(int i =0; i<n; i++)
        {
            if(previousOccurance.find(word[i])!=previousOccurance.end())
            {
                moves++;
                previousOccurance.erase(word[i]);
            }
            else
            {
                previousOccurance.insert(word[i]);
            }
            
        }
        return moves;
    }
};

int main()
{
    string word;
    cin>>word;
    Solution sol;
    cout<<sol.minLength(word);
    return 0;
}