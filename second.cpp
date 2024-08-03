#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> numbers;
    vector<char> operators;
    
    string num = "";
    
    // Extract numbers and operators
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            num += s[i];
        } else {
            numbers.push_back(stoi(num));
            num = "";
            operators.push_back(s[i]);
        }
    }
    numbers.push_back(stoi(num));
    
    // Evaluate * and / first
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            int operand1 = numbers[i];
            int operand2 = numbers[i + 1];
            int result;
            
            if (operators[i] == '*') {
                result = operand1 * operand2;
            } else if (operators[i] == '/') {
                result = operand1 / operand2;
            }
            
            // Update the numbers and operators
            numbers[i] = result;
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--; // Adjust index after modification
        }
    }
    
    // Now evaluate + and -
    int result = numbers[0];
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        } else if (operators[i] == '-') {
            result -= numbers[i + 1];
        }
    }
    
    cout << result;
    return 0;
}
