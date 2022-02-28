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

    private boolean elem(int[] arr, int x, int len) {
        for(int i = 0; i < len; i++) {
            if(arr[i] == x)
                return true;
        }
        return false;
    }

    public int[] sort(int[] a) {
        if(a.length == 0)
            return a;

        int lengthL = a.length / 2;
        int lengthR = a.length - lengthL - 1;

        int[] _left = new int[lengthL];
        int[] _right = new int[lengthR];

        System.arraycopy(a, 0, _left, 0, lengthL);
        System.arraycopy(a, lengthL + 2, _right,0, lengthR);

        int[] left = sort(_left);
        int[] right = sort(_right);

        int[] result = new int[a.length];
        int i = 0;
        for(; i < lengthL; i++)
            result[i] = left[i];

        result[i] = a[i];

        i++;
        for(; i < a.length; i++)
            result[i] = right[i];

        return result;
    }

    public int[] comuns(int[] a, int[] b) {
        int[] res = new int[a.length];
        int count = 0;
        for(int i = 0; i < a.length; i++) {
            if(elem(b, a[i], b.length) && !elem(res, a[i], count)) {
                res[count] = a[i];
                count++;
            }
        }


        int[] resultado = new int[count];
        System.arraycopy(res, 0, resultado, 0, count);
        return resultado;
    }
}
