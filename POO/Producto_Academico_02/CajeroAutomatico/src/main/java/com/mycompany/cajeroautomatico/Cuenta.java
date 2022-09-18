/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class Cuenta {
    private int numeroCuenta;
    private int nip;
    private double saldoDisponible;
    private double saldoTotal;
    
    
    public Cuenta( int elNumeroDeCuenta, int elNIP,
            double elSaldoDisponible, double elSaldoTotal ) {
        numeroCuenta = elNumeroDeCuenta;
        nip = elNIP;
        saldoDisponible = elSaldoDisponible;
        saldoTotal = elSaldoTotal;
    }
    
    
    public boolean validarNIP( int nipUsuario ) {
        if ( nipUsuario == nip )
            return true;
        else
            return false;
    }
    
    
    public double obtenerSaldoDisponible() {
        return saldoDisponible;
    }
    
    
    public double obtenerSaldoTotal() {
        return saldoTotal;
    }
    
    
    public void abonar( double monto ) {
        saldoDisponible += monto;
    }
    
    
    public void cargar( double monto ) {
        saldoDisponible -= monto;
        saldoTotal -= monto;
    }
    
    
    public int obtenerNumeroCuenta() {
        return numeroCuenta;
    }
}
