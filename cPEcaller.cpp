#include <iostream>
#include <string>

using namespace std;

int calculatePostfixExpression(string expression[], int length);

int main(void) {
    string expStr;
    int expStrLen;

    cout << "Please enter your expression using postfix notation:" << endl;
    cin >> expStr;

    expStrLen = expStr.length();

    string expression[expStrLen];
    for(int i = 0; i < expStrLen; i++) {
        expression[i] = expStr.at(i);
    }

    int result = calculatePostfixExpression(expression, expStrLen);

    cout << "Result: " << result << endl;

    return 0;
}