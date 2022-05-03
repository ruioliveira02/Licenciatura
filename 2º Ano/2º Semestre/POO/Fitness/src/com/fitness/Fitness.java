package com.fitness;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Fitness {
    private Map<String, Integer> utilizadores;

    public boolean existeUtilizador(String email) {
        return this.utilizadores.containsKey(email);
    }

    public Map<String, List<Integer>> podiumPorActiv() {
        Map<String, List<Integer>> result = new HashMap<>();



        return result;
    }
}
