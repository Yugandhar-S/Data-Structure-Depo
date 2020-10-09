#include<iostream>
using namespace std;

int arr[100], tos, MaxSize;

//Stack initialisation
void initStack(){
	MaxSize = 10;

}

void push(int e){
	tos++;
	arr[tos] = e;
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
	else
		return 0;
}

int isEmpty(){
	if (tos == -1)
		return 1;
	else return 0;
}

void printStack(){
	int i;
	for (i = tos; i > -1; i--)
		cout << arr[i] << endl;

}

int atTop(){
	return arr[tos];
}


void decimalToBinary(int number){
	while (number != 0){
		int rem = number % 2;
		number = number / 2;
		push(rem);
	}

	while (isEmpty() != 1){
		int item;
		item=pop();
		cout << item;
	}
	getchar();
}

int main(){
	int number;
	
		cout << "Enter Number"<<endl;
		cin >> number;
		decimalToBinary(number);
		getchar();


}