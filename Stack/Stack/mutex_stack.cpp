#include "pch.h"
#include "mutex_stack.h"


mutex_stack::mutex_stack(){
}

void mutex_stack::push(int data) {
	std::lock_guard<std::mutex> lock(m);
	database.push(data);
}

int mutex_stack::top_and_pop() {
	std::lock_guard<std::mutex> lock(m);
	int ans = -1;
	if (!database.empty()) {
		ans = database.top();
		database.pop();
	}
	return ans;
}

mutex_stack::~mutex_stack(){
}
