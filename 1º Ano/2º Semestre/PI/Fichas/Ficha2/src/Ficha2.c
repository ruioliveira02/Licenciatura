/*
 ============================================================================
 Name        : Ficha2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


float multInt1 (int n, float m){
	float r = 0.0;

	int i;
	for(i = 0; i < n; i++)
		r += m;

	return r;
}

float multInt2 (int n, float m){
	float r = 0;

	while(n > 0)
	{
		if(n & 1){
			r += m;
		}


		n /= 2;
		m *= 2.0;
	}

	return r;
}

float multInt3 (int n, float m, int *count){
	float r = 0;

	while(n > 0)
	{
		if(n & 1){
			r += m;
			(*count)++;
		}


		n /= 2;
		m *= 2.0;
		(*count)++;
	}

	return r;
}




int mdc1 (int a, int b){
	if(b < a) {
		int c = a;
		a = b;
		b = a;
	}

	int ans = 1;

	int i;
	for(i = 1; i <= a; i++)
	{
		if((a % i == 0) && (b % i == 0))
			ans = i;
	}

	return ans;
}
int mdc2 (int a, int b){
	if(a == b)
		return a;
	else if(a > b)
		return mdc2(a - b, b);
	else
		return mdc2(a, b - a);
}
int mdc3 (int a, int b, int *count){
	(*count)++;
	if(a == b)
		return a;
	else if(a > b)
		return mdc3(a - b, b, count);
	else
		return mdc3(a, b - a, count);
}
int mdc4 (int a, int b, int *count){
	(*count)++;
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	else if(a > b)
		return mdc4(a % b, b, count);
	else
		return mdc4(a, b % a, count);
}




int main() {
	return 0;
}
