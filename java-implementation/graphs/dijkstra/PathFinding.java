package graphs.dijkstra;

import node.WeightedNode;

import java.util.ArrayList;
import java.util.PriorityQueue;

public class PathFinding {

    ArrayList<WeightedNode> nodeList = new ArrayList<WeightedNode>();

    public PathFinding(ArrayList<WeightedNode> nodeList) {
        this.nodeList = nodeList;
    }

    public void dijkstra(WeightedNode node){
        PriorityQueue<WeightedNode> queue = new PriorityQueue<>();
        node.setDistance(0); //This will make sure that we start from this vertex in priority queue as distance is min
        queue.addAll(nodeList);
        while(!queue.isEmpty()){
            WeightedNode presentNode = queue.remove();
            for(WeightedNode neighbor:presentNode.getNeighbors()){
                if(queue.contains(neighbor)){
                    if(neighbor.getDistance() > (presentNode.getDistance()+presentNode.getWeightMap().get(neighbor))){
                        neighbor.setDistance(presentNode.getDistance()+presentNode.getWeightMap().get(neighbor));
                        neighbor.setParent(presentNode);
                        //Refresh the Priority Queue
                        queue.remove(neighbor);
                        queue.add(neighbor);
                    }
                }
            }
        }
        for(WeightedNode nodeToCheck:nodeList){
            System.out.print("Node "+nodeToCheck+", distance: "+nodeToCheck.getDistance()+", Path: ");
            pathPrint(nodeToCheck);
            System.out.println();
        }
    }

    public static void pathPrint(WeightedNode node){
        if(node.getParent()!=null) {
            pathPrint(node.getParent());
            System.out.print("->"+node);
        }else
            System.out.print(node);

    }
    public void addWeightedEdge(int i, int j, int d) {
        WeightedNode first = nodeList.get(i-1);
        WeightedNode second = nodeList.get(j-1);
        first.getNeighbors().add(second);
        first.getWeightMap().put(second,d);
    }
}
