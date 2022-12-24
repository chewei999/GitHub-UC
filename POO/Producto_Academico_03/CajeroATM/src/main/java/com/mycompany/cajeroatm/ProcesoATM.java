/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroatm;

/**
 *
 * @author JOSE
 */
public class ProcesoATM {
    
    private double saldo = 5200;
    
    public double obtenerSaldo() {
        return saldo;
    }
    
    public boolean realizarDeposito(int valor) {
        saldo += valor;
        return true;
    }
    
    public boolean realizarRetiro(int valor) {
        saldo -= valor;
        return true;
    }
    
    private double dosDec(double valor) {
        valor = valor * 100;
        valor = Math.round(valor);
        valor = valor / 100;
        return valor;
    }
}
