#include<bits/stdc++.h>

using namespace std;
class recurssion{
public:
int count = 0;
    void recurssionWithBase()
    {
    if(count == 7)
    {
        return;
    }

    cout<<count<<endl;
    count++;
    recurssionWithBase();
    }
};

    int main()
    {
        recurssion ob = recurssion();
        ob.recurssionWithBase();
        return 0;
    }