package com.company;

import java.io.InvalidObjectException;
import java.util.*;
import java.util.stream.Collectors;

public class GestaoEncomendas {

    HashMap<Integer, Encomenda> encomendas;

    public GestaoEncomendas() {
        encomendas = new HashMap<Integer, Encomenda>();
    }

    public GestaoEncomendas(Collection<Encomenda> encomendas) {
        this.encomendas = new HashMap<Integer, Encomenda>();

        for(Encomenda e : encomendas) {
            this.encomendas.put(e.getNumero(), (Encomenda) e.clone());
        }
    }

    public GestaoEncomendas(GestaoEncomendas gestao) {
        this(gestao.encomendas.values());
    }

    public Set<Integer> todosCodigosEnc() {
        return encomendas.keySet();
    }

    public void addEncomenda(Encomenda encomenda) {
        encomendas.put(encomenda.getNumero(), (Encomenda)encomenda.clone());
    }

    public int encomendaComMaisProdutos() {
        Encomenda result = null;
        int maxSize = 0;
        for(Encomenda e : encomendas.values()) {
            if(e.getLinhas().size() >= maxSize) {
                result = e;
                maxSize = e.getLinhas().size();
            }
        }

        if(result == null)
            throw new IllegalStateException();

        return result.getNumero();
    }

    public Set<Integer> encomendasComProduto(String produto) {
        return encomendas.values().stream().filter((Encomenda e) -> e.getLinhas().stream()
                .anyMatch((LinhaEncomenda le) -> le.getProduct().equals(produto))).map(Encomenda::getNumero)
                .collect(Collectors.toSet());
    }

    public Encomenda getEncomenda(Integer codEnc) {
        Encomenda enc = encomendas.get(codEnc);

        if(enc == null)
            throw new IllegalArgumentException();

        return (Encomenda)enc.clone();
    }

    public Map<String, List<Integer>> encomendasDeProduto() {
        HashMap<String, List<Integer>> result = new HashMap<>();

        for(Encomenda e : encomendas.values()) {
            for(LinhaEncomenda le : e.getLinhas()) {
                if(!result.containsKey(le.getProduct())) {
                    result.put(le.getProduct(), new ArrayList<Integer>());
                }
                //if(!result.get(le.getProduct()).contains(e.getNumero()))
                    result.get(le.getProduct()).add(e.getNumero());
            }
        }

        return result;
    }

    public void removeEncomenda(Integer codEnc) {
        encomendas.remove(codEnc);
    }

    public Object clone() {
        return new GestaoEncomendas(this);
    }

    public String toString() {
        StringBuilder builder = new StringBuilder();

        for(Encomenda e : encomendas.values()) {
            builder.append(e.toString());
        }

        return builder.toString();
    }

    public boolean equals(Object o) {
        if(o == this)
            return true;

        if(o.getClass() != this.getClass())
            return false;

        GestaoEncomendas gestao = (GestaoEncomendas)o;

        return gestao.encomendas.equals(encomendas);
    }
}
