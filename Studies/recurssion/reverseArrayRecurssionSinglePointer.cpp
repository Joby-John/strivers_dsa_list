#include<bits/stdc++.h>

using namespace std;

void reverse(vector<int> &arr, int i)
{
    int n = arr.size();

    if(i>=n/2)
    {
        return;
    }

    swap(arr[i], arr[n-1-i]);
    reverse(arr, i+1);
}

int main()
{

    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    reverse(arr, 0);

    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}