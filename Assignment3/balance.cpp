#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& expression, bool &validInput) {
    stack<char> stk;
    validInput = true;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.empty() || (ch == ')' && stk.top() != '(') ||
                (ch == '}' && stk.top() != '{') ||
                (ch == ']' && stk.top() != '[')) {
                return false;
            }
            stk.pop();
        } else {

        }
    }

    return stk.empty();
}

int main() {
    cout << "Enter an expression to check for balanced brackets: ";
    string expression;
    getline(cin, expression);

    bool validInput;
    if (isBalanced(expression, validInput)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
    return 0;
}
