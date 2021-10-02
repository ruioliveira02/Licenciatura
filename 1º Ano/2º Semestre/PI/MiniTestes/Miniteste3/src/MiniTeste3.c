/*
 ============================================================================
 Name        : MiniTeste3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int hash(char* str) {
	int index = 1, hash = 0;

	while(*str) {
		hash += index * (*str);
		++index;
		++str;
	}

	return hash;
}


int hash1 (char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}


int next(char s[], int n) {
 while (n > 0) {
   n--;
   if (s[n] < 'z') {
     s[n]++;
     if(s[n] > '9' && s[n] < 'a')
    	 s[n] = 'a';
     return 1;
   } else {
     s[n] = '0';
   }
 }
 return 0;
}



int main(void) {

	printf("%d\n", hash("programacao imperativa"));

	char str[10] = "";
	for(int i = 0; i < 10; i++)
		str[i] = '\0';
	int n = 0;
	while(hash1(str) != 370) {
		int x = next(str, n);

		if(x == 0)
			++n;
	}

	printf("%d %s\n", hash1(str), str);

	return EXIT_SUCCESS;
}
