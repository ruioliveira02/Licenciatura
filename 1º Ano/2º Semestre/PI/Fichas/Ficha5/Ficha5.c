#include <stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

typedef int (*function)(Aluno, Aluno);

int nota (Aluno a) {
    float nota = 0.0;
    int i;
    
    for(i = 0; i < 6; i++) {
        nota += (float)a.miniT[i];
    }
    
    nota /= 6.0;
    
    nota *= 0.3;
    
    nota += a.teste * 0.7;
    
    return nota;
}
int procuraNum (int num, Aluno t[], int N) {
    int l = 0, r = N - 1;
    
    while(r > l) {
        int mid = (l + r) / 2;
        if(t[mid].numero >= num)
            r = mid;
        else
            l = mid + 1;
    }
    
    if(t[l].numero == num)
        return l;
    else
        return -1;
}

void mergePorNum(Aluno *l, Aluno *r, Aluno *ar, int X, int Y) {
    int a = 0, b = 0, c = 0;
    
    Aluno temp[X + Y];
    
    while(a < X && b < Y) {
        if(l[a].numero < r[b].numero)
            temp[c++] = l[a++];
        else
            temp[c++] = r[b++];
    }
    
    while(a < X) 
        temp[c++] = l[a++];
        
    while(b < Y)
        temp[c++] = r[b++];
        
        
    int i;
    
    for(i = 0; i < (X + Y); i++) {
        ar[i] = temp[i];
    }
}

void ordenaPorNum (Aluno t[], int N) {
    
    if(N > 1) {
        ordenaPorNum(t, N / 2);
        ordenaPorNum(t + N / 2, N - (N / 2));
        
        mergePorNum(t, t + N / 2, t, N / 2, N - (N / 2));
    }
}
int procuraNumInd (int num, int ind[], Aluno t[], int N) {
    int l = 0, r = N - 1;
    
    while(r > l) {
        int mid = (l + r) / 2;
        if(t[ind[mid]].numero >= num)
            r = mid;
        else
            l = mid + 1;
    }
    
    if(t[ind[l]].numero == num)
        return ind[l];
    else
        return -1;
}



int comparaNum(Aluno a, Aluno b) {
    return a.numero < b.numero;
}

int comparaNome(Aluno a, Aluno b) {
    int i = 0, j = 0;
    
    while(a.nome[i] && b.nome[j]) {
        if(b.nome[j] < a.nome[i])
            return 0;
        else if(b.nome[j] > a.nome[i])
            return 1;
            
        ++i;
        ++j;
    }
    
    return (i < j);
}

void merge(Aluno t[], int ind1[], int ind2[], int size1, int size2, int ind[], function f) {
    int a = 0, b = 0, c = 0;
    
    while(a < size1 && b < size2) {
        if(f(t[ind1[a]], t[size1 + ind2[b]]))
            ind[c++] = ind1[a++];
        else
            ind[c++] = ind2[b++] + size1;
    }
    
    while(a < size1)
        ind[c++] = ind1[a++];
        
    while(b < size2)
        ind[c++] = ind2[b++] + size1;
}


void criaIndPorNum (Aluno t [], int N, int ind[]) {
    if(N > 1) {
        int size1 = N / 2, size2 = N - N / 2;
        
        int ind1[size1], ind2[size2];
        
        criaIndPorNum(t, size1, ind1);
        criaIndPorNum(t + size1, size2, ind2);
        
        merge(t, ind1, ind2, size1, size2, ind, comparaNum);
    } else {
        ind[0] = 0;
    }
}
void criaIndPorNome (Aluno t [], int N, int ind[]) {
    if(N > 1) {
        int size1 = N / 2, size2 = N - N / 2;
        
        int ind1[size1], ind2[size2];
        
        criaIndPorNum(t, size1, ind1);
        criaIndPorNum(t + size1, size2, ind2);
        
        merge(t, ind1, ind2, size1, size2, ind, comparaNome);
    } else {
        ind[0] = 0;
    }
}

void imprimeTurmaInd (int ind[], Aluno t[], int N) {
    int i;
    
    for(i = 0; i < N; i++) {
        printf("%d %s ", t[ind[i]].numero, t[ind[i]].nome);
        
        int j;
        for(j = 0; j < 6; j++) 
            printf("%d ", t[ind[i]].miniT[j]);
            
        printf("%f\n", t[ind[i]].teste);
    }
}

void dumpV (Aluno v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i].numero);
}

int main() {
    Aluno Turma1 [4] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                      ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
                      ,{7777, "Maria", {2,2,2,2,2,1}, 18.5}
                      ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                      };
                      
    Aluno Turma2 [4] = {{1111, "André", {2,1,0,2,2,2}, 10.5}
                      ,{2222, "Joana", {2,2,2,1,0,0}, 14.5}
                      ,{2244, "Maria", {2,2,2,2,2,1}, 18.5}
                      ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                      };
                      
    printf("%d\n", procuraNum(1111, Turma2, 4));
    
    ordenaPorNum(Turma1, 4);
    
    int ind[4];
    
    criaIndPorNome(Turma2, 4, ind);
    
    printf("%d\n", procuraNumInd(1121, ind, Turma2, 4));

    imprimeTurmaInd(ind, Turma2, 4);

    dumpV(Turma1, 4);
    
    return 0;
}

