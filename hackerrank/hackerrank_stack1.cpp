#include <iostream>
#include <stack>
#include <string>

using std::stack;
using std::cout;
using std::string;
using std::endl;


char opposite(char openBrace){
    if(openBrace == '{')
        return '}';
    else if (openBrace == '[')
        return ']';
    else
        return ')';
}
bool isOpenTerm(char openBrace){
    if(openBrace == '{' || openBrace == '[' || openBrace == '(')
        return true;
    else
        return false;
    
}
int main(){
    string input = "{}";
    stack<char> stk;
    bool unbalanced = true;
    for(char letter:input) {
        if(isOpenTerm(letter)) {
            stk.push(letter);
            unbalanced = false;
        }
        else {
            char topOfStack = stk.top();
            stk.pop();
            if(opposite(topOfStack) == letter){
                continue;
            } else {
                unbalanced = true; 
                break;
            }
        }
    }
    if(!stk.empty() || unbalanced)
        cout << "unbalanced" << endl;
    else
        cout << "balanced" << endl;
    return 0;
}