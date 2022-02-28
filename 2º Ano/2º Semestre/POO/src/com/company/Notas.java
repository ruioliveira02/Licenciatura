package com.company;

public class Notas {

    private int[][] notas;
    public Notas(int alunos, int ucs) {
        this.notas = new int[alunos][ucs];
    }

    public updateGrade(int aluno, int uc, int grade) {
        this.notas[aluno][uc] = grade;
    }

    public int sumGrades(int uc) {
        int sum = 0;

        for(int grade : this.notas[uc])
            sum += grade;

        return sum;
    }

    public float averageStudent(int aluno) {
        
    }

}
