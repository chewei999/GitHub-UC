package proyecto.pkg2.jdbc.oracle.ejem1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Connection cn = null;
        //Obteniendo la conexion
        try {
            DriverManager.registerDriver(new oracle.jdbc.OracleDriver());
            cn=DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:XE", "System", "oracle");
            System.out.println("Obteniendo la conexion");
        }
        catch (Exception e) {
            System.out.println("Error de conexion \n " + e.toString());
        }
        
        //cerrando la conexion
        try {
            cn.close();
            System.out.println("Cerrando la conexion");
        }
        catch (SQLException e) {
            System.out.println("Error de cierre " + e.toString());
        }
    }
    
}
