package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Ficha1 ficha1 = new Ficha1();

        Scanner scanner = new Scanner(System.in);

        System.out.println(ficha1.factorial(5000));
    }
}
