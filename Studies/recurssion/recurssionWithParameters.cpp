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

        cout<<"Joby"<<endl;
        
        recurssionWithParameters(i+1, n);
        cout<<i<<"complete"<<endl;
    }

};

int main()
{
    int n;
    cin>>n;

    recurssion ob = recurssion();
    ob.recurssionWithParameters(0,n);
}