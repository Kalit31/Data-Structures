package graphs.disjointSet;
import node.WeightedNode;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<WeightedNode> nodeList = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            nodeList.add(new WeightedNode("" + (char) (65 + i)));
        }
        DisjointSet.driver(nodeList);
    }
}
