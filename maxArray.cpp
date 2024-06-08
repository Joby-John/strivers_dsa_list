#include<bits/stdc++.h>

using namespace std;

void maximum(int* arr, int n)
{
    int max = arr[0];
  for(int i = 0; i<n; i++)
  {
    if(arr[i]>max)
    {
        max = arr[i];
    }
  }
  cout<<max;
}
int main()
{
    int n = 5;
    int arr[5] = {34,23,54,72,23};
    maximum(arr, n);
    return 0;
}