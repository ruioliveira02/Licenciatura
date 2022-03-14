package com.company;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Encomenda {
    private ArrayList<LinhaEncomenda> linhas;

    private String nomeCliente;
    private String nome;
    private int nif;
    private String morada;
    private int numero;
    private Date data;

    public Encomenda() {
        linhas = new ArrayList<LinhaEncomenda>();
    }

    public Encomenda(ArrayList<LinhaEncomenda> linhas, String nomeCliente, String nome, int nif, String morada, int numero, Date data) {
        this.linhas = new ArrayList<LinhaEncomenda>();

        for(LinhaEncomenda le : linhas) {
            this.linhas.add(new LinhaEncomenda(le));
        }

        this.nomeCliente = nomeCliente;
        this.nome = nome;
        this.nif = nif;
        this.morada = morada;
        this.numero = numero;
        this.data = data;
    }

    public Encomenda(Encomenda encomenda) {
        this(encomenda.linhas, encomenda.nomeCliente, encomenda.nome, encomenda.nif, encomenda.morada, encomenda.numero, encomenda.data);
    }

    public int getNif() {
        return nif;
    }

    public int getNumero() {
        return numero;
    }

    public String getNomeCliente() {
        return nomeCliente;
    }

    public String getMorada() {
        return morada;
    }

    public String getNome() {
        return nome;
    }

    public LinhaEncomenda getLinha(int index) {
        return (LinhaEncomenda) linhas.get(index).clone();
    }

    public List<LinhaEncomenda> getLinhas() {
        ArrayList<LinhaEncomenda> resultado = new ArrayList<LinhaEncomenda>();

        for(LinhaEncomenda le : this.linhas) {
            resultado.add(new LinhaEncomenda(le));
        }

        return resultado;
    }

    public double calculaValorTotal() {
        double resultado = 0.0;

        for(LinhaEncomenda le : linhas)
            resultado += le.calculaValorLinhaEnc();

        return resultado;
    }

    public double calculaValorDesconto() {
        double resultado = 0.0;

        for(LinhaEncomenda le : linhas)
            resultado += le.calculaValorDesconto();

        return resultado;
    }

    public boolean equals(Object o) {
        if(o == this)
            return true;

        if(o == null || o.getClass() != this.getClass())
            return false;

        Encomenda encomenda = (Encomenda)o;
        int size = encomenda.linhas.size();

        if(this.linhas.size() != size)
            return false;

        for(int i = 0; i < size; i++) {
            if(this.linhas.get(i) != encomenda.linhas.get(i))
                return false;
        }

        return this.nomeCliente.equals(encomenda.nomeCliente) && this.nif == encomenda.nif && this.morada.equals(encomenda.morada) && this.numero == encomenda.numero
                && this.data.equals(encomenda.data) && this.nome.equals(encomenda.nome);
    }

    public Object clone() {
        return (Object)new Encomenda(this);
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append("====Encomenda====\n");

        for(LinhaEncomenda le : this.linhas) {
            stringBuilder.append("==Linha==\n");
            stringBuilder.append(le.toString());
            stringBuilder.append("=========\n");
        }

        return stringBuilder.toString();
    }
}
