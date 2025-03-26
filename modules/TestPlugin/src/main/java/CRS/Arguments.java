/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CRS;

import java.io.File;

/**
 *
 * @author reecedevenney
 */
public class Arguments {
    
     static {
        //File file = new File("./src/main/java/CRS/libnative.so");
        System.load("/home/reecedevenney/UNCC/Research/gephi-plugins/modules/TestPlugin/src/main/java/CRS/libnative.so");
    }
    
    public static void main(String[] args) {
        int[] xadj = {0,1,3,4};
        int[] adj = {1,0,2,1};
        double[] test = new Arguments().base_bc(xadj.length - 1,xadj, adj, xadj.length - 1);
        for(int i = 0; i < 3; i++){
        System.out.println(test[i]);
        }
    }
    
 

    
    public native double[] base_bc(int nVtx, int[] xadj, int[] adj, int maxvertex);
    
}
