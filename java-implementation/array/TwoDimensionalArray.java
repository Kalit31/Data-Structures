package array;

public class TwoDimensionalArray {

    int arr[][] = null;

    public TwoDimensionalArray(int numberOfRows, int numberOfColumns) {
        this.arr = new int[numberOfRows][numberOfColumns];
        for(int i = 0;i<numberOfRows;i++)
            for(int j = 0;j<numberOfColumns;j++)
                arr[i][j] = Integer.MIN_VALUE;
    }

    public void traverseArray(){
        try{
            System.out.println("Printing array....");
            for(int i = 0;i<arr.length;i++) {
                for (int j = 0; j < arr[i].length; j++)
                    System.out.print(arr[i][j] + " ");
                System.out.println();
            }
        }catch (Exception e){
            System.out.println("Array does not exist!");
        }
    }

    public void insertValue(int i,int j, int value){
        try{
            if(arr[i][j] == Integer.MIN_VALUE){
                arr[i][j]= value;
                System.out.println("Succesfully inserted "+value);
            }else
                System.out.println("Already occupied");
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void accessCell(int i,int j){
        try{
            System.out.println("Value: "+arr[i][j]);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void searchValue(int value){
        for(int i=0;i<arr.length;i++){
            for(int j =0;j<arr[i].length;j++){
                if(arr[i][j]==value){
                    System.out.println("Value found at row: "+i+" column: "+j);
                    return;
                }
            }
        }
        System.out.println("Value not found!!");
    }

    public void delete(int i,int j){
        try{
            System.out.println("Successfully deleted: "+arr[i][j]);
            arr[i][j] = Integer.MIN_VALUE;
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public void deleteArray(){
        arr = null;
        System.out.println("Array has been deleted");
    }
}
