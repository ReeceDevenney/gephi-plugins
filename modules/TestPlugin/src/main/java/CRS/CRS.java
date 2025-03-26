/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package CRS;

import org.gephi.graph.api.Graph;
import org.gephi.graph.api.GraphModel;
import java.util.ArrayList;
import org.gephi.graph.api.Node;
import org.gephi.statistics.spi.Statistics;
import org.gephi.graph.api.Table;
import org.gephi.graph.api.Column;


/**
 *
 * @author reecedevenney
 */
public class CRS implements Statistics {

    //Result
    private ArrayList<Integer> idArray;
    private int[] indexArray;
    private int[] edgeArray;

    @Override
    public void execute(GraphModel graphModel) {
        
        Graph graph = graphModel.getGraphVisible();
        int edgeCount = graph.getEdgeCount();
        int nodeCount = graph.getNodeCount();
        Node[] nodes = graph.getNodes().toArray();
        indexArray = new int[nodeCount + 1];
        if(graph.isDirected()){
            edgeArray = new int[edgeCount];
        } else if(graph.isUndirected()){
            edgeArray = new int[edgeCount * 2];
        }
        idArray = new ArrayList<>();
        indexArray[0] = 0;
        int nodeIndex = 1;
        int edgeIndex = 0;
        for(Node n: nodes){
            for(Node m: graph.getNeighbors(n)){
               edgeArray[edgeIndex] = m.getStoreId(); 
               edgeIndex++;
            }
            indexArray[nodeIndex] = edgeIndex;
            idArray.add(n.getStoreId());
            nodeIndex++;
        }
        System.out.println(idArray);
        for(int i = 0; i < indexArray.length; i++){
        System.out.println(indexArray[i] + "test");
        }
        //int[] xadj = {0,1,3,4};
        //int[] adj = {1,0,2,1};
        double[] test = new Arguments().base_bc(indexArray.length - 1, indexArray, edgeArray, indexArray.length - 1);
        
        Table nodeTable = graphModel.getNodeTable();
        Column col = nodeTable.getColumn("CRS");
        if (col == null) {
            col = nodeTable.addColumn("CRS", Double.class);
        }
        
        graph.readLock();
        for(int i = 0; i < nodes.length; i++){
            nodes[i].setAttribute(col, test[i]);
        }
        graph.readUnlock();
        
        System.out.println(test[1]);
    }
    
    

    @Override
    public String getReport() {
        String report = "<HTML> <BODY> <h1>CRS Report </h1> "
                + "<hr>"
                + "<br> <h2> No global data to report, check data labs. </h2>"
                + "<br />"
                + "</BODY></HTML>";
        return report;
    }

    public int[] getIndexArray() {
        return indexArray;
    }
    
    public int[] getEdgeArray() {
        return edgeArray;
    }
}

