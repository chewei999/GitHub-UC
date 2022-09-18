/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class Deposito extends Transaccion {
    private double monto;
    private Teclado teclado;
    private RanuraDeposito ranuraDeposito;
    private final static int CANCELO = 0;
    
    
    public Deposito( int numeroCuentaUsuario, Pantalla pantallaATM, BaseDatosBanco baseDatosBancoATM,
            Teclado tecladoATM, RanuraDeposito ranuraDepositoATM) {
        
        super( numeroCuentaUsuario, pantallaATM, baseDatosBancoATM);
        
        
        teclado = tecladoATM;
        ranuraDeposito = ranuraDepositoATM;
    }
    
    
    @Override
    public void ejecutar() {
        BaseDatosBanco baseDatosBanco = obtenerBaseDatosBanco();
        Pantalla pantalla = obtenerPantalla();
        
        monto = pedirMontoADepositar();
        
        
        if ( monto != CANCELO ) {
            
            pantalla.mostrarMensaje( "\nInserte un sobre que contenga " );
            pantalla.mostrarMontoDolares( monto );
            pantalla.mostrarLineaMensaje( "." );
            
            
            boolean seRecibioSobre = ranuraDeposito.seRecibioSobre();
            
            
            if ( seRecibioSobre ) {
                pantalla.mostrarLineaMensaje("\nSe recibio su sobre de " + 
                        "deposito.\nNOTA: El dinero que se acaba de depositar no " +
                        "estara disponible sino hasta que verifiquemos el monto del " +
                        "efectivo y cualquier cheque incluido.");
                
                
                baseDatosBanco.abonar( obtenerNumeroCuenta(), monto);
            }
            else
            {
                pantalla.mostrarLineaMensaje( "\nNo inserto un sobre de " +
                        "deposito, por lo que el ATM ha cancelado su transaccion,");
            }
        }
        else
        {
            pantalla.mostrarLineaMensaje( "\nCancelando transaccion...");
        }
    }
    
    
    private double pedirMontoADepositar() {
        Pantalla pantalla = obtenerPantalla();
        
        
        pantalla.mostrarMensaje( "\nIntroduzca un monto a depositar en " + "CENTAVOS (o 0 para cancelar); ");
        int entrada = teclado.obtenerEntrada();
        
        
        if ( entrada == CANCELO )
            return CANCELO;
        else {
            return ( double ) entrada / 100;
        }
    }
}
