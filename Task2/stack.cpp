#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "stack.h"
using namespace std;
stack::stack()
{
	this->top = 0;
	this->size = 1;
	this->ptr_data = new int[1];
}

stack::~stack()
{
	this->top = 0;
	this->size = 0;
	if(this->ptr_data) delete[] this->ptr_data;
}

void stack::clear()
{
	this->top = 0;
}

void stack::push(int a)
{
	if(this->top < this->size)
	{
		this->ptr_data[this->top++] = a;
	}
	else
	{
		int *tmp = new int[this->size * 2];
		memcpy(tmp, this->ptr_data, this->top * sizeof(int));
		delete[] this->ptr_data;
		this->ptr_data = tmp;
		this->ptr_data[this->top++] = a;
		this->size *= 2;
	}	
}

int stack::pop()
{
	if(this->top > 0)
	{
		if(this->top >= (this->size / 2))
		{
			return this->ptr_data[--this->top];
		}
		else
		{
			int* tmp = new int[this->size / 2];
			memcpy(tmp, this->ptr_data, this->top * sizeof(int));
			delete[] this->ptr_data;
			this->ptr_data = tmp;
			this->size /= 2;
			return this->ptr_data[--this->top];
		}
	}
	return 0;
}