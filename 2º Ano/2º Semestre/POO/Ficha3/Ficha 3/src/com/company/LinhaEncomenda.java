package com.company;

public class LinhaEncomenda {
    private String product;
    private String description;

    private int price;
    private int orderedAmount;

    private int tax;

    private int discount;

    public LinhaEncomenda() {
        product = "";
        description = "";
        price = 0;
        orderedAmount = 0;
        tax = 0;
        discount = 0;
    }

    public int getDiscount() {
        return discount;
    }

    public int getPrice() {
        return price;
    }

    public int getOrderedAmount() {
        return orderedAmount;
    }

    public int getTax() {
        return tax;
    }

    public String getProduct() {
        return product;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setDiscount(int discount) {
        this.discount = discount;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setOrderedAmount(int orderedAmount) {
        this.orderedAmount = orderedAmount;
    }

    public void setProduct(String product) {
        this.product = product;
    }

    public void setTax(int tax) {
        this.tax = tax;
    }

    public double calculaValorLinhaEnc() {
        return Math.round((double)price * (1.0 + (double)tax / 100.0) * (1.0 - (double)discount / 100) * 100.0) / 100.0;
    }

    public double calculaValorDesconto() {
        return (discount / 100.0) * (double)price * (1.0 + (double)tax / 100.0);
    }

    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();

        stringBuilder.append("Produto: ");
        stringBuilder.append(product);
        stringBuilder.append("\n");
        stringBuilder.append("Descrição: ");
        stringBuilder.append(description);
        stringBuilder.append("\n");
        stringBuilder.append("Valor em linha: ");
        stringBuilder.append(calculaValorLinhaEnc());
        stringBuilder.append("\n");
        stringBuilder.append("Valor desconto: ");
        stringBuilder.append(calculaValorDesconto());

        return stringBuilder.toString();
    }
}
