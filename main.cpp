#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack<char> a;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            a.push(s[i]);
        } else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
            if (a.empty()) {
                return false;
            }
            char top = a.top();
            if ((top == '[' && s[i] == ']') || (top == '{' && s[i] == '}') || (top == '(' && s[i] == ')')) {
                a.pop();
            } else {
                return false;
            }
        }
    }
    return a.empty();
}

int main() {
    string s = "([{({})}])"; // Modify the input string to contain only parentheses and brackets
    if (check(s)) {
        cout << "It is balanced";
    } else {
        cout << "It is not balanced";
    }
    return 0;
}
