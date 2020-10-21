package array;

public class TwoDimensionalArrayMain {

    public static void main(String[] args) {
        TwoDimensionalArray tda = new TwoDimensionalArray(4,4);
        tda.traverseArray();

        tda.insertValue(0,2,1000000001);
        tda.traverseArray();

        tda.insertValue(0,2,1000000001);
        tda.traverseArray();

        tda.accessCell(0,2);
        tda.accessCell(6,2);
        tda.accessCell(2,2);

        tda.searchValue(10);
        tda.searchValue(-2147483648);
        tda.searchValue(1000000001);

        tda.delete(0,2);
        tda.traverseArray();

        tda.deleteArray();
        tda.traverseArray();
    }
}
