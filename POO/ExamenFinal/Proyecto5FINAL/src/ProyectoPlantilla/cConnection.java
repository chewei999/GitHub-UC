/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ProyectoPlantilla;

import java.sql.*;

/**
 *
 * @author JOSE
 */
public class cConnection {
    private String url = "jdbc:ucanaccess://E:\\UC\\GitHub-UC\\POO\\ExamenFinal\\Proyecto5FINAL\\BDVentas.accdb";
    private String usr = "";
    private String pswd = "";
    private Connection con = null;
    
    public cConnection() {
        loadDriver();
    }
    
    private void loadDriver() {
        try {
            Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
        }
        catch(ClassNotFoundException e) {
            System.out.println("Error al crear el puente JDBC-Access");
        }
    }
    
    public Connection ObtenerConexion() {
        System.out.println("Estableciendo conexion con " + url);
        try {
            con = DriverManager.getConnection(url, usr, pswd);
        }
        catch(SQLException sqle) {
            System.out.println("No se pudo establecer la conexion");
            return null;
        }
        
        System.out.println("Conexion establecida con: " + url);
        return con;
    }
    
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
