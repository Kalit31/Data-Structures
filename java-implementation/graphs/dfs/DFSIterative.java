package graphs.dfs;

import node.GraphNode;

import java.util.ArrayList;
import java.util.Stack;

public class DFSIterative {
    ArrayList<GraphNode> nodeList = new ArrayList<>();

    public DFSIterative(ArrayList<GraphNode> nodeList) {
        this.nodeList = nodeList;
    }

    public void dfs(){
        for(GraphNode g:nodeList)
            if(!g.isVisited())
                dfsVisit(g);
    }

    void dfsVisit(GraphNode node){
        Stack<GraphNode>  stack = new Stack<>();
        stack.push(node);
        while (!stack.isEmpty()){
            GraphNode presentNode = stack.pop();
            presentNode.setVisited(true);
            System.out.print(presentNode.getName()+" ");
            for(GraphNode g:presentNode.getNeighbors()){
                if(!g.isVisited()){
                    stack.add(g);
                    g.setVisited(true);
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
