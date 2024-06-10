#include<bits/stdc++.h>

using namespace std;


void bubbleSort(vector<int> &arr, int size)
{
    for( int i = size-1; i>=1; i--)
    {
        int didSwap = 0; // for best case
        for( int j = 0; j<i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        //for best case
        if(didSwap==0){
            break;
        }
        cout<<"runs"<<endl;
    }

    for ( int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int size;
    cin>>size;
    vector<int>arr(size);
    
    for ( int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }

    bubbleSort(arr, size);
    return 0;
}