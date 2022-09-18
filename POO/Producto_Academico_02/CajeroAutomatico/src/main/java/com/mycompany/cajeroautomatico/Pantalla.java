/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class Pantalla {
    
    public void mostrarMensaje( String mensaje ) {
        System.out.print( mensaje );
    }
    
    
    public void mostrarLineaMensaje( String mensaje ) {
        System.out.println( mensaje );
    }
    
    
    public void mostrarMontoDolares( double monto ) {
        System.out.printf( "$%,.2f", monto );
    }
}
