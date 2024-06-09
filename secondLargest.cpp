#include<bits/stdc++.h>

using namespace std;

 
 int findLargest(vector<int>&arr, int n)
 {
 
 int largest = arr[0];
	    int secondLargest = -1;
	    
	    for (int i = 0; i<n; i++)
	    {
	        if(arr[i]>largest)
	        {
	            secondLargest = largest;
	            largest = arr[i];
	        }
	        
	        else if(arr[i]<largest && arr[i]>secondLargest)
	        {
	            secondLargest = arr[i];
	        }
	    }
	    
	    if(largest == secondLargest)
	    {
	        return -1;
	    }
	    else
	    {
	        return secondLargest;
	    }
 }

int main(){
	int t;
	cin>>t;
	int size;
    
	for(int cases = 0; cases<t; cases++)
	{
		cin>>size;
	    vector<int> arr(size);
		for (int i = 0; i<size; i++)
		{
			cin>>arr[i];
		}
	 cout<<findLargest(arr, size)<<endl;	
	}

  
}