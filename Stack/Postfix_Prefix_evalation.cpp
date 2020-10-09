#include<iostream>
#include<string>
using namespace std;

int  tos, MaxSize;
int arr[100];

void  initStack(int size){
	MaxSize = size;
	tos = -1;
}

//Stack ADT's

void push(int num){
	tos++;
	arr[tos] = num;
}

int pop(){
	int temp;
	temp = arr[tos];
	tos--;
	return temp;
}

int isFull(){
	if (tos == MaxSize - 1)
		return 1;
	else return 0;
}

int isEmpty(){
	if (tos == -1)
		return 1;
	else return 0;
}

int atTop(){
	return arr[tos];
}

int evalPost(char s[]){
	int result;
	int length = strlen(s);

	for (int i = 0; i < length; i++){
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			int right, left;
			char ch=s[i];
			right = pop();
			left = pop();
			switch (ch)
			{
			case '+': result = left + right; break;
			case '-':result = left - right; break;
			case '*':result = left*right; break;
			case '/':result = left / right; break;
			default:
				break;
			}

			push(result);
		}

		if (isdigit(s[i]))
			push(s[i]-'0');
	}

	return result;

}

int evalPrefix(char s[]){
	int result;
	int length = strlen(s);

	for (int i = length - 1; i >= 0; i--){
		if (isdigit(s[i]))
			push(s[i] - '0');

		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			int left = pop();
			int right = pop();
			char ch = s[i];

			switch (ch)
			{
			case '+':result = left + right; break;
			case '-':result = left - right; break;
			case '*':result = left * right; break;
			case '/':result = left / right; break;
			default:
				break;
			}

			push(result);
		}

	}

	return result;
}

int main(){
	int result;
	char str[] = "-+5*231";
	char str1[] = "52+41-*";
	cout <<"Post fix evaluation is "<< evalPost(str1) << endl;
	cout <<"Prefix evaluation is "<< evalPrefix(str) << endl;
	system("pause");
	return 0;


}