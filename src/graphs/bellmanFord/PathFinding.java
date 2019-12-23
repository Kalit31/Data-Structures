package graphs.bellmanFord;

import node.WeightedNode;
import java.util.ArrayList;

public class PathFinding {
    ArrayList<WeightedNode> nodeList = new ArrayList<WeightedNode>();

    public PathFinding(ArrayList<WeightedNode> nodeList) {
        this.nodeList = nodeList;
        for(WeightedNode aNode: nodeList){
            aNode.setDistance(Integer.MAX_VALUE/10);
        }
    }

    public void bellmanFord(WeightedNode sourceNode){
        sourceNode.setDistance(0);
        for(int i=1;i<nodeList.size();i++){
            for(WeightedNode presentNode:nodeList){
                for(WeightedNode neighbor:presentNode.getNeighbors()){
                    if(neighbor.getDistance()>(presentNode.getDistance()+presentNode.getWeightMap().get(neighbor))) {
                        neighbor.setDistance(presentNode.getDistance() + presentNode.getWeightMap().get(neighbor));
                        neighbor.setParent(presentNode);
                    }
                }
            }
        }
        System.out.println("Checking for Negative Cycle ...");
        for(WeightedNode presentNode:nodeList){
            for(WeightedNode neighbor:presentNode.getNeighbors()){
                if(neighbor.getDistance()>presentNode.getDistance()+presentNode.getWeightMap().get(neighbor)){
                    System.out.println("Negative cycle found: \n");
                    System.out.println("Vertex Name: " + neighbor.getName());
                    System.out.println("Old Distance: " + neighbor.getDistance());
                    int newDistance = presentNode.getDistance()+presentNode.getWeightMap().get(neighbor);
                    System.out.println("New distance: " + newDistance);
                    return;
                }
            }
        }
        System.out.println("Negative cycle not found !");
        for (WeightedNode nodeToCheck : nodeList) {
            if (nodeToCheck.getDistance() != Integer.MAX_VALUE/10) {
                System.out.print("Node " + nodeToCheck + ", distance: " + nodeToCheck.getDistance() + ", Path: ");
                pathPrint(nodeToCheck);
            } else {
                System.out.print("No path for node " + nodeToCheck);
            }
            System.out.println();
        }
    }

    private static void pathPrint(WeightedNode node) {
        if(node.getParent()!=null) {
            pathPrint(node.getParent());
            System.out.print("->"+node);
        }
        else
            System.out.print(node);
    }

    public void addWeightedEdge(int i, int j, int d) {
        WeightedNode first = nodeList.get(i-1);
        WeightedNode second = nodeList.get(j-1);
        first.getNeighbors().add(second);
        first.getWeightMap().put(second,d);
    }
}
