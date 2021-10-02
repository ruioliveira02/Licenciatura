#include <stdio.h>

int isVowel(char ch)
{
    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    
    int i, res = 0;
    for(i = 0; i < 10; i++)
        if(ch == vowels[i])
            res = 1;
    return res;
}

int contaVogais (char *s) {
    int i = 0;
    int res = 0;
    while(s[i] != '\0')
    {
        if(isVowel(s[i]))
            ++res;
        ++i;
    }
    return res;
}

int retiraVogaisRep (char *s){
    int write = 1, read = 1;
    
    int removed = 0;
    while(s[read] != '\0')
    {
        if(isVowel(s[read]) && s[read] == s[read - 1])
        {
            ++removed;
            ++read;
        }
        else
        {
            s[write] = s[read];
            ++write;
            ++read;
        }
    }
    
    s[write] = '\0';
    
    return removed;
}

int duplicaVogais (char *s){
    int added = contaVogais(s);
    
    int size = strlen(s);
    int j = size + added;
    
    s[j--] = '\0';
    
    int i = size - 1;
    
    while(i >= 0)
    {
        if(isVowel(s[i]))
        {
            s[j--] = s[i];
            s[j--] = s[i];
        }
        else
        {
            s[j--] = s[i];
        }
        
        --i;
    }
    
    
    return added;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));
    
    x = retiraVogaisRep (s1);
    printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s1);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
    
    printf ("\nFim dos testes\n");

    return 0;
}