#include<bits/stdc++.h>

using namespace std;

class recurssion
{
    public:
        void nTo1(int i, int n)
        {
          if(i>n)
          {
            return;
          }

          nTo1(i+1, n);

          cout<<i<<endl;
        }
};

int main()
{
    int n;

    cin>>n;

    recurssion ob = recurssion();

    ob.nTo1(1,n);
}