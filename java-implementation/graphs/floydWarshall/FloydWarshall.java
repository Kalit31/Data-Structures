package graphs.floydWarshall;

import node.WeightedNode;
import java.util.ArrayList;

public class FloydWarshall {
    ArrayList<WeightedNode> nodeList = new ArrayList<WeightedNode>();

    public FloydWarshall(ArrayList<WeightedNode> nodeList) {
        this.nodeList = nodeList;
    }

    public void floydWarshall(){
        int size = nodeList.size();
        int[][] V = new int[size][size];

        for(int i=0;i<size;i++){
            WeightedNode first = nodeList.get(i);
            for(int j=0;j<size;j++){
                WeightedNode second = nodeList.get(j);
                if(i==j)
                    V[i][j]=0;
                else if(first.getWeightMap().containsKey(second)) {
                    V[i][j] = first.getWeightMap().get(second);
                }
                else
                    V[i][j]=Integer.MAX_VALUE/10;
            }
        }

        for(int k=0;k<size;k++){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(V[i][j]>V[i][k]+V[k][j])
                        V[i][j]=V[i][k]+V[k][j];
                }
            }
        }

        for(int i=0;i<size;i++){
                System.out.print("Printing distance list for node "+nodeList.get(i)+": ");
                for(int j=0;j<size;j++)
                    System.out.print(V[i][j]+" ");
            System.out.println();
        }
    }

    public void addWeightedEdge(int i, int j, int d) {
        WeightedNode first = nodeList.get(i - 1);
        WeightedNode second = nodeList.get(j - 1);
        first.getNeighbors().add(second);
        first.getWeightMap().put(second, d);
    }
}
