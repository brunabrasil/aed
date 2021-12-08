# include <iostream>
# include <stack>
using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T> 
bool StackExt<T>::empty() const {
	return values.empty();
}

template <class T> 
T& StackExt<T>::top() {
    return values.top();
}

template <class T> 
void StackExt<T>::pop() {
    if (!values.size()) return;
    stack<T> temp;
    const T & t = values.top();
    while (minimums.size()) {
        if (t == minimums.top()) {
            minimums.pop();
            break;
        }
        else {
            temp.push(minimums.top());
            minimums.pop();
        }
    }
    while (temp.size()) {
        minimums.push(temp.top());
        temp.pop();
    }
    values.pop();
}

template <class T> 
void StackExt<T>::push(const T& val) {
    stack<T> temp;
    while (minimums.size()) {
        if (val < minimums.top()) break;
        else {
            temp.push(minimums.top());
            minimums.pop();
        }
    }
    minimums.push(val);
    while (temp.size()) {
        minimums.push(temp.top());
        temp.pop();
    }
    values.push(val);
}

template <class T> 
T& StackExt<T>::findMin() {
    return minimums.top();
}

