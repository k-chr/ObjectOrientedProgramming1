#ifndef _stack_H
#define _stack_H

class stack
{
public:
	void push(int a);
	int pop();
	void clear();
	stack();
	~stack();
private:
	int top;
	int size;
	int* ptr_data;
};

#endif