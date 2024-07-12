import java.util.Random;

public class Area {
    protected String[][] filler;
    protected int nRows;
    protected int nCols;
    protected int pRow;
    protected int pCol;
    protected Creature Ccreep = null;;
    protected int wHp;

    protected Random rand = new Random();

    /**
     * This just shows the layout of each area when the user inputs the specified number for each Area (1, 2, 3).
     * This initializes the fields wherein the player can move.
     */
    public Area() {
        this.nRows = 1;
        this.nCols = 5;
            
        this.filler = new String[nRows][nCols];
        this.pRow = 0;
        this.pCol = 0;
        this.wHp = 50;
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                filler[i][j] = "-";
            }
        }
        filler[pRow][pCol] = "P"; // Player's starting position
    }

    /**
     * This then displays the area chosen by the user and substitutes the values in the area using the values found
     * when the user inputs a specific Area layout.
     */
    public void displayArea() {
        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                System.out.print("| " + filler[i][j] + " ");
            }
            System.out.println("|");
        }
    }

      /**
     * Allows the user to move up in the Area if possible.
     */
    public void moveUp() {
        if (pRow > 0) {
            filler[pRow][pCol] = "-";
            pRow--;
            filler[pRow][pCol] = "P";
        }
        else{
            System.out.println("Cannot move up");
        }
    }

    /**
     * Allows the user to move down in the Area if possible.
     */
    public void moveDown() {
        if (pRow < nRows - 1) {
            filler[pRow][pCol] = "-";
            pRow++;
            filler[pRow][pCol] = "P";
        }
        else {
            System.out.println("Cannot move down");
        }
    }

    /**
     * Allows the user to move left in the Area if possible.
     */
    public void moveLeft() {
        if (pCol > 0) {
            filler[pRow][pCol] = "-";
            pCol--;
            filler[pRow][pCol] = "P";
        }
        else {
            System.out.println("Cannot move, left edge reached");
        }
    }

    /**
     * Allows the user to move right in the Area if possible. 
     */
    public void moveRight() {
        if (pCol < nCols - 1) {
            filler[pRow][pCol] = "-";
            pCol++;
            filler[pRow][pCol] = "P";
        }
        else {
            System.out.println("Cannot move, right edge reached");
        }
    }

    /**
     * This randomizes the chances wherein an encounter may happen, a random creature will have a 40% chance of spawning in eaceh cell in an Area.
     * @return pred = returns true if the rate is <= 40, else false
     */
    public boolean rateSpawn() {
        double rate =0.4; //40% chance
        boolean pred;
        
        if (Math.random() < rate) { //Math.random calls double values 
            pred = true;
        }
        else {
            pred = false;
        }
        return pred;
    }

    /**
     * This gives the integer value of the enemy HP
     * @return = returns the HP value of enemy
     */
    public int getHp() {
        return this.wHp;
    }

    /**
     * Changes the current value of enemy HP
     * @param hp = The HP of the enemy.
     */
    public void setHp(int hp) {
        this.wHp = hp;
    }

    /**
     * 
     * @return = returns player's current row
     */
    public int getpRow() {
        return this.pRow;
    }

    /**
     * @return = returns player's current column
     */
    public int getpCol() {
        return this.pCol;
    }

    /**
     * @return = returns table rows
     */
    public int getnRows() {
        return this.nRows;
    }

    /**
     * @return = returns table columns
     */
    public int getnCols() {
        return this.nCols;
    }

    /**
     * This shows the random creature's HP, as well as each of their information that is provided 
     * @param wild = This is the random creature that spawns in the Area.
     * @param bag = This calls your active creature to play on the field.
     */
    public void battleSpook (Creature Cwild, Inventory Cbag) {
        Ccreep = Cbag.getActive();
        
        System.out.println("====================================================");
        System.out.println("|                   Battle Phase                   |");
        System.out.println("====================================================");
        System.out.println("\t\t\t\tEnemy HP: " + wHp);
        System.out.println("\t\t\t\tEnemy: " + Cwild.getStrName());
        System.out.println("\t\t\t\tEL: " + Cwild.getnEl());
        System.out.println("\t\t\t\tType: " + Cwild.getStrType());
        System.out.println("You: " + Ccreep.getStrName());
        System.out.println("EL: " + Ccreep.getnEl());
        System.out.println("Type: " + Ccreep.getStrType());
        System.out.println("===================================================");
    }
}