package com.company;

public class Circulo {
    private double x;
    private double y;
    private double raio;

    public Circulo() {

    }

    public Circulo(double x, double y, double raio) {
        if(raio <= 0) {
            throw new IllegalArgumentException("Radius must be positive");
        }
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    public Circulo(Circulo circulo) {
        this.x = circulo.x;
        this.y = circulo.y;
        this.raio = circulo.raio;
    }


    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    public double getRaio() {
        return this.raio;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setRaio(double raio) {
        if(raio <= 0) {
            throw new IllegalArgumentException("Radius must be positive");
        }

        this.raio = raio;
    }

    public void alteraCentro(double x, double y) {
        setX(x);
        setY(y);
    }

    public double calculaArea() {
        return Math.pow(this.raio, 2) * Math.PI;
    }

    public double calculaPerimetro() {
        return Math.PI * this.raio * 2;
    }

    public String toString() {
        return "(" + Double.toString(x) + "," + Double.toString(y) + "), raio=" + Double.toString(raio);
    }

    public boolean equals(Object o) {
        if(o == this)
            return true;

        if(o == null || o.getClass() != getClass())
            return false;

        Circulo circulo = (Circulo)o;

        return circulo.x == x && circulo.y == y && circulo.raio == raio;
    }
}
