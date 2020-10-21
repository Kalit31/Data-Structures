package graphs.prims;
import node.WeightedNode;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Prims {
    ArrayList<WeightedNode> nodeList = new ArrayList<WeightedNode>();

    public Prims(ArrayList<WeightedNode> nodeList) {
        this.nodeList = nodeList;
    }

    public void prims(WeightedNode node){
        for(int counter=0;counter<nodeList.size();counter++){
            nodeList.get(counter).setDistance(Integer.MAX_VALUE);
        }
        node.setDistance(0);

        PriorityQueue<WeightedNode> queue = new PriorityQueue<>();
        queue.addAll(nodeList);

        while(!queue.isEmpty()){
            WeightedNode presentNode = queue.remove();

            for(WeightedNode n:presentNode.getNeighbors()){
                if(queue.contains(n)){
                    if(n.getDistance()>presentNode.getWeightMap().get(n)){
                        n.setDistance(presentNode.getWeightMap().get(n));
                        queue.remove(n);
                        queue.add(n);
                    }
                }
            }
        }

        int cost = 0;
        for (WeightedNode nodeToCheck : nodeList) {
            System.out.println("Node " + nodeToCheck + ", key: " + nodeToCheck.getDistance() + ", Parent: " + nodeToCheck.getParent());
            cost = cost + nodeToCheck.getDistance();
        }
        System.out.println("Minimum cost: "+cost);
    }

    public void addWeightedUndirectedEdge(int i, int j, int d) {
        WeightedNode first = nodeList.get(i-1);
        WeightedNode second = nodeList.get(j-1);
        first.getNeighbors().add(second);
        second.getNeighbors().add(first);
        first.getWeightMap().put(second,d);
        second.getWeightMap().put(first, d);
    }
}
