#pragma once
#include<stack>
#include<mutex>
template<typename T>
class mutex_stack{
private:
	std::stack<T> database;
	std::mutex m;

public:
	mutex_stack();
	void push(const T& data);
	T top_and_pop();
	~mutex_stack();
};

template<typename T>
mutex_stack<T>::mutex_stack() {
}
template<typename T>
void mutex_stack<T>::push(const T& data) {
	std::lock_guard<std::mutex> lock(m);
	database.push(data);
}
template<typename T>
T mutex_stack<T>::top_and_pop() {
	std::lock_guard<std::mutex> lock(m);
	T ans = -1;
	if (!database.empty()) {
		ans = database.top();
		database.pop();
	}
	return ans;
}
template<typename T>
mutex_stack<T>::~mutex_stack() {
}

