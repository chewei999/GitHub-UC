/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class SolicitudSaldo extends Transaccion {
    
    public SolicitudSaldo( int numeroCuentaUsuario, Pantalla pantallaATM, BaseDatosBanco baseDatosBanco ) {
        super( numeroCuentaUsuario, pantallaATM, baseDatosBanco);
    }
    
    
    @Override
    public void ejecutar() {
        
        BaseDatosBanco baseDatosBanco = obtenerBaseDatosBanco();
        Pantalla pantalla = obtenerPantalla();
        
        
        double saldoDisponible = baseDatosBanco.obtenerSaldoDisponible( obtenerNumeroCuenta() );
        
        
        double saldoTotal = baseDatosBanco.obtenerSaldoTotal( obtenerNumeroCuenta() );
        
        
        pantalla.mostrarLineaMensaje("\nInformacion de saldo:");
        pantalla.mostrarMensaje( " - Saldo disponible: ");
        pantalla.mostrarMontoDolares( saldoDisponible);
        pantalla.mostrarMensaje("\n - Saldo total: ");
        pantalla.mostrarMontoDolares( saldoTotal );
        pantalla.mostrarLineaMensaje( "" );
    }
}
