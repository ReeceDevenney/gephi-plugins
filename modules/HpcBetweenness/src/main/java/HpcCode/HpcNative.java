/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package HpcCode;

import java.io.File;

/**
 *
 * @author reecedevenney
 */
public class HpcNative {
    
    static {
        File file = new File("src/main/java/HpcCode/libnative.so");
        String absPath = file.getAbsolutePath();
        System.load(absPath);
    }
    
    public static void main(String[] args) {
        int[] xadj = {0,1,3,4};
        int[] adj = {1,0,2,1};
        double[] test = new HpcNative().base_bc(xadj.length - 1,xadj, adj, xadj.length - 1);
        for(int i = 0; i < 3; i++){
        System.out.println(test[i]);
        }
    }
    
 

    
    public native double[] base_bc(int nVtx, int[] xadj, int[] adj, int maxvertex);

    
}
