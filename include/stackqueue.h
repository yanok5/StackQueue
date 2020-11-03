#pragma once

#include "vector.h"
#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 1000;
const int MAX_QUEUE_SIZE = 1000;

template <typename T>
class Stack
{
private:
	T *pStack;
	int Size;
	int Max;
public:
	Stack(int s= 10);
	Stack(const Stack &s);
	~Stack();
	void Push(T elem);	// Добавить элемент в стек
	void Pop();		// Удалить элемент из стека
	bool Empty();	// Проверка на пустоту стека
	bool Full();	// Проверка на полноту стека
	Stack& operator=(const Stack &s);
	bool operator==(const Stack &s) const;
	bool operator!=(const Stack &s) const;
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

template <typename T>
class Queue : public Vector<T>
{
private:
	unsigned int front;
	unsigned int back;
	void insert(T elem, int index) {}
	void erase(int index) {}
	void pop_back() {}
	void pop_front() {}
	void push_back(T elem) {}
	void push_front(T elem) {}
	void resize(int n) {}
public:
	Queue() :Vector() { front = 0; back = 0; }
	Queue(int n) :Vector(n) { front = 0; back = n - 1; }
	~Queue() {}
	T Front() { return data[front]; }
	T Back() { return data[back]; }
	void push(T elem) {
		back++;
		if (back == capacity)
			back = 0;
		if (this->full() == 1)
			resize(size_t(coefficient * capacity) + 1);
		data[back] = elem;
		size++;
	}

	void pop() {
		if (size == 0) throw std::logic_error("Unable to delete element");
		front++;
		size--;
		if (front == capacity) front = 0;
	}

	bool empty() {
		if (size == 0) return 1;
		else return 0;
	}

	bool full() {
		if (size == capacity) return 1;
		else return 0;
	}
};
