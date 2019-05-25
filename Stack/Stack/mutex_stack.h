#pragma once
#include<stack>
#include<mutex>
class mutex_stack{
private:
	std::stack<int> database;
	std::mutex m;

public:
	mutex_stack();
	void push(int data);
	int top_and_pop();
	~mutex_stack();
};

