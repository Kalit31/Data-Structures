package graphs.topoSort;

import node.GraphNode;
import java.util.ArrayList;
import java.util.Stack;

public class TopologicalSort {
    ArrayList<GraphNode> nodeList = new ArrayList<GraphNode>();

    public TopologicalSort(ArrayList<GraphNode> nodeList) {
        this.nodeList = nodeList;
    }

    void topologicalSort(){
        Stack<GraphNode> stack = new Stack<>();
        for(GraphNode g:nodeList){
            if(!g.isVisited())
                topologicalVisit(g,stack);
        }
        while(!stack.isEmpty()){
            System.out.print(stack.pop().getName()+" ");
        }
    }

    public void topologicalVisit(GraphNode node,Stack<GraphNode> stack){
        for(GraphNode g:node.getNeighbors()){
            if(!g.isVisited())
                topologicalVisit(g,stack);
        }
        node.setVisited(true);
        stack.push(node);
    }

    public void addDirectedEdge(int i, int j) {
        GraphNode first = nodeList.get(i - 1);
        GraphNode second = nodeList.get(j - 1);
        first.getNeighbors().add(second);
    }
}
