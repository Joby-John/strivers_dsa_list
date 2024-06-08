#include<bits/stdc++.h>

using namespace std;

int main()
{
    int age;
    cin >> age;
    
    if (age>18)
    {
        cout<<"You are an adult";
    }
    else if(age>0)
    {
        cout<<"You are not an adult";
    }
    else{
        cout<<"Invalid age";
    }

    
    return 0;
}