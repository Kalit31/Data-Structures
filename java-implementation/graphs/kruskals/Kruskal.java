package graphs.kruskals;

import graphs.disjointSet.DisjointSet;
import graphs.graphUtils.UndirectedEdge;
import node.WeightedNode;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Kruskal {
    ArrayList<WeightedNode> nodeList = new ArrayList<WeightedNode>();
    ArrayList<UndirectedEdge> edgeList = new ArrayList<>();

    public Kruskal(ArrayList<WeightedNode> nodeList) {
        this.nodeList = nodeList;
    }

    public void kruskal(){
        DisjointSet.makeSet(nodeList);

        Comparator<UndirectedEdge> comparator = new Comparator<UndirectedEdge>() {
            @Override
            public int compare(UndirectedEdge undirectedEdge, UndirectedEdge t1) {
                return undirectedEdge.getWeight()-t1.getWeight();
            }
        };
        Collections.sort(edgeList,comparator);

        int cost = 0;
        for(UndirectedEdge edge:edgeList){
            WeightedNode first = edge.getFirst();
            WeightedNode second = edge.getSecond();
            if(!DisjointSet.findSet(first).equals(DisjointSet.findSet(second))) {
                DisjointSet.union(first, second);
                cost = cost + edge.getWeight();
                System.out.println("Taken " + edge);
            }
        }
        System.out.println("\nTotal cost of MST: " + cost);
    }

    public void addWeightedUndirectedEdge(int firstIndex,int secondIndex, int weight){
        UndirectedEdge edge = new UndirectedEdge(nodeList.get(firstIndex-1),nodeList.get(secondIndex-1),weight);
        WeightedNode first = edge.getFirst();
        WeightedNode second = edge.getSecond();
        first.getNeighbors().add(second);
        second.getNeighbors().add(first);
        first.getWeightMap().put(second,weight);
        second.getWeightMap().put(first,weight);
        edgeList.add(edge);
    }
}
