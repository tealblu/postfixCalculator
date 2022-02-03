/**
 * @file cPEcaller.cpp
 * @author Charles Hartsell (ckharts@clemson.edu)
 * @brief 
 * @version 0.1
 * @date 2022-02-03
 * 
 * @copyright Copyright (c) 2022
 * 
 * This file is a companion file for calculatePostfixExpression.cpp
 * It exists solely to setup and run that function.
 * Please compile with:
 *  g++ cPEcaller.cpp calculatePostfixExpression.cpp -o postfixCalc
 * And run with:
 *  ./postfixCalc
 * Thank you!
 */

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