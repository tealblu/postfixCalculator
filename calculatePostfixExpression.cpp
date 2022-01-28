#include <string>
#include <stack>

using namespace std;


bool isOp(string op) {
    if(op=="+" || op=="-" || op=="*" || op=="/" || op=="%") {
        return true;
    } else {
        return false;
    }
}

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    stack<int> S;
    int val1, val2, result;

    if(length<3 && length!=1) {return 0;}
    if(length==1) {
        if(isOp(expression[0])) {
            return 0;
        } else {
            return stoi(expression[0]);
        }
    }

    for(int count=0;count<length;count++) {
        if(expression[count]=="+") { // Operator +
            // Stuff for +
            val1 = S.top();
            S.pop();
            val2 = S.top();
            S.pop();

            result = val2 + val1;
            S.push(result);
        } else if(expression[count]=="-") {
            // Stuff for -
            val1 = S.top();
            S.pop();
            val2 = S.top();
            S.pop();

            result = val2 - val1;
            S.push(result);
        } else if(expression[count]=="*") {
            // Stuff for *
            val1 = S.top();
            S.pop();
            val2 = S.top();
            S.pop();

            result = val2 * val1;
            S.push(result);
        } else if(expression[count]=="/") {
            // Stuff for /
            val1 = S.top();
            S.pop();
            val2 = S.top();
            S.pop();

            result = val2 / val1;
            S.push(result);
        } else if(expression[count]=="%") {
            // Stuff for %
            val1 = S.top();
            S.pop();
            val2 = S.top();
            S.pop();

            result = val2 % val1;
            S.push(result);
        } else { // Operand
            S.push(stoi(expression[count]));
        }
    }

    result = S.top();
    S.pop();
    if(!S.empty()) {return 0;}
    return result;
}