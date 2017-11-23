#pragma once
#ifndef GenericStack_h
#define GenericStack_h
template <typename T>
class GenericStack{

	class Node {
	public:
		T data;
		Node *next;
	};

private:
	Node *top;
public:
	GenericStack() {
		top = nullptr;
	}
	GenericStack(T e) {
		top = new Node(e);
	}
	//add to the top of stack
	void push(T e) {
		Node *newNode = new Node;
		if (top == nullptr) {
			newNode->data = e;
			newNode->next = nullptr;
			top = newNode;
		}
		else {
			newNode->data = e;
			newNode->next = top;
			top = newNode;
		}
	}
	//remove the top of stack
	void pop() {
		if (top == nullptr) {
			cout << "Stack is empty, cant pop" << endl;
		}
		else {
			Node *old = top;
			top = top->next;
			delete(old);
		}
	}
	//return top of stack
	T tops() {
		if (top == nullptr)
			return NULL;
		else {
			return top->data;
		}
	}
	//return if empty
	bool empty() {
		if (top != nullptr)
			return false;
		return true;
	}
	//print stack
	void print() {
		Node *temp;
		temp = top;
		while (temp != nullptr) {
			cout << temp->data;
			temp = temp->next;
			if (temp != NULL)
				cout << ", ";
		}
	}

};
#endif // !GenericStack_h

