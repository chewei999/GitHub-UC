/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Clases;

import java.sql.*;

/**
 *
 * @author JOSE
 */
public class cConnection {
    private String url = "jdbc:ucanaccess://E:\\UC\\GitHub-UC\\POO\\ExamenFinal\\Proyecto 3 JDBC Access Ejem1\\BDEjemplo.accdb";
    private String usr = "";
    private String pswd = "";
    private Connection con = null;
    
    /* Constructor, carga puente JDBC-ODBC */
    public cConnection() {
        loadDriver();
    }
    
    // Carga el driver de la conexion a la base de datos
    private void loadDriver() {
        try {
            Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
        }
        catch(ClassNotFoundException e) {
            System.out.println("Error al crear el puente JDBC-Access");
        }
    }
    
    public Connection mkConnection() {
        System.out.println("Estableciendo conexion con " + url);
        try {
            con = DriverManager.getConnection(url, usr, pswd);
        }
        catch(SQLException e) {
            System.out.println("No se pudo establecer la conexion");
            return null;
        }
        
        System.out.println("Conexion establecida con " + url);
        
        return con;
    }
    
    //cerrar la conexion
    public boolean closeConnection() {
        try {
            con.close();
        }
        catch(SQLException sqle) {
            System.out.println("No se cerró la conexion");
            return false;
        }
        
        System.out.println("Conexion cerrada con exito");
        return true;
    }
}
