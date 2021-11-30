#pragma once
#include <string>
#include <iostream>
#include "HTStack.h"

//using namespace std;

class TCalculator {
	std::string expr;
	std::string postfix;
	TStack<char> st_char;
	TStack<double> st_d;
	int prior(char t);

public: 
	TCalculator(int size = 30) {
		TStack<char> t(size);
		st_char = t;
		TStack<double> tt(size);
		st_d = tt;
	}
	TCalculator(const std::string& s) {
		expr = s;
		int size = s.size();
		TStack<char> t(size);
		st_char = t;
		TStack<double> tt(size);
		st_d = tt;
	}
	TCalculator(const TCalculator& a) {
		expr = a.expr;
		st_char = a.st_char;
		st_d = a.st_d;
	}
	void SetExpr(const std::string& s) {
		expr = s;
		int size = s.size();
		TStack<char> t(size);
		st_char = t;
		TStack<double> tt(size);
		st_d = tt;
	}
	std::string GetExpr() {
		return expr;
	}
	std::string GetPostfix() {
		return postfix;
	}

	bool CheckExpr();

	double Calc();

	void ToPostfix();

};

void TCalculator::ToPostfix() {
	std::string infix = "(" + expr + ")";
	postfix = "";
	st_char.clear();
	for(int i = 0; i < infix.size(); i++) {
		if (infix[i] == ' ')
			continue;
		if (infix[i] >= '0' && infix[i] <= '9') {
			size_t ind = 0;
			double e = std::stod(&infix[i], &ind);
			if(postfix.size())
				postfix += " ";
			postfix += infix.substr(i,ind);

			i += ind - 1;
			continue;
		}
		if (infix[i] == '(') {
			st_char.push('(');
			continue;
		}
		if (infix[i] == ')') {
			while (st_char.top() != '(') {
				if (postfix.size())
					postfix += " ";
				postfix += st_char.top();
				st_char.pop();
			}
			st_char.pop();
			continue;
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			while (prior(st_char.top()) >= prior(infix[i])) {
				if (postfix.size())
					postfix += " ";
				postfix += st_char.top();
				st_char.pop();
			}
			st_char.push(infix[i]);
		}
	}
}

bool TCalculator::CheckExpr(){
		st_char.clear();
		bool flag = 1;
		for (int i = 0; i < expr.size(); i++) {
			if (expr[i] == '(')
				st_char.push('(');
			if (expr[i] == ')') {
				if (st_char.empty()) {
					flag = 0;
					break;
				}
				st_char.pop();
			}
		}
		flag = std::min(flag, st_char.empty());
		return flag;
}

double TCalculator::Calc() {
	std::string infix = "(" + expr + ")";
	st_char.clear();
	st_d.clear();

	for (int i = 0; i < infix.size(); i++) {
		
		if (infix[i] == ' ')
			continue;
		if (infix[i] >= '0' && infix[i] <= '9') {
			size_t ind = 0;
			double e = std::stod(&infix[i], &ind);
			st_d.push(e);

			i += ind - 1;
			continue;
		}
		if (infix[i] == '(') {
			st_char.push('(');
			continue;
		}
		if (infix[i] == ')') {
			while (st_char.top() != '(') {
				double b = st_d.pop();
				double a = st_d.pop();
				double t;
				switch (st_char.top())
				{
				case '+':
					st_d.push(a + b);
					break;
				case '-':
					st_d.push(a - b);
					break;
				case '*':
					st_d.push(a * b);
					break;
				case '/':
					st_d.push(a / b);
					break;
				case '^':
					t = 1;
					for (int i = 0; i < b; i++)
						t *= a;
					st_d.push(t);
					break;
				default:
					break;
				}
				st_char.pop();
			}
			st_char.pop();
			continue;
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
			while (prior(st_char.top()) >= prior(infix[i])) {
				double b = st_d.pop();
				double a = st_d.pop();
				double t;
				switch (st_char.top())
				{
				case '+':
					st_d.push(a + b);
					break;
				case '-':
					st_d.push(a - b);
					break;
				case '*':
					st_d.push(a * b);
					break;
				case '/':
					st_d.push(a / b);
					break;
				case '^':
					t = 1;
					for (int i = 0; i < b; i++)
						t *= a;
					st_d.push(t);
					break;
				default:
					break;
				}
				st_char.pop();
			}
			st_char.push(infix[i]);
		}
	}
	return st_d.pop();
}

int TCalculator::prior(char t) {
	switch (t) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	case '(':
		return 0;
	}
}