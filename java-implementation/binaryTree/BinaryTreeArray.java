package binaryTree;

public class BinaryTreeArray {
    int[] arr;
    int lastIndexUsed;

    public BinaryTreeArray(int size) {
        arr = new int[size + 1];
        this.lastIndexUsed = 0;
        System.out.println("Blank Tree of size " + size + " has been created !\n");
    }

    boolean isTreeFull() {
        if (arr.length - 1 == lastIndexUsed) {
            return true;
        } else {
            return false;
        }
    }

    void insert(int value) {
        if (!isTreeFull()) {
            arr[lastIndexUsed + 1] = value;
            lastIndexUsed++;
            System.out.println("Successfully inserted " + value + " in the tree!");
        } else {
            System.out.println("Could not insert value in the Tree as it is full !");
        }
    }

    public int search(int value) {
        for (int i = 0; i <= lastIndexUsed; i++) {
            if (arr[i] == value) {
                System.out.print(value +" exists in the Tree! ");
                return i;
            }
        }
        System.out.println(value + " does not exists in Tree !");
        return -1;
    }

    void inOrder(int index){
        if(index>lastIndexUsed){
            return;
        }
        inOrder(index*2);
        System.out.print(arr[index]+" ");
        inOrder(index*2+1);
    }

    public void preOrder(int index) {
        if (index > lastIndexUsed) {
            return;
        }
        System.out.print(arr[index] + " ");
        preOrder(index * 2);
        preOrder(index * 2 + 1);
    }

    void postOrder(int index) {
        if (index > lastIndexUsed) {
            return;
        }
        postOrder(index * 2);
        postOrder(index * 2 + 1);
        System.out.print(arr[index] + " ");
    }

    public void levelOrder() {
        for(int i=1;i<=lastIndexUsed;i++ ) {
            System.out.print(arr[i]+" ");
        }
    }

    public void delete(int value) {
        int location = search(value);
        //If Value does not exists in Array
        if (location == -1) {
            return;
        }else {
            //insert last element of the Tree into current location
            arr[location] = arr[lastIndexUsed];
            lastIndexUsed--;
            System.out.println("Successfully deleted " + value + " from the Tree !");
        }
    }

    public void deleteTree(){
        try {
            arr = null;
            System.out.println("Tree has been deleted successfully !");
        }catch(Exception e){
            System.out.println("There was an error deleting the tree.");
        }
    }
}
