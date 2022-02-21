package com.company;

public class Ficha1 {
    public int maximoNumeros(int a, int b) {
        return (a < b) ? a : b;
    }

    public String criaDescricaoConta(String nome, double saldo) {
        return nome + ": " + Double.toString(saldo) + "€";
    }

    public double eurosParaLibras(double valor, double taxaConversao) {
        return valor * taxaConversao;
    }

    public long factorial(int num) {
        long result = 1;

        for(int i = 2; i <= num; i++) {
            result *= i;
        }


        return result;
    }
}
