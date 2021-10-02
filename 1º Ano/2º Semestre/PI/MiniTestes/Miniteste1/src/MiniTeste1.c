/*
 ============================================================================
 Name        : MiniTeste1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int func(int x) {
  int r = 0;
  while (x > 0) {
    r += 2;
    x = x - r;
  }
  return r;
}


void two()
{
	int x,y;
	for (y=0;y<8;y++) {
	  for (x=0;x<8;x++) {
	    if (x - y == 0){
	    	putchar('#');
	    }
	    else putchar('.');
	  }
	  putchar('\n');
	}
}







int main() {

	two();
	int count = 0;
	for(int i = 0; i < 10000000; i++)
	{
		if(func(i) == 4)
			++count;
	}

	printf("%d", count);

	return EXIT_SUCCESS;
}
