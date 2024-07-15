#include<bits/stdc++.h>

using namespace std;

class FindPrimes
{
public:
    vector<int>seive(int n)
    {
        vector<bool>primes(n+1, true);
        vector<int>primeNumbers;

        for(int p = 2; p*p<=n; p++)
        {
            if(primes[p])
            {
                for(int i = p*p; i<=n; i+=p)
                {
                    primes[i] = false;
                }
            }
        }

        for(int i = 2; i<=n; i++)
        {
            if(primes[i])
            {
                primeNumbers.push_back(i);
            }
        }

        return primeNumbers;
    }
};


int main()
{
    FindPrimes ob = FindPrimes();

    int p ;
    cin>>p;
    vector<int>primes;

    primes = ob.seive(p);

    for(auto it:primes)
    {
        cout<<it<<endl;
    }

    return 0;
}