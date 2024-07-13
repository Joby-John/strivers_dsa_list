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
            cout<<i<<endl;
        }
};

int main()
{
    int n;
    cin>>n;

    recurssion ob = recurssion();
    ob.backTrack(n);
}