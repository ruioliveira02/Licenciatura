package com.company;

public class Main {

    public static void main(String[] args) {
        LinhaEncomenda linha = new LinhaEncomenda();
        linha.setOrderedAmount(1);
	linha.setPrice(69420);
        linha.setTax(42);
        linha.setDiscount(42);
        linha.setProduct("Posinhos do Bace");
        linha.setDescription("Os posinhos mágicos que o Bace usa quando programa despois da meia noite");
        System.out.println(linha.toString());
    }
}
