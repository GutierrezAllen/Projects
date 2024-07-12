public class Area2  extends Area{

    /**
     * This just shows the layout of each area when the user inputs the specified number for each Area (1, 2, 3).
     * nRows shows the horizontal lanes and nCols shows the vertical lanes that the user is allowed to move on.
     */
    public Area2() {
        super();
        this.nRows = 3;
        this.nCols = 3;
        this.filler = new String[nRows][nCols];
        this.pRow = 0;
        this.pCol = 0;
        this.wHp = 50;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                filler[i][j] = "-";
            }
        }
        filler[pRow][pCol] = "P";
    }

    
}
