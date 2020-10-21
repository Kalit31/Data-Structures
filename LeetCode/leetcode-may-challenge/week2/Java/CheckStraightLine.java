package week2;

public class CheckStraightLine {
    public boolean checkStraightLine(int[][] coordinates) {
        if (coordinates.length == 2)
            return true;
        double slope = (1.0 * (coordinates[1][1] - coordinates[0][1])) / ((coordinates[1][0] - coordinates[0][0]));

        for (int i = 1; i < coordinates.length - 1; i++) {
            double newSlope = (1.0 * (coordinates[i + 1][1] - coordinates[i][1]))
                    / ((coordinates[i + 1][0] - coordinates[i][0]));
            if (newSlope != slope) {
                return false;
            }
        }
        return true;
    }
}