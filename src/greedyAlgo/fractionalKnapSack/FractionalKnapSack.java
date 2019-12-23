package greedyAlgo.fractionalKnapSack;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class FractionalKnapSack {
    public static void knapSack(ArrayList<Item> items,int capacity){
        Comparator<Item> sortRatio = new Comparator<Item>() {
            @Override
            public int compare(Item item, Item t1) {
                if(t1.getRatio()>item.getRatio())
                    return 1;
                else
                    return -1;
            }
        };

        Collections.sort(items,sortRatio);

        int usedCapacity=0;
        double totalValue=0;
        for(Item item:items){
            if(usedCapacity+item.getWeight()<=capacity){
                usedCapacity+=item.getWeight();
                System.out.println("Taken: "+item);
                totalValue+=item.getValue();
            }else{
                int left = capacity - usedCapacity;
                double value = item.getRatio()*left;
                System.out.println("Taken: "+"item index = " + item.getIndex() + ",obtained value = " + value + ",used weight = " + left + ", ratio = " + item.getRatio()
                        + "]");
                usedCapacity+=left;
                totalValue+=value;
            }
            if(usedCapacity==capacity)break;
        }
        System.out.println("\nTotal value obtained: "+ totalValue);
    }
}
