#include<bits/stdc++.h>

using namespace std;

void reverse(vector<int> &array, int left, int right)
{
    if(left>=right)
    {
        return;
    }

    swap(array[left], array[right]);

    reverse(array, left+1, right-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int>array(n);

    for(int i = 0; i<n; i++)
    {
        cin>>array[i];
    }

    reverse(array, 0, n-1);

    for(int i = 0; i<n; i++)
    {
        cout<<array[i]<<" ";
    }

    


    return 0;
}