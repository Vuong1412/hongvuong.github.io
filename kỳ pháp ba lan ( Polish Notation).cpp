#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
// kiem tra c co phai toan tu hay khong
bool isoperator(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
// xac dinh dau uu tien
int precedence(char op) {
	if (op == '-' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;

}
// chuyen bieu thuc trung to sang hau to
string infixtopostfix(string infix) {
	stack<char> operators; // tao stack luu tru toan tu
	string postfix = ""; //Chuoi luu bieu thuc hau to ket qua

	for (char c : infix) {// duyet ki tu trong bieu thuc
		if (isdigit(c)) {// neu chu so(digit) 
			postfix += c; // neu la so (0-9) thi them vao postfix(hau to)
		}
		else if (isoperator(c)) {
			while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
				postfix += operators.top();
				operators.pop();
			}
			operators.push(c);
		}
	}
	while (!operators.empty()) {
		postfix += operators.top();
		operators.pop();
	}
	return postfix;
}
int evaluatepostfix(string postfix) {
	stack<int> values;
	for (char c : postfix) {
		if (isdigit(c)) {
			values.push(c - '0');
		}
		else if (isoperator(c)) {
			int b = values.top();values.pop();
			int a = values.top();values.pop();
			switch (c) {
			case'+': values.push(a + b);
				break;
			case '-': values.push(a - b);
				break;
			case '*': values.push(a * b);
				break;
			case '/': values.push(a / b);

			}
		}
	}
	return values.top();
}
