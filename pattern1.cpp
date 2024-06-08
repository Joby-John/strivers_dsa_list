#include<bits/stdc++.h>

using namespace std;


void pattern1( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int j = 1; j<=i; j++)
    {
        cout<<"* ";
    }
    cout << endl;
  }
}

void pattern2( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int j = 1; j<=i; j++)
    {
        cout<<j<<" ";
    }
    cout << endl;
  }
}
void pattern3( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int j = 1; j<=i; j++)
    {
        cout<<i<<" ";
    }
    cout << endl;
  }
}

void pattern4( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int j = n; j>=i; j--)
    {
        cout<<"* ";
    }
    cout << endl;
  }
}

void pattern5( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int j = n; j>=i; j--)
    {
        cout<<j<<" ";
    }
    cout << endl;
  }
}

void pattern6( int n)
{
  for(int i = 1; i<=n; i++)
  {
    for (int k = n-i; k>0; k--)
    {
      cout<<" ";
    }
    for (int j = 1; j<=i; j++)
    {
        cout<<j<<" ";
    }
    cout << endl;
  }
}

void pattern7( int n)
{
  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 1; j<=n-i; j++)
    {
      cout<<"s";
    }
    //stars
    for ( int j = 1; j<=i; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 1; j<=n-i; j++)
    {
      cout<<"s";
    }
    cout << endl;
  }
}

void pattern8( int n)
{
  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 0; j<i-1; j++)
    {
      cout<<" ";
    }
    //stars
    for ( int j = 1; j<=n-i+1; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 0; j<=i-1; j++)
    {
      cout<<" ";
    }
    cout << endl;
  }
}

void pattern9( int n)
{
  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 0; j<i-1; j++)
    {
      cout<<" ";
    }
    //stars
    for ( int j = 1; j<=n-i+1; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 0; j<=i-1; j++)
    {
      cout<<" ";
    }
    cout << endl;
  }

  //straight

  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 1; j<=n-i; j++)
    {
      cout<<" ";
    }
    //stars
    for ( int j = 1; j<=i; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 1; j<=n-i; j++)
    {
      cout<<" ";
    }
    cout << endl;
  }
}

void pattern10( int n)
{
  //straight
  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 1; j<=n-i; j++)
    {
      cout<<" ";
    }
    //stars
    for ( int j = 1; j<=i; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 0; j<=n-i; j++)
    {
      cout<<" ";
    }
    cout << endl;
  }

  //inverted
  for(int i = 1; i<=n; i++)
  {
    //space

    for( int j = 0; j<i; j++)
    {
      cout<<" ";
    }
    //stars
    for ( int j = 1; j<=n-i; j++)
    {
      cout<<j<<" ";
    }

    //space
    for( int j = 1; j<i; j++)
    {
      cout<<" ";
    }
    cout << endl;
  }
}

int main()
{
    int t;
    int n;
    cin >> t;
    for( int i = 0; i<t; i++)
    {
    cin >> n;
    pattern10(n);
    }
    return 0;
}