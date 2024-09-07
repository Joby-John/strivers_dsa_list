// ->from range 1 to n includive.
// ->if % by 3 and 5- fizzbuzz
// -> if% by 3 and not 5- fizz
// -> if  % by 5 and 3 - buzz

#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    void fizzBuzz(int n)
    {
        for(int i = 1; i<=n; i++)
        {

            if(i%15 == 0)
            {
                cout<<"FizzBuzz"<<endl;
            }
            else if(i%3==0 && i%5!=0)
            {
                cout<<"Fizz"<<endl;
            }
            else if(i%5 == 0 && i%3 !=0)
            {
                cout<<"Buzz"<<endl;
            }
            else
            {
                cout<<i<<endl;
            }
        }
    }
};

int main()
{
    int n;
    cin>>n;
    Solution sol;
    sol.fizzBuzz(n);
    return 0;
}