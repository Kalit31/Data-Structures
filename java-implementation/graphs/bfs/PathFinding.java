package graphs.bfs;

import node.GraphNode;
import java.util.ArrayList;
import java.util.LinkedList;

public class PathFinding {
    ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();

    public PathFinding(ArrayList<GraphNode> nodeList) {
        this.nodeList = nodeList;
    }

    public static void pathPrint(GraphNode node) {
        if(node.getParent()!=null)
            pathPrint(node.getParent());
        System.out.print(node+" ");
    }

    public void SingleSourceShortestPath(GraphNode node){
        LinkedList<GraphNode> queue = new LinkedList<>();
        queue.add(node);
        while(!queue.isEmpty()){
            GraphNode presentNode = queue.remove(0);
            presentNode.setVisited(true);
            System.out.print("Printing path for node "+presentNode.getName()+": ");
            pathPrint(presentNode);
            System.out.println();
            for(GraphNode g:presentNode.getNeighbors()){
                if(!g.isVisited()){
                    queue.add(g);
                    g.setVisited(true);
                    g.setParent(presentNode);
                }
            }
        }
    }

    public void addUndirectedEdge(int i, int j) {
        GraphNode first = nodeList.get(i);
        GraphNode second = nodeList.get(j);
        first.getNeighbors().add(second);
        second.getNeighbors().add(first);
    }
}
