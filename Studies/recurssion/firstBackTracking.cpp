#include<bits/stdc++.h>

using namespace std;

class recurssion
{
    public:

        void backTrack(int i)
        {
            if(i<1)
            {
                return;
            }

            backTrack(i-1);
            cout<<i<<endl; // by writing tasks after recursive call
            //we made sure that the execution of our task start from 
            //the base case, that is execution only starts when it returns.
        }
};

int main()
{
    int n;
    cin>>n;

    recurssion ob = recurssion();
    ob.backTrack(n);
}