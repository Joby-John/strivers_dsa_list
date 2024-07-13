#include<bits/stdc++.h>

using namespace std;

class recurssion
{
public:
    void recurssionWithParameters(int i, int n)
    {
        if(i>n)
        {
            cout<<"terminate at "<<i<<endl;
            return;
        }

        cout<<i<<endl;
        
        recurssionWithParameters(i+1, n);
        //cout<<i<<" complete"<<endl;
    }

    void reverse(int i)
    {
        if(i<1)
        {
            return;
        }

        cout<<i<<endl;
        reverse(i-1);
    }

};

int main()
{
    int n;
    cin>>n;

    recurssion ob = recurssion();
    ob.recurssionWithParameters(1,n);
    cout<<endl<<"Now reverse"<<endl;
    ob.reverse(n);
}