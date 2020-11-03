#pragma once

#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;

template <typename T>
class Stack
{
protected:
	T *pStack;
	int Size;
	int Max;
public:
	Stack(int s = 10);
	Stack(const Stack &s);
	~Stack();
	void Push(T elem);	// Добавить элемент в стек
	void Pop();		// Удалить элемент из стека
	bool Empty();	// Проверка на пустоту стека
	bool Full();	// Проверка на полноту стека
	T Top();
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;
	bool operator!=(const Stack &s) const;
	T operator[](int pos);
};

template <typename T>
Stack<T>::Stack(int s)
{
	if (s < 0 || s > MAX_STACK_SIZE)
		throw "Smth wrong!";
	Size = 0;
	Max = s;
	pStack = new T[s];
}

template <typename T>
Stack<T>::Stack(const Stack &s)
{
	Size = s.Size;
	Max = s.Max;
	pStack = new T[Max];
	for (int i = 0; i < Size; i++)
		pStack[i] = s.pStack[i];
}

template <typename T>
Stack<T>::~Stack()
{
	if (pStack)
	{
		delete[] pStack;
		pStack = nullptr;
	}
}

template <typename T>
void Stack<T>::Push(T elem)
{
	if (Full())
	{
		Max = 2.0 * Max;
		T* temp = new T[Max];
		for (int i = 0; i < Size; i++)
			temp[i] = pStack[i];
		if (pStack)
			delete[]pStack;
		pStack = temp;
	}
	pStack[Size++] = elem;
}

template <typename T>
void Stack<T>::Pop()
{
	if (Empty())
		throw "Stack is empty";
	else
	{
		pStack[--Size] = 0;
	}
}

template <typename T>
bool Stack<T>::Empty()
{
	return Size == 0;
}

template <typename T>
bool Stack<T>::Full()
{
	return Max == Size;
}

template<typename T>
T Stack<T>::Top()
{
	if (Empty())
		throw "Stack is empty";
	return pStack[Size - 1];
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack &s)
{
	Max = s.Max;
	Size = s.Size;
	if (pStack)
		delete[] pStack;
	pStack = new T[Max];

	for (int i = 0; i < Size; i++)
		pStack[i] = s.pStack[i];
	return *this;
}

template <typename T>
bool Stack<T>::operator==(const Stack &s) const
{
	if ((Size != s.Size) || (Max != s.Max))
		return false;
	for (int i = 0; i < Max; i++)
	{
		if (pStack[i] != s.pStack[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool Stack<T>::operator!=(const Stack &s) const
{
	return !(s == *this);
}

template <class T>
T Stack<T>::operator[](int pos)
{
	if (pos < 0 || pos > Max)
		throw "Smth wrong";
	return pStack[pos];
}
/*----------------------------------------------------------*/

template <class T>
class Queue : public Stack<T>
{
private:
	Stack<int> s1, s2;
	int Ise; //Index start element
public:
	Queue(int q = 6);
	~Queue() {};
	void Push(T elem);
	void Pop();
	bool operator==(const Queue &q);
	bool operator!=(const Queue &q);
	T operator[](int pos);
};

template <class T>
Queue<T>::Queue(int q)
{
	Stack<T> temp(q);
	s1 = temp;
	s2 = temp;
	Ise = 0;
}

template <class T>
void Queue<T>::Push(T elem)
{
	s1.Push(elem);
}

template <class T>
void Queue<T>::Pop()
{
	while (!s1.Empty())
	{
		s2.Push(s1.Top());
		s1.Pop();
	}
	s2.Pop();

	while (!s2.Empty())
	{
		s1.Push(s2.Top());
		s2.Pop();
	}
}

template <class T>
bool Queue<T>::operator==(const Queue &q)
{
	if ((!q.s1.Empty()) && (!s1.Empty()))
		if (s1 == q.s1)
			return true;
	if ((!q.s2.Empty()) && (!s2.Empty()))
		if (s2 == q.s2)
			return true;
	return false;
}

template <class T>
bool Queue<T>::operator!=(const Queue &q)
{
	return !(q == *this);
}

template <class T>
T Queue<T>::operator[](int pos)
{
	if (s2.Empty())
		return s1[pos + Ise];
	return s2[pos];
}