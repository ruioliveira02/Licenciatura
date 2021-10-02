/*
 ============================================================================
 Name        : Ficha50.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void one()
{
	int x = 1;
	int big = 0;
	while(x != 0)
	{
		scanf("%d", &x);

		if(big < x)
			big = x;
	}

	printf("%d", big);
}

void two()
{
	double sum = 0.0;

	int count = 0;

	int x = -1;

	while(x != 0)
	{
		scanf("%d", &x);

		sum += x;
		++count;
	}

	sum = sum / count;

	printf("%f", sum);
}

void three()
{
	int first = 0, second = -1;

	int x = 1;

	while(x != 0)
	{
		scanf("%d", &x);

		if(x > first)
		{
			second = first;
			first = x;
		}
		else if(x > second)
		{
			second = x;
		}
	}

	printf("%d", second);
}

int bitsUm(unsigned int n)
{
	int count = 0;

	for(int i = 0; i < 32; i++)
	{
		if(n & (1 << i))
			++count;
	}

	return count;
}

int trailingZ(unsigned int n)
{
	for(int i = 0; i < 32; i++)
	{
		if((n & (1 << i)))
			return i;
	}
	return 32;
}

int qDig(unsigned int n)
{
	int count = 1;

	while(n >= 10)
	{
		n /= 10;
		++count;
	}

	return count;
}

char *strcat (char s1[], char s2[])
{
	char* result = malloc(strlen(s1) + strlen(s2) + 1);

	memcpy(result, s1, strlen(s1));
	memcpy(result, s2, strlen(s2));

	return result;
}

char *strcopy(char dest[], char source[])
{
	dest = malloc(strlen(source) + 1);

	for(int i = 0; i < strlen(source); i++)
		dest[i] = source[i];

	return dest;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int strcmp(char s1[], char s2[])
{
	for(int i = 0; i < min(strlen(s1), strlen(s2)); i++)
	{
		if(s1[i] < s2[i])
			return -1;
		else if(s1[i] > s2[i])
			return 1;
	}

	if(strlen(s1) == strlen(s2))
		return 0;
	else if(strlen(s1) < strlen(s2))
		return -1;
	else
		return 1;
}

char *strstr (char s1[], char s2[])
{
	int i = 0;
	int same = 0;
	while(i < strlen(s1))
	{
		if(s1[i] == s2[same])
			++same;
		else
			same = 0;

		if(same == strlen(s2))
			return (s1 + i - same - 1);

		++i;
	}

	return NULL;
}

void strrev (char s[])
{
	int len = strlen(s);

	for(int i = 0; i < len / 2; i++)
	{
		char ch = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = ch;
	}
}

int isVowel(char ch)
{
	char vowels[] = {'a', 'e','i','o','u', 'A','E','I','O','U'};

	int i;
	for(i = 0; i < 10; i++)
		if(vowels[i] == ch)
			return 1;

	return 0;
}

void strnoV (char t[]){
	int i;
	int s = strlen(t);

	printf("%d\n", s);

	//int removed = 0;
	for(i = 0; i < s; i++)
	{
		printf("%d\n", i);


		if(isVowel(t[i]))
		{
			int j;
			for(j = i; j < s; j++)
			{
				printf("%d %d\n", i, j);
				//t[0] = '0';
				if(j == s - 1)
				{
					t[j] = '\0';
				}
				else
				{
					t[j] = t[j + 1];
				}
			}
			printf("%d\n", i);
			--i;
		}
	}

	printf("%s\n", t);
	return;
}


void truncW (char t[], int n){
	int size = strlen(t);

	int i;
	int counter = 0;

	for(i = 0; i < size; i++)
	{
		if(t[i] == '\0')
			break;

		if(t[i] == ' ')
		{
			counter = 0;
		}
		else if(counter >= n)
		{
			printf("%s\n", t);
			int j;
			for(j = i; j < size; j++)
			{
				if(j == size - 1)
					t[j] = '\0';
				else
					t[j] = t[j + 1];
			}
			--i;
		}
		else
		{
			++counter;
		}

	}
}


char charMaisFreq(char s[])
{
	if(strlen(s) == 0)
		return 0;

	int result[256];

	for(int i = 0; i < 256; i++)
		result[i] = 0;

	for(int i = 0; i < strlen(s); i++)
		result[s[i]]++;

	char ans = '0';
	int count = 0;
	for(int i = 0; i < 256; i++)
		if(result[i] > count)
		{
			count = result[i];
			ans = i;
		}

	return ans;
}


int iguaisConsecutivos (char s[]) {

	if(strlen(s) == 0)
		return 0;

	int count = 1;

	int ans = 1;

	int i = 1;
	for(; i < strlen(s); i++)
	{
		if(s[i] == s[i - 1])
		{
			++count;
		}
		else
		{
			if(ans < count)
				ans = count;

			count = 1;
		}
	}

	if(ans < count)
		ans = count;

	return ans;
}




void resetChars(int* str)
{
	int i;
	for(i = 0; i < 256; i++)
		str[i] = 0;
}

int difConsecutivos(char s[])
{
	int charsUsed[256];

	resetChars(charsUsed);

	int count = 0;
	int ans = 0;

	int i;
	for(i = 0; i < strlen(s); i++)
	{
		int j;
		for(j = i; j < strlen(s); j++)
		{
			if(charsUsed[s[j]] == 0)
			{
				++count;
				charsUsed[s[j]] = 1;
			}
			else
			{
				if(ans < count)
					ans = count;

				count = 0;

				resetChars(charsUsed);
				break;
			}
		}

	}

	if(ans < count)
		ans = count;

	return ans;
}



int maiorPrefixo (char s1 [], char s2 []) {
	int i;

	int min = (strlen(s1) < strlen(s2)) ? strlen(s1) : strlen(s2);

	for(i = 0; i < min; i++)
	{
		if(s1[i] != s2[i])
			break;
	}

	return i;
}




int maiorSufixo (char s1 [], char s2 []) {
	int size1 = strlen(s1), size2 = strlen(s2);

	int min = (size1 < size2) ? size1 : size2;

	int i;
	for(i = 0; i < min; i++)
	{
		if(s1[size1 - 1 - i] != s2[size2 - 1 - i])
			break;
	}

	return i;
}



int sufPref (char s1[], char s2[]) {

	int size1 = strlen(s1);
	int size2 = strlen(s2);

	int size = (size1 < size2) ? size1 : size2;

	int ans = 0;

	int i;
	for(i = 1; i <= size; i++)
	{
		int j;
		int matches = 1;
		for(j = 0; j < i; j++)
		{
			if(s1[size1 - i + j] != s2[j])
			{
				matches = 0;
				break;
			}
		}


		if(matches)
			ans = i;
	}

	return ans;
}



int contaPal (char s[]) {
	int ans = 0;

	int letterCount = 0;

	int i;
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] == ' ' || s[i] == '\n')
		{
			if(letterCount > 0)
				++ans;

			letterCount = 0;
		}
		else
		{
			++letterCount;
		}
	}

	if(letterCount > 0)
		++ans;

	return ans;
}



int contaVogais (char s[]) {
	int ans = 0;

	int i;
	for(i = 0; i < strlen(s); i++)
	{
		if(isVowel(s[i]))
			++ans;
	}

	return ans;
}



int contida (char a[], char b[]) {

	int i;
	for(i = 0; i < strlen(a); i++)
	{
		int j;
		int found = 0;
		for(j = 0; j < strlen(b); j++)
		{
			if(b[j] == a[i])
			{
				found = 1;
				break;
			}
		}

		if(!found)
			return 0;
	}


	return 1;
}



int palindroma (char s[]) {
	int i;

	int size = strlen(s);

	for(i = 0; i < size / 2; i++)
	{
		if(s[i] != s[size - 1 - i])
			return 0;
	}

	return 1;
}


int remRep (char texto []) {

	int i;
	int size = strlen(texto);

	for(i = 0; i < size - 1; i++)
	{
		while(texto[i + 1] == texto[i])
		{
			int h;
			for(h = i + 1; h < size; h++)
			{
				if(h == size - 1)
					texto[h] = '\0';
				else
					texto[h] = texto[h + 1];
			}
			--size;
		}
	}

	return size;
}




int limpaEspacos (char texto[]) {
	int size = strlen(texto);

	int i;
	for(i = 0; i < size - 1; i++)
	{
		if(texto[i] == ' ')
		{
			while(texto[i + 1] == ' ')
			{
				int h;
				for(h = i + 1; h < size; h++)
				{
					if(h == size - 1)
						texto[h] = '\0';
					else
						texto[h] = texto[h + 1];
				}
				--size;
			}
		}
	}

	return size;
}


void insere (int s[], int N, int x){

	int l = 0, r = N - 1;

	while(r - l > 1)
	{
		int mid = (l + r) / 2;

		if(s[mid] > x)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}

	int j;


	if(s[0] > x)
		l = -1;

	if(s[N - 1] < x)
		l = N - 1;

	for(j = N; j >= l + 1; j--)
		s[j] = s[j - 1];

	s[l + 1] = x;
}





void merge (int r [], int a[], int b[], int na, int nb){
	int i;

	for(i = 0; i < na; i++)
	{
		r[i] = a[i];
	}

	for(i = 0; i < nb; i++)
	{
		insere(r, na + i, b[i]);
	}

}



int crescente (int a[], int i, int j){

	for(++i; i <= j;i++)
	{
		if(a[i - 1] > a[i])
			return 0;
	}

	return 1;
}




int retiraNeg (int v[], int N){
	int r = N;

	int i = 0;

	while(i < r)
	{
		if(v[i] < 0)
		{
			int j = i;

			for(; j < r; j++)
			{
				v[j] = v[j + 1];
			}

			--r;
			--i;
		}
		++i;
	}

	return r;
}


int menosFreq (int v[], int N){

	int record = N + 1;
	int current = v[0];
	int count = 1;
	int ans = -1;

	int i;
	for(i = 1; i < N; i++)
	{
		if(v[i] != current)
		{
			if(record > count)
			{
				record = count;
				ans = current;
			}

			count = 1;
			current = v[i];
		}
		else
		{
			++count;
		}
	}

	if(record > count)
		ans = current;

	return ans;
}



int maisFreq (int v[], int N){
	int record = -1;
	int current = v[0];
	int count = 1;
	int ans = -1;

	int i;
	for(i = 1; i < N; i++)
	{
		if(v[i] != current)
		{
			if(record < count)
			{
				record = count;
				ans = current;
			}

			count = 1;
			current = v[i];
		}
		else
		{
			++count;
		}
	}

	if(record < count)
		ans = current;

	return ans;
}



int maxCresc (int v[], int N) {
	int r = -1;

	int count = 1;

	int i;
	for(i = 1; i < N; i++)
	{
		if(v[i] < v[i - 1])
		{
			if(count > r)
				r = count;

			count = 1;
		}
		else
		{
			count++;
		}
	}

	if(count > r)
		r = count;

	return r;
}



int elimRep (int v[], int N) {

	int size = N;

	int i;
	for(i = 0; i < size; i++)
	{
		int j;
		for(j = i + 1; j < size; j++)
		{
			if(v[i] == v[j])
			{
				int h;
				for(h = j; h < size; h++)
				{
					v[h] = v[h + 1];
				}


				--size;
				--j;
			}
		}
	}


	return size;
}




int elimRepOrd (int v[], int N) {

	int size = N;

	int i;
	for(i = 0; i < size; i++)
	{
		int j;
		for(j = i + 1; j < size; j++)
		{
			if(v[i] == v[j])
			{
				int h;
				for(h = j; h < size; h++)
				{
					v[h] = v[h + 1];
				}


				--size;
				--j;
			}
			else
			{
				break;
			}
		}
	}


	return size;
}



//PERGUNTAR RESTRICAO DE NUMERO DE ELEMENTOS
int comunsOrd (int a[], int na, int b[], int nb){
	int r = 0;

	int i = 0, j = 0;

	while(i < na && j < nb)
	{
		if(a[i] < b[j])
			++i;
		else if(a[i] > b[j])
			++j;
		else
		{
			++r;
			++i;
			++j;
		}
	}

	return r;
}


int minInd (int v[], int n) {

   int r = 0;
   int min = v[0];

   int i;
   for(i = 0; i < n; i++)
   {
       if(v[i] < min)
       {
           r = i;
           min = v[i];
       }
   }

   return r;
}




void somasAc (int v[], int Ac [], int N){

   int sum = 0;

   int i;

   for(i = 0; i < N; i++)
   {
       sum += v[i];
       Ac[i] = sum;
   }
}




int triSup (int N, int m [N][N]) {

    int i;
    for(i = 0; i < N; i++)
    {
        int j;
        for(j = 0; j < i; j++)
        {
            if(m[i][j] != 0)
                return 0;
        }
    }

    return 1;
}



void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i, j;

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            a[i][j] += b[i][j];
    return;
}


int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int c=0;

       int i;
       for(i = 0; i < N; i++)
        r[i] = v1[i] | v2[i];

       return c;
   }



int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0;

    int i;
    for(i = 0; i < N; i++)
     r[i] = v1[i] & v2[i];

    return c;
}



void transposta (int N, float m [N][N]) {

    int i;

    for(i = 0; i < N; i++)
    {
        int j;
        for(j = 0; j < i; j++)
        {
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }

    return;
}



int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int c = 0;

       int i;
       for(i = 0; i < N; i++)
           r[i] = min(v1[i], v2[i]);

       return c;
   }


int max(int a, int b)
{
    return (a > b) ? a : b;
}

   int unionMSet (int N, int v1[N], int v2[N], int r[N]){
     int c = 0;

       int i;
       for(i = 0; i < N; i++)
           r[i] = max(v1[i], v2[i]);

       return c;
   }




   int cardinalMSet (int N, int v[N]){
      	  int c=0;

      	  int i;

      	  for(i = 0; i < N; i++)
      	    c += v[i];

      	  return c;
      }


int comuns (int a[], int na, int b[], int nb){
     int r=0;

     int used[nb];

     int i;

     for(i = 0; i < nb; i++)
       used[i] = 0;


       for(i = 0; i < na; i++)
       {
           int j;
           for(j = 0; j < nb; j++)
           {
               if(a[i] == b[j] && !used[j])
               {
                   ++r;
                   //used[j] = 1;
                   break;
               }
           }
       }


     return r;
  }



typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {int x, y;} Posicao;



Posicao posFinal (Posicao inicial, Movimento mov[], int N){

   int i;

   for(i = 0; i < N; i++)
   {
       if(mov[i] == 0)
           inicial.y++;
        else if(mov[i] == 2)
           inicial.y--;
        else if(mov[i] == 1)
           inicial.x--;
        else
            inicial.x++;
   }

    return inicial;
}




int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    // dadas as posições inicial e final do robot, preenche o array mov com os movimentos
    // suficientes para que o robot passe de uma posição para a outra.
    // A função deverá preencher no máximo N elementos do array e
    // retornar o nú́mero de elementos preenchidos.úú
    // Se não for possível atingir a posição final com N movimentos,
    // a função deverá retornar um nú́mero negativo.


    int xDelta = abs(inicial.x - final.x);
    int yDelta = abs(inicial.y - final.y);


    if(xDelta + yDelta > N)
        return -1;


    int index = 0;
    int i;

    for(i = 0; i < xDelta; i++)
    {
        if(inicial.x > final.x)
            mov[index] = 1;
        else
            mov[index] = 3;


        ++index;
    }



    for(i = 0; i < yDelta; i++)
    {
        if(inicial.y > final.y)
            mov[index] = 2;
        else
            mov[index] = 0;


        ++index;
    }


    return xDelta + yDelta;
}


int dist(Posicao p)
{
    return p.x * p.x + p.y * p.y;
}

int maiscentral (Posicao pos[], int N) {

    int ans = 0;

    int distance = dist(pos[0]);

    int i;
    for(i = 1; i < N; i++)
    {
        int d = dist(pos[i]);

        if(d < distance)
        {
            distance = d;
            ans = i;
        }
    }

    return ans;
}


int vizinhos (Posicao p, Posicao pos[], int N) {
    int ans = 0;
    int i;
    for(i = 0; i < N; i++)
    {
        if(abs(pos[i].x - p.x) + abs(pos[i].y - p.y) == 1)
            ++ans;
    }

    return ans;
}



int main()
{
	char c[] = "aAeEiIoOuU aAeEiIoOuU ";
	strnoV(c);
	printf("%c", charMaisFreq("olaa"));

	return 0;
}
