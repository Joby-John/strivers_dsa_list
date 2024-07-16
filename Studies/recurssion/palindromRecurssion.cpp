#include<bits/stdc++.h>

using namespace std;

bool palindrome(string in, int i, int n)
{
    if(i>=n/2)
    {
        return true;
    }

    if(in[i] == in[n-1-i])
    {
        return palindrome(in, i+1, n);
    } 
    else{
        return false;
    }
    
}

int main()
{
    string in, out;
    cin>>in;
    int n;
    n = in.length();

    bool output = palindrome(in, 0, n);
    if(output)
    {
        cout<<in<<" is a palindrome";
    }
    else{
        cout<<in<<" is not a palindrome";
    }

    return 0;
}