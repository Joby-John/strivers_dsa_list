#include<bits/stdc++.h>

using namespace std;

int main()
{
    int size;
    int temp, min, loc;
    cin>>size;
    vector<int>arr(size);

    for( int i = 0; i<size; i++)
     {
        cin>>arr[i];
     }
    

    for(int i = 0; i<size; i++)
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
        cout<<arr[i]<<",";
     }

    return 0;
}