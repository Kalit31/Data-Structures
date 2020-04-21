import java.util.List;

// This is the BinaryMatrix's API interface. // You should not implement it,
//or speculate about its implementation 
interface BinaryMatrix {
    public int get(int x, int y);

    public List<Integer> dimensions();
};

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dimension = binaryMatrix.dimensions();
        int row = dimension.get(0);
        int col = dimension.get(1);
        int i = 0;
        int lastColFound = -1;
        col--;
        while (i < row && col >= 0) {
            int val = binaryMatrix.get(i, col);
            if (val == 0) {
                i += 1;
            } else {
                lastColFound = col;
                col -= 1;
            }
        }
        return lastColFound;
    }
}