#pragma once

#include <iostream>
#include "stackqueue.h"

bool TrueBrackets(string s)
{
	Stack<char> st;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.Push(s[i]);
		else if (st.Top() == '(' && s[i] == ')' && !st.Empty())
			st.Pop();
		else if (st.Top() == '[' && s[i] == ']' && !st.Empty())
			st.Pop();
		else if (st.Top() == '{' && s[i] == '}' && !st.Empty())
			st.Pop();
		else return false;
	}
	if (st.Empty())
		return true;
	else return false;
}

int main(int argc, char** argv)
{
	if (argc > 1)
		cout << TrueBrackets(argv[1]) << endl;
	return 0;
}