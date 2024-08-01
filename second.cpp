#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s; 
    cin>>s;
    int n = s.length();
    vector<int>numbers;
    vector<string>operators;

    string num = "";

    for(int i = 0; i<n; i++)
    {
        if(s[i] != '+' && s[i] != '*' && s[i] !='/' && s[i]!='-')
        {
            num = num+s[i];
        }
        else{
            numbers.push_back(stoi(num));
            num = "";
            string symbol;
            symbol = s[i];
            operators.push_back(symbol);
        }

    }
    numbers.push_back(stoi(num));


}