/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroatm;

/**
 *
 * @author JOSE
 */
public class PruebaEjecucion {
    
    public static void main(String[] args) {
        
        double saldo;
        
        
        ProcesoATM service = new ProcesoATM();
        
        
        saldo = service.obtenerSaldo();
        System.out.println("saldo Inicial: " + saldo);
        
        
        service.realizarRetiro(20);
        System.out.println("retiro: " + 20);
        
        saldo = service.obtenerSaldo();
        System.out.println("saldo luego del retiro: " + saldo);
        
        
        service.realizarDeposito(100);
        System.out.println("Deposito: " + 100);
        saldo = service.obtenerSaldo();
        System.out.println("saldo luego del deposito: " + saldo);
    }
}
