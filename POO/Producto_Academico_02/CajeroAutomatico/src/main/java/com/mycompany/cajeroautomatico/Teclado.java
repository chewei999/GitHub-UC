/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.cajeroautomatico;

import java.util.Scanner;

/**
 *
 * @author JOSE
 */
public class Teclado {
    private Scanner entrada;
    
    
    public Teclado() {
        entrada = new Scanner( System.in );
    }
    
    
    public int obtenerEntrada() {
        return entrada.nextInt();
    }
}
