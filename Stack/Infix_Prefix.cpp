#include<iostream>
#include<string>
using namespace std;

char s[100];
int tos, MaxSize;


//Stack ADT's
void initStack(int size){
	MaxSize = size;
	tos = -1;
}

void push(char c){
	tos++;
	s[tos] = c;
}

char pop(){
	char c;
	c = s[tos];
	tos--;
	return c;
}

int isFull(){
	if (tos == (MaxSize - 1))
		return 1;
	else return 0;
}

int isEmpty(){
	if (tos == -1)
		return 1;
	else return 0;
}

char atTop(){
	return s[tos];
}

int prec(char ch){
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/' || ch == '%')
		return 2;
	else return 0;
}



void reverse(char post[], int len){
	int i;
	for (i = len; i > -1; i--)
		cout << post[i];
	getchar();
}

int main(){
	char in[100], post[100], c;
	int pi, i;
	cout << "Enter infix :" << endl;
	cin >> in;
	initStack(strlen(in));
	pi = 0;

	

	for (i = strlen(in)-1; i >= 0; i--) {

		c = in[i];
		switch (c){
		case ')': push(c);
			break;

		case '(': while (s[tos] != ')') {
			post[pi] = pop();
			pi++;
		}
				  c = pop();
				  break;
		case '+': case '-': case '*': case '/':
			while ((prec(c) < prec(s[tos])) && (isEmpty() != 1)){
				post[pi] = pop();
				pi++;
			}
			push(c);
			break;
		default:post[pi] = c;
			pi++;
			break;
		}
	}

	while (isEmpty() != 1){
		post[pi] == pop();
		pi++;
	}

	reverse(post, strlen(in));
	system("pause");
	return 0;
}
