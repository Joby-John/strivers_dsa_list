#include<bits/stdc++.h>

using namespace std;


    int lengthOfLongestSubstring(string s) {
        //best :-map

        int n = s.length();

        int l = 0;
        int r = 0;

        int start = 0; // to print string
        int end = 0;
        unordered_map<char, int> dupLetterIndex;

        int length = 0;
        int maxLength = 0;

        while(r<n)
        {
            if(dupLetterIndex.find(s[r])!=dupLetterIndex.end())
            {
                l = max(l,dupLetterIndex[s[r]]+1);
            }
            length = r-l+1;
            if(length>maxLength)
            {
               maxLength =  length;
               start = l; // start of maxString
               end = r; //end of maxString
            }
            dupLetterIndex[s[r]] = r;
            r++;
            int end = r;
        }

        //printing maxString
        cout<<"Max String : ";
        for(int i = start; i<=end; i++)
        {
            cout<<s[i];
        }
        cout<<endl;

        return maxLength;

         //better:-sliding window
        // int n = s.length();
        // unordered_set<int>letters;

        // int l = 0;
        // int r = 0;
        // int currLength = 0;
        // int maxLength = 0;

        // while(r<n)
        // {
        //     while(letters.find(s[r])!=letters.end())
        //     {
        //         letters.erase(s[l]);
        //         l++;
        //     }
        //     currLength = r-l+1;
        //     maxLength = max(currLength, maxLength);
        //     letters.insert(s[r]);
        //     r++;

        // }
        // return maxLength;

        // int n = s.length();
        // int count = 0;
        // int maxLength= 0;
        // unordered_set<int>letters;

        // for(int i = 0; i<n; i++)
        // {
        //     count = 0;
        //     letters.clear();

        //     for(int j = i; j<n; j++)
        //     {
        //         if(letters.find(s[j]) == letters.end())
        //         {
        //             count++;
        //             maxLength = max(maxLength, count);
        //             letters.insert(s[j]); 
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        // }

        // return maxLength;
        
    }


int main()
{

    string anyString;
    cin>>anyString;
    int result = lengthOfLongestSubstring(anyString);
    cout<<"Length : "<<result;
    return 0;
}