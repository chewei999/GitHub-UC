/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class DispensadorEfectivo {
    
    private final static int CUENTA_INICIAL = 500;
    private int cuenta;
    
    
    public DispensadorEfectivo() {
        cuenta = CUENTA_INICIAL;
    }
    
    
    public void dispensadorEfectivo( int monto ) {
        int billetesRequeridos = monto / 20;
        cuenta -= billetesRequeridos;
    }
    
    
    public boolean haySuficienteEfectivoDisponible( int monto ) {
        int billetesRequeridos = monto / 20;
        
        if ( cuenta >= billetesRequeridos )
            return true;
        else
            return false;
    }
}
