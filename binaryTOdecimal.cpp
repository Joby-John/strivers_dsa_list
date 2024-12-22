#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    void binaryToDecimal(string binaryNumber)
    {
        int  n = binaryNumber.size();

        int power = 1;

        int decimal = 0;

        for(int i = n-1; i>=0; i--)
        {
            if(binaryNumber[i]=='1')
            {
                decimal += power*1;
            }
            power *= 2;
        }

        cout<<"Result:"<<decimal<<endl;
    }
};
int main()
{

    Solution sol;
    string binaryNumber = "";
    cin>>binaryNumber;
    sol.binaryToDecimal(binaryNumber);
    return 0;
}

