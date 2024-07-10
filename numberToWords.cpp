#include<bits/stdc++.h>
using namespace std;

string numberToWords(long long n) {
    if (n == 0) {
        return "Zero";
    }

    vector<string> oneto19 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                              "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    vector<string> bigGuys = {"Trillion", "Billion", "Million", "Thousand", ""};

    long long currPlace = 1000000000000; // Adjusted the initial place value to Trillion
    string result = "";
    int bigGuyPos = 0;

    while (currPlace > 0) {
        long long bigGuy = n / currPlace;
        n %= currPlace;
        currPlace /= 1000;

        if (bigGuy == 0) {
            bigGuyPos++;
            continue;
        }

        if (bigGuy >= 100) {
            result += oneto19[bigGuy / 100] + " Hundred ";
            bigGuy %= 100;
        }

        if (bigGuy >= 20) {
            result += tens[bigGuy / 10] + " ";
            bigGuy %= 10;
        }

        if (bigGuy > 0) {
            result += oneto19[bigGuy] + " ";
        }

        if (bigGuyPos < 5) {
            result += bigGuys[bigGuyPos] + " ";
        }

        bigGuyPos++;
    }

    // Trim any trailing spaces
    while (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    long long number = 10000002345;
    string result = numberToWords(number);
    cout << result << endl; // Output should be: "One Hundred Thousand One Hundred Twenty Nine"
    return 0;
}
