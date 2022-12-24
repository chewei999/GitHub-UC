/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Clases;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.awt.*;

/**
 *
 * @author JOSE
 */
public class Proceso {
    
    public List<Producto> LisProducto(Integer idProd) { //crear la funcino LisProducto, con argumento para consultar
        
        List<Producto> lista = new ArrayList();
        String consultaSQL = "select * from Producto where IdP like '" + idProd + "%'";
        Conexion connect = new Conexion();
        
        try {
            // Preparar la sentencia SQL
            PreparedStatement st = connect.ObtenerConexion().prepareStatement(consultaSQL);
            
            // Cuando ejecutemos una consulta st.executeQuery(), esta será llevada a memoria
            // a traves de ResultSet y se almacena en rs
            ResultSet rs = st.executeQuery();
            
            // recorrer todo lo que esta en memoria, leer fila por fila
            while(rs.next()) {
                Producto p = new Producto();
                
                // Captura el valor que tiene la memoria en la posicion 1 de la sentencia sql.
                // Para luego almacenar estos valores en p.setCodProd
                p.setCodProd(rs.getInt(1));
                p.setDescrip(rs.getString(2));
                p.setSaldo(rs.getInt(3));
                lista.add(p);
            }
        }
        catch(SQLException e) {
            e.printStackTrace();
        }
        
        return lista;
    }
}
