#include <bits/stdc++.h>

using namespace std;

class FindPrimes
{
public:
    vector<int> seive(int m)
    {
        vector<bool> isPrime(m + 1, true);
        vector<int> primeNumbers;

        isPrime[0] = isPrime[1] = false;
        for (int p = 2; p <= m; ++p)
        {
            if (isPrime[p])
            {
                primeNumbers.push_back(p);
                for (int i = p * p; i <= m; i += p)
                {
                    isPrime[i] = false;
                }
            }
        }
        return primeNumbers;
    }

    int minToMakeN(int n, int m)
    {
        vector<int> primes = seive(m);
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0; // 0 primes needed to make 0

        for (int prime : primes)
        {
            for (int i = prime; i <= n; i++)
            {
                if (dp[i - prime] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - prime] + 1);
                }
            }
        }

        if(dp[n] == INT_MAX)
        {
            return -1;
        }
        else
        {
            return dp[n];
        }

        //return (dp[n] == INT_MAX) ? -1 : dp[n];
    }
};

int main()
{
    FindPrimes ob;

    int n, m;
    cout << "Enter the target number (n): ";
    cin >> n;
    cout << "Enter the upper limit for primes (m): ";
    cin >> m;

    int result = ob.minToMakeN(n, m);
    if (result != -1)
    {
        cout << "Minimum number of primes required to make " << n << ": " << result << endl;
    }
    else
    {
        cout << "It is not possible to make " << n << " with primes up to " << m << endl;
    }

    return 0;
}
