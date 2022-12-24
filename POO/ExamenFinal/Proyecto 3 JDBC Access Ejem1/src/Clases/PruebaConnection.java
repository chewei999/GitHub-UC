/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package Clases;

import java.sql.*;

/**
 *
 * @author JOSE
 */
public class PruebaConnection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        //Crear un objeto de la clase conexion
        cConnection connect = new cConnection();
        
        //Obtener la conexion
        Connection con = connect.mkConnection();
        
        if(con == null) {
            //Error al establecer la conexion
        }
    }
    
}
