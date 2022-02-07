#pragma once
#include <string.h>
#include <stdio.h>

class Number {
private:
	char* digit;
	int size;
public:


	inline int GetSize()
	{
		return size;
	}
//#pragma region Region_1
//#pragma endregion Region_1

	Number(char* c,int s=-1) {
		if (c == NULL) throw 0;		
		size = (s==-1)?strlen(c):s;
		if (size==0) throw 0;
		digit = new char[size + 1];
		strcpy(c, digit, size + 1 );
		for (int i = 0; i < size; i++)
		{
			digit[i] -= '0';
		}
	}

	Number operator *(int newsize) { //add some 0 to the end
		if (newsize <= size) return *this;
		char* c = new char[newsize + 1];		
		for (int i = 0; i < newsize-size; i++) {
			c[i] = 0;
		}	
		strcpy(digit, &c[newsize-size], size);
		c[newsize] = 0;
		delete digit;
		digit = new char[newsize + 1];
		size=newsize;
		strcpy(c, digit, size + 1);
		return *this;
	}

	Number operator +(Number b) {		
		if (this->size != b.GetSize()) throw 1;
		char* c = new char[size + 1]; 
		c[size] = 0;
		for (int i = 0; i < size; i++){
			c[i] = (digit[i] ^ b[i])+'0';
		}
		return Number(c,size);
	}

	Number operator -(Number b) {

	}

	Number operator <<(int b) {
		char* c = new char[size + 2];
		strcpy(digit,c, size + 1);
		c[size] = b ;
		c[size + 1] = 0;

		delete digit;
		digit=new char[size + 2];
		size++;		
		strcpy(c,digit, size + 1);
		
		return *this;
	}

	int operator [](int i) { // Numeration from hiest digit (as in String): "01" -> Num[0]=0; 
		if (size > i) return digit[i];
		return -1;
	}

	bool operator ==(Number b) {
		if (size != b.GetSize())return false;
		for (int i = 0; i < size; i++)
		{
			if (this->digit[i] != b[i])return false;
		}
		return true;
	}

	bool operator !=(Number b) {
		if (size != b.GetSize())return true;
		for (int i = 0; i < size; i++)
		{
			if (this->digit[i] != b[i])return true;
		}
		return false;
	}

	void V() {
		for (int i = 0; i < size; i++)
		{
			printf("%d",digit[i]);
		}
		printf("\n");	
	}
	void strcpy(char* s, char* d, int n)
	{
		for (int i = 0; i < n; i++)
		{
			d[i] = s[i];
		}
	}
};

