/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

/**
 *
 * @author JOSE
 */
public class Retiro extends Transaccion {
    private int monto;
    private Teclado teclado;
    private DispensadorEfectivo dispensadorEfectivo;
    
    
    private final static int CANCELO = 6;
    
    
    public Retiro( int numeroCuentaUsuario, Pantalla pantallaATM, BaseDatosBanco baseDatosBancoATM,
            Teclado tecladoATM, DispensadorEfectivo dispensadorEfectivoATM ) {
        
        
        super( numeroCuentaUsuario, pantallaATM, baseDatosBancoATM );
        
        
        teclado = tecladoATM;
        dispensadorEfectivo = dispensadorEfectivoATM;
    }
    
    
    @Override
    public void ejecutar() {
        boolean efectivoDispensado = false;
        double saldoDisponible;
        
        
        BaseDatosBanco baseDatosBanco = obtenerBaseDatosBanco();
        Pantalla pantalla = obtenerPantalla();
        
        
        do {
            
            monto = mostrarMenuDeMontos();
            
            
            if ( monto != CANCELO ) {
                
                saldoDisponible = baseDatosBanco.obtenerSaldoDisponible( obtenerNumeroCuenta() );
                
                
                if ( monto <= saldoDisponible ) {
                    
                    if ( dispensadorEfectivo.haySuficienteEfectivoDisponible( monto ) ) {
                        
                        baseDatosBanco.cargar( obtenerNumeroCuenta(), monto );
                        
                        dispensadorEfectivo.dispensadorEfectivo(monto );
                        efectivoDispensado = true;
                        
                        
                        pantalla.mostrarLineaMensaje( "\nSe dispenso su" + " efectivo. Tomelo ahora." );
                    }
                    else
                        pantalla.mostrarLineaMensaje( "\nNo hay suficiente efectivo disponible en el ATM." + 
                                "\n\nSeleccione un monto menor." );
                }
                else
                {
                    pantalla.mostrarLineaMensaje( "\nNo hay suficiente fondos en su cuenta." +
                            "\n\nSeleccione un monto menor." );
                }
            }
            else
            {
                pantalla.mostrarLineaMensaje( "\nCancelando transaccion...");
                return;
            }
        } while ( !efectivoDispensado );

    }
    
    
    
    private int mostrarMenuDeMontos() {
        int opcionUsuario = 0;
        
        Pantalla pantalla = obtenerPantalla();
        
        
        int montos[] = { 0, 20, 40, 60, 100, 200 };
        
        
        while ( opcionUsuario == 0) {
            
            pantalla.mostrarLineaMensaje( "\nMenu de retiro:" );
            pantalla.mostrarLineaMensaje( "1 - $20" );
            pantalla.mostrarLineaMensaje( "2 - $40" );
            pantalla.mostrarLineaMensaje( "3 - $60" );
            pantalla.mostrarLineaMensaje( "4 - $100" );
            pantalla.mostrarLineaMensaje( "5 - $200" );
            pantalla.mostrarLineaMensaje( "6 - Cancelar transaccion" );
            pantalla.mostrarMensaje( "\nSeleccione un monto a retirar: " );
            
            int entrada = teclado.obtenerEntrada();
            
            
            switch ( entrada ) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    opcionUsuario = montos[ entrada ];
                    break;
                case CANCELO:
                    opcionUsuario = CANCELO;
                    break;
                default:
                    pantalla.mostrarLineaMensaje( "\nSeleccion invalida. Intente de nuevo." );
                    break;
            }
        }
        
        return opcionUsuario;
    }
}
