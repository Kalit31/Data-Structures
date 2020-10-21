package graphs.bfs;

import node.GraphNode;

import java.util.ArrayList;
import java.util.LinkedList;

public class BFSLinkedList {
    ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();

    public BFSLinkedList(ArrayList<GraphNode> nodeList) {
        this.nodeList = nodeList;
    }
    public void bfs() {
        //if a node is unvisited then run bfs on it
        for(GraphNode node: nodeList) {
            if(!node.isVisited())
                bfsVisit(node);
        }
    }

    public void bfsVisit(GraphNode node) {
        LinkedList<GraphNode> queue = new LinkedList<>();
        queue.add(node); //add source node to queue
        while(!queue.isEmpty()) {
            GraphNode presentNode = queue.remove(0);
            presentNode.setVisited(true);
            System.out.print(presentNode.getName()+" ");
            for(GraphNode neighbor: presentNode.getNeighbors()) {
                if(!neighbor.isVisited()) {
                    queue.add(neighbor);
                    neighbor.setVisited(true);
                }
            }
        }
    }

    public void addUndirectedEdge(int i, int j) {
        GraphNode first = nodeList.get(i-1);
        GraphNode second = nodeList.get(j-1);
        first.getNeighbors().add(second);
        second.getNeighbors().add(first);
    }
}
