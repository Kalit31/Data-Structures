package hashing;

import java.util.ArrayList;

public class LinearProbing {
    String[] hashTable;
    int noOfCellsUsedInHashTable;

    public LinearProbing(){
        hashTable = new String[13];
        noOfCellsUsedInHashTable = 0;
    }

    public int simpleASCIIHashFunction(String x, int M){
        char ch[];
        ch = x.toCharArray();
        int i, sum;
        for (sum=0, i=0; i<x.length(); i++) {
            sum = sum + ch[i];
        }
       return sum % M;
    }

    public double getLoadFactor() {
        double loadFactor = noOfCellsUsedInHashTable * 1.0 / hashTable.length;
        return loadFactor;
    }

    public void insertKeyInHashTable(String value){
        double loadFactor = getLoadFactor();
        if(loadFactor>=0.75){
            System.out.println("Load factor of this HashTable has exceeded 0.75, hence we need to Rehash !\n");
            rehashKeys(value);
        }else{
            System.out.println("Inserting \"" + value + "\" in HashTable...");
            int index = simpleASCIIHashFunction(value,hashTable.length);
            for(int i=index;i<index+hashTable.length;i++){
                int newIndex = i % hashTable.length;
                if(hashTable[index]==null){
                    hashTable[index]= value;
                    System.out.println("Index: " + newIndex + " is blank. Inserting there...");
                    System.out.println("Successfully inserted " + "\"" + value + "\"" + " in location: " + newIndex);
                    System.out.println("-------------------------------------------\n");
                    break;
                }else{
                    System.out.println("Index: " + newIndex + " is already occupied. Trying next empty cell...");
                }
            }
        }
        noOfCellsUsedInHashTable++;
    }

    public void rehashKeys(String stringToBeInserted){
        noOfCellsUsedInHashTable = 0;
        ArrayList<String> data = new ArrayList<>();
        for(String s: hashTable){
            if(s!=null)
                data.add(s);
        }
        data.add(stringToBeInserted);
        hashTable = new String[hashTable.length*2];
        for(String s:data)
            insertKeyInHashTable(s);
    }

    public boolean searchKeyInHashTable(String stringToBeSearched){
        int index = simpleASCIIHashFunction(stringToBeSearched,hashTable.length);
        for(int i=index;i<index+hashTable.length;i++){
            int newIndex =  i%hashTable.length;
            if(hashTable[newIndex]!=null && hashTable[index].equals(stringToBeSearched)){
                System.out.println("\n" + "\"" + stringToBeSearched + "\"" + " found in HashTable at location: "+newIndex);
                return true;
            }
        }
        System.out.println("\n" + "\"" + stringToBeSearched + "\"" + " not found in HashTable.");
        return false;
    }

    public void deleteKey(String stringToBeDeleted){
        int index = simpleASCIIHashFunction(stringToBeDeleted,hashTable.length);
        for(int i=index;i<index+hashTable.length;i++){
            int newIndex = i % hashTable.length;
            if (hashTable[newIndex]!=null && hashTable[newIndex].equals(stringToBeDeleted)) {
                hashTable[newIndex] = null;
                System.out.println("\n" + "\"" + stringToBeDeleted + "\"" + " has been found in HashTable." );
                System.out.println("\"" + stringToBeDeleted + "\"" + " has been deleted from HashTable !" );
                return;
            }
        }
    }

    public void displayHashTable() {
        if(hashTable == null) {
            System.out.println("\nHashTable does not exits !");
            return;
        }else {
            System.out.println("\n---------- HashTable ---------");
            for (int i = 0; i < hashTable.length; i++) {
                System.out.println("Index:" + i + ".   Key:" + hashTable[i]);
            }
        }
        System.out.println("\n");
    }

    public void deleteHashTable() {
        System.out.println("Successfully deleted HashTable !");
        hashTable = null;
    }
}
