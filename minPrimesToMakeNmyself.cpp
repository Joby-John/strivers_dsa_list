#include<bits/stdc++.h>

using namespace std;

vector<int>seive(int n)
{
    vector<bool>primes(true,n+1);
    vector<int>primeNumbers;
    primes[0]=primes[1] = false;

    for(int p = 2; p<=n; p++)
    {
      if(primes[p] == true)
      {
        primeNumbers.push_back(p);
      }

      for(int i = p*p; i<=n; i+=p)
      {
        primes[i] = false;
      }
    }

    return primeNumbers;
}

int minPrimestoN(int target, int m)
{
    vector<int>dp(target+1, INT_MAX);
    vector<int>primesUptoTarget = seive(target);

    vector<int>mPrimes(primesUptoTarget.begin(), primesUptoTarget.begin()+m);

    dp[0] = 0;

    for(int prime: mPrimes)
    {
        for(int i = prime; i<=target; i++)
        {
            if(dp[i-prime] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i-prime]+1);
            }
        }
    }

    if(dp[target] != INT_MAX)
    {
        return dp[target];
    }
    else{
        return -1;
    }
}

int main()
{
    int n, m;
    cin>>n;
    cin>>m;

    int result = minPrimestoN(n, m);

    cout<<result;

    return 0;
}

// explanation
// Let's perform a dry run of the critical portion of the minToMakeN function with the inputs n = 11 and m = 5.
// Initial Setup:

//     n = 11
//     m = 5
//     We first call the seive function to find all prime numbers up to m.

// Sieve Function Execution:

//     Prime Generation:
//         Create a isPrime vector of size m+1 initialized to true, except for isPrime[0] and isPrime[1] which are set to false.
//         Iterate through numbers from 2 to m:
//             p = 2: It's prime, mark multiples as non-prime (4).
//             p = 3: It's prime, mark multiples as non-prime (none up to 5).
//             p = 4: Already marked as non-prime.
//             p = 5: It's prime, mark multiples as non-prime (none up to 5).

//     Prime Numbers: The generated prime numbers up to 5 are [2, 3, 5].

// Initialize DP Array:

//     Create a dp array of size n+1 initialized to INT_MAX:

//     css

//     dp = [0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX]

//     Set dp[0] to 0 because 0 primes are needed to make 0.

// DP Array Update with Primes:

//     Iterate over each prime and update dp array:

//     Prime = 2:
//         For i from 2 to 11:
//             i = 2: dp[2] = min(dp[2], dp[0] + 1) = min(INT_MAX, 0 + 1) = 1
//             i = 3: dp[3] remains INT_MAX because dp[1] is INT_MAX.
//             i = 4: dp[4] = min(dp[4], dp[2] + 1) = min(INT_MAX, 1 + 1) = 2
//             i = 5: dp[5] remains INT_MAX because dp[3] is INT_MAX.
//             i = 6: dp[6] = min(dp[6], dp[4] + 1) = min(INT_MAX, 2 + 1) = 3
//             i = 7: dp[7] remains INT_MAX because dp[5] is INT_MAX.
//             i = 8: dp[8] = min(dp[8], dp[6] + 1) = min(INT_MAX, 3 + 1) = 4
//             i = 9: dp[9] remains INT_MAX because dp[7] is INT_MAX.
//             i = 10: dp[10] = min(dp[10], dp[8] + 1) = min(INT_MAX, 4 + 1) = 5
//             i = 11: dp[11] remains INT_MAX because dp[9] is INT_MAX.
//         dp after processing prime 2:

//         css

//     dp = [0, INT_MAX, 1, INT_MAX, 2, INT_MAX, 3, INT_MAX, 4, INT_MAX, 5, INT_MAX]

// Prime = 3:

//     For i from 3 to 11:
//         i = 3: dp[3] = min(dp[3], dp[0] + 1) = min(INT_MAX, 0 + 1) = 1
//         i = 4: dp[4] remains 2 because dp[1] is INT_MAX.
//         i = 5: dp[5] = min(dp[5], dp[2] + 1) = min(INT_MAX, 1 + 1) = 2
//         i = 6: dp[6] = min(dp[6], dp[3] + 1) = min(3, 1 + 1) = 2
//         i = 7: dp[7] = min(dp[7], dp[4] + 1) = min(INT_MAX, 2 + 1) = 3
//         i = 8: dp[8] = min(dp[8], dp[5] + 1) = min(4, 2 + 1) = 3
//         i = 9: dp[9] = min(dp[9], dp[6] + 1) = min(INT_MAX, 2 + 1) = 3
//         i = 10: dp[10] = min(dp[10], dp[7] + 1) = min(5, 3 + 1) = 4
//         i = 11: dp[11] = min(dp[11], dp[8] + 1) = min(INT_MAX, 3 + 1) = 4
//     dp after processing prime 3:

//     css

//     dp = [0, INT_MAX, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4]

// Prime = 5:

//     For i from 5 to 11:
//         i = 5: dp[5] = min(dp[5], dp[0] + 1) = min(2, 0 + 1) = 1
//         i = 6: dp[6] remains 2 because dp[1] is INT_MAX.
//         i = 7: dp[7] remains 3 because dp[2] is 1 and dp[2] + 1 is 2, which is not less than the current value 3.
//         i = 8: dp[8] remains 3 because dp[3] is 1 and dp[3] + 1 is 2, which is not less than the current value 3.
//         i = 9: dp[9] remains 3 because dp[4] is 2 and dp[4] + 1 is 3, which is not less than the current value 3.
//         i = 10: dp[10] = min(dp[10], dp[5] + 1) = min(4, 1 + 1) = 2
//         i = 11: dp[11] remains 4 because dp[6] is 2 and dp[6] + 1 is 3, which is not less than the current value 4.
//     dp after processing prime 5:

//     css

//         dp = [0, INT_MAX, 1, 1, 2, 1, 2, 2, 3, 3, 2, 3]

// Final Output:

//     The value of dp[11] is 3, meaning the minimum number of primes required to make 11 using primes up to 5 is 3.
//     Therefore, the output will be 3.

// Explanation of the Output:

// The minimum number of primes required to make 11 using primes up to 5 is 3 because one of the combinations is 2 + 2 + 2 + 5 = 11, which uses three primes: 2, 2, and 5. The dynamic programming approach effectively finds the minimum count.