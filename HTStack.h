#pragma once

#include <iostream>
#include<string>
//using namespace std;


template<class T>
class TStack {
protected:
	T* pMem;
	int size;
	int	pos;

public:
	TStack(int _size = 10) :size(_size), pos(0) {
		if (size <= 0)
			throw "NS";
		pMem = new T[size];
	}
	~TStack() {
		delete[] pMem;
	}
	TStack(const TStack& a) {
		size = a.size;
		pMem = new T[size];
		pos = a.pos;
		for (int i = 0; i < pos; i++)
			pMem[i] = a.pMem[i];
	}
	TStack& operator=(const TStack& a) {
		if (a.size != size) {
			delete[] pMem;
			size = a.size;
			pMem = new T[size];
		}
		pos = a.pos;
		for (int i = 0; i < pos; i++)
			pMem[i] = a.pMem[i];
		return *this;
	}
	bool operator==(const TStack& b)const {
		if (b.pos != pos)
			return 0;
		int flag = 1;
		for (int i = 0; i < pos; i++)
			if (pMem[i] != b.pMem[i])
				flag = 0;
		return flag;
	}
	bool operator!=(const TStack& b)const {
		if (b.pos != pos)
			return 1;
		int flag = 1;
		for (int i = 0; i < pos; i++)
			if (pMem[i] != b.pMem[i])
				flag = 0;
		return 1 - flag;
	}
	bool full() {
		return pos == size;
	}
	bool empty() {
		return pos == 0;
	}
	void push(T val) {
		if (this->full())
			throw "FS";
		pMem[pos++] = val;
	}
	T pop() {
		if (this->empty())
			throw "ES";
		return pMem[--pos];
	}
	T top() {
		if (this->empty())
			throw "ES";
		return pMem[pos - 1];
	}
	void clear() {
		pos = 0;
	}


};

