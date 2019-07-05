#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
	stack* s1 = new stack();
	stack* s2 = new stack();
	s1->push(1);
	s1->push(2);
	s1->push(3);
	s1->push(111);
	s1->push(23);
	s1->push(37);
	s2->push(5);
	s2->push(6);
	cout << (s1->pop()) << " -stack1" << endl;
	cout << (s1->pop()) << " -stack1" << endl;
	cout << (s2->pop()) << " -stack2" << endl;
	cout << (s2->pop()) << " -stack2" << endl;
	s1->clear();
	s1->push(1);
	s1->push(2);
	s1->push(3);
	cout << (s1->pop()) << " -stack1" << endl;
	cout << (s1->pop()) << " -stack1" << endl;
	delete s1;
	delete s2;
	return 0;
}
