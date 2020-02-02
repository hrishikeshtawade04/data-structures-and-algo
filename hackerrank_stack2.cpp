#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::cin;
using std::endl;

void shiftItems(stack<int> &stackOld, stack<int> &stackNew){
    const int previousSize = stackNew.size();
    for(int i = 0; i< previousSize ; i++){
        stackOld.push(stackNew.top());
        stackNew.pop();
    }
}

void enqueue(stack<int> &stackNew, int item){
    stackNew.push(item);
}

int peek(stack<int> &stackNew, stack<int> &stackOld){
    if(!stackOld.empty())
        return stackOld.top();
    else{
        cout << "True" << endl;
        shiftItems(stackOld, stackNew);
        return stackOld.top();
    }
}

void dequeue(stack<int> &stackNew, stack<int> &stackOld){
    if(!stackOld.empty())
        stackOld.pop();
    else{
        shiftItems(stackOld, stackNew);
        stackOld.pop();
    }
}

int main(){
    stack<int> stackOld;
    stack<int> stackNew;
    int item = 0;
    
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);
    
    cout << peek(stackNew, stackOld) << endl;
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);
    
    cout << peek(stackNew, stackOld) << endl;
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);
    
    cout << peek(stackNew, stackOld) << endl;
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);
    
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);
    
    cout << "Enter item" << endl;
    cin >> item;
    enqueue(stackNew, item);

    dequeue(stackNew, stackOld);
    cout << peek(stackNew, stackOld) << endl;
    dequeue(stackNew, stackOld);
    cout << peek(stackNew, stackOld) << endl;
    dequeue(stackNew, stackOld);
    cout << peek(stackNew, stackOld) << endl;
    dequeue(stackNew, stackOld);
    cout << peek(stackNew, stackOld) << endl;
    return 0;
}