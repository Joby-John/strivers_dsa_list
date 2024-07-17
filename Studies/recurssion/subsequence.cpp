#include<bits/stdc++.h>

using namespace std;

void subSequence(int i, int n, vector<int>& og, vector<int>& subseq)
{
    if(i>=n)
    {
        
        cout<<"[";
        for(int it:subseq)
        {
            cout<<it;
        }
        cout<<"], ";

        return;
    }
    subseq.push_back(og[i]);
    subSequence(i+1, n, og, subseq);

    subseq.pop_back();
    subSequence(i+1, n, og, subseq);

}

int main()
{
    int n; 
    cin>>n;
    vector<int>arr(n);
    vector<int>subseq;

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    subSequence(0, n, arr, subseq);
    return 0;
}