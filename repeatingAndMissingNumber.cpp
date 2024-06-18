#include<bits/stdc++.h>

using namespace std;

/*the brute case is using two loops and finding repeated
 is found using count > 2 and missing by finding givensum - missing then subsatracting that 
 to actual sum */

 /* the better solution uses map which takes recor dof accurances of elements then
 index with>1 is repeated and element<1 is missing*/

 /* Best case uses math operations, doing givensum - actualsum, the given element square sums
 - catual elements square sums, solving both to get a and b
 */

/* There is also an best XOR solution
*/
void repeatedNumber(vector<int> &nums) {
    
    int n = nums.size();
    long long givenSum = 0;
    long long givenSquareSum = 0;
    long long actualSum = static_cast<long long>(n)*(n+1)/2; // static cast i sused for casting.
    long long actualSquareSum = static_cast<long long>(n)*(n+1)*(2*n+1)/6;// cast only a single element ie, for n*n+1/2 cast like static_cast<long>(n)*... the result i saoutomaticaly upper casted if cated after calculation it'll truncated to fit then only converted
    
    long long aMinusb;
    long long aSqaureminusbSqaure;
    
    long long aPlusb;
    
    int a,b;
    
    for(int i = 0; i<n; i++)
    {
        givenSum += nums[i];
        givenSquareSum += static_cast<long long>(nums[i])*nums[i];
    }
    
    aMinusb = givenSum - actualSum;
    aSqaureminusbSqaure = givenSquareSum - actualSquareSum;
    
    aPlusb = aSqaureminusbSqaure/aMinusb;
    
    a = static_cast<int>((aPlusb + aMinusb)/2);
    b = static_cast<int>(aPlusb - a);
    
    cout<<"missing : "<<b<<endl;//a is repeat and b is missing
    cout<<"repeating : "<<a;
        
}

int main()
{
    int n; 
    cin>>n;

    vector<int>nums(n);
    vector<int>result;

    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }

    repeatedNumber(nums);
    return 0;
}
