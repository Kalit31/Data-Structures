package graphs.dfs;

import node.GraphNode;

import java.util.ArrayList;

public class DFSRecursive {
    ArrayList<GraphNode> nodeList = new ArrayList<>();

    public DFSRecursive(ArrayList<GraphNode> nodeList) {
        this.nodeList = nodeList;
    }

    void dfs(){
        for(GraphNode g:nodeList){
            if(!g.isVisited())
                dfsVisit(g);
        }
    }

    void dfsVisit(GraphNode node){
        node.setVisited(true);
        System.out.print(node.getName()+" ");
        for(GraphNode g:node.getNeighbors()){
            if(!g.isVisited())
                dfsVisit(g);
        }
    }

    public void addUndirectedEdge(int i, int j) {
        GraphNode first = nodeList.get(i-1);
        GraphNode second = nodeList.get(j-1);
        first.getNeighbors().add(second);
        second.getNeighbors().add(first);
    }
}
