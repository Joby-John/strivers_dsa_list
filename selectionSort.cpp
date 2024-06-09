#include<bits/stdc++.h>

using namespace std;


void selection_sort(vector<int> &arr, int size)
{
    int temp, min, loc;

    for(int i = 0; i<size-1; i++) //size-1 bc last element does't need to be compared as its last
    {
        min = arr[i];
        for(int j = i+1; j<size;j++)
        {
            
            if(arr[j]<min)
            {
                min = arr[j];
                loc = j;
            }

        }
        temp = arr[i];
        arr[i] = min;
        arr[loc]=temp;
        
    }

     for( int i = 0; i<size; i++)
     {
        cout<<arr[i]<<" ";
     }
}
int main()
{
    int size;
    cin>>size;
    vector<int>arr(size);

    for( int i = 0; i<size; i++)
     {
        cin>>arr[i];
     }

     selection_sort(arr, size);
    

    

    return 0;
}