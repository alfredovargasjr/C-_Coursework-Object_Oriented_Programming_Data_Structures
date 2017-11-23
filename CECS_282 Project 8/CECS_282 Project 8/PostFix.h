#pragma once
#ifndef PostFix_h
#define PostFix_h
using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include "GenericStack.h"
//check if c is an operand
bool isOperand(char c) {
	if (isdigit(c))
		return true;
	if (c == '.')
		return true;
	return false;
}
//check if c is operator
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
		return true;
	return false;
}
//return the weight of the operator
int valueOp(char c) {
	int val = 0;
	switch (c) {
	case '+':
	case '-':
		val = 1;
		break;
	case '*':
	case '/':
	case '%':
		val = 2;
		break;
	case '^':
		val = 3;
		break;
	}
	return val;
}
//return is aoperator is heavier than b
bool isBiggerOp(char a, char b) {
	int diff = valueOp(a) - valueOp(b);
	if (diff > 0)
		return true;
	return false;

}
/*
	- postfix to infix
	- return infix
	*/
string toInFix(string s) {
	GenericStack<char> charStk;
	GenericStack<string> stringStk;
	string exp = "";
	string t = "";
	char a, b;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == ',')
			continue;
		if (isOperand(s[i])) {
			charStk.push(s[i]);
		}
		else if (isOperator(s[i])) {
			while (!charStk.empty()) {
				if (!charStk.empty()) {
					t = charStk.tops() + t;
					charStk.pop();
				}
				if(!charStk.empty())
					t = s[i] + t;
				else if (charStk.empty() && !stringStk.empty()){
					if(i < s.length() - 1)
						if (isOperator(s[i + 1])) {

						}
						else {
							t = stringStk.tops() + s[i] + t;
							stringStk.pop();
						}
				}
			}
			if (i == s.length() - 1 && !stringStk.empty()) {
				while (!stringStk.empty()) {
					t = stringStk.tops() + t;
					stringStk.pop();
					if (!stringStk.empty())
						t = s[i] + t;
				}
				
			}
			stringStk.push("(" + t + ")");
			t = "";
		}
	}
	exp = stringStk.tops();
	stringStk.pop();
	return exp;
}

//return postfix notation
string toPostFix(string s) {
	GenericStack<char> stk;
	string exp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == ',')
			continue;
		if (isOperand(s[i])) {
			exp = exp + s[i];
		}
		else if (isOperator(s[i])) {
			while (!stk.empty() && isBiggerOp(stk.tops(), s[i])) {
				exp = exp + stk.tops();
				stk.pop();
			}
			stk.push(s[i]);
		}
		else if (s[i] == '(') {
			stk.push(s[i]);
		}
		else if (s[i] == ')') {
			while (!stk.empty() && stk.tops() != '(') {
				exp = exp + stk.tops();
				stk.pop();
			}
			stk.pop();
		}
	}
	while (!stk.empty()) {
		exp = exp + stk.tops();
		stk.pop();
	}
	return exp;
}
#endif // !PostFix_h

