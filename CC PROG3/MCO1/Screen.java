import java.util.*;

public class Screen {
    Creature CCreeps = new Creature();
    Inventory CInventory = new Inventory();
    Scanner intScan = new Scanner(System.in);
    Random rand = new Random();

    /**
     * Displays the inventory list
     * @param bag = displays the content
     */
    private void displayBag(Inventory bag) {
        int count = 1;

        System.out.println("\n");
        System.out.println("\t\t==========================================================");
        System.out.println("\t\t|\t                   BAG...                        |");
        System.out.println("\t\t==========================================================");
        
        /*These lines of code allow the user to see how many pokemons are in their current inventory whether captured or starter pokemon. */
        for (Creature creep: bag.getInventory()) {
            if (creep.getbStat() == true) {
                System.out.print("\t\t [" + count + "] " + creep.getStrName()  +  "|"  + " Type: " + creep.getStrType() + " |" + " Family: " + creep.getcFamily() + " |"  + " EL: " + creep.getnEl() + "  <ACTIVE>\n");
            }

            else {
                System.out.println("\t\t [" + count + "] " + creep.getStrName()  +  "|"  + " Type: " + creep.getStrType() + " |" + " Family: " + creep.getcFamily() + " |"  + " EL: " + creep.getnEl());
            }
            count++;
        }
        System.out.println("\n\t\t==========================================================");
        System.out.println("\t\t|\t                   END...                        |");
        System.out.println("\t\t==========================================================");

        invSelect(bag); //calls the method for changing the active creature
    }

    /**
     * Method for changing active creature
     * This loop allows the user to first select whether or not they want to switch their active pokemon. They are then allowed to choose 
     * which pokemon in their inventory they want to use by setting it depending on where they are in the inventory.
     * @param bag = parameter name for an inventory variable.
     */
    private void invSelect(Inventory bag) {
        int size = bag.getInventorySize();
        int term = 0, op, choice;
        
        do {
            if (size != 1) {
                System.out.println("\t\t \t              [1] SET ACTIVE                     ");
                System.out.println("\t\t \t              [2]   BACK                     ");
                System.out.print("\t\t\t            Select Action: ");
            }

            else {
                System.out.println("\t\t \t              [1]   BACK                     ");
                System.out.print("\t\t\t            Select Action: ");
            }
                op = intScan.nextInt();
            switch (op) {
                case 1: if (size != 1) {
                            System.out.println("\t\t \t              CHOOSE ACTIVE                     ");
                            System.out.print("\t\t\t               SET ACTIVE: ");
                            choice = intScan.nextInt();
                            bag.setActive(choice);
                            term = 1;
                        }

                        else {
                            term = 1;
                        }
                        break;
                
                case 2: if (size == 1) {
                            System.out.print("\t\t\t                Choose from list");
                        }

                        else {
                            term = 1;
                        }
                      
                        break;

                default: System.out.print("\t\t\t                Choose from list");
                        break;
            }
        }while (term != 1);
    }

    /**
     * Method for selecting which area to go
     */
    private void mapSelect() {
        int term = 0, op, num;
        
       do {
            System.out.println("\n\t\t==================================================");
            System.out.println("\t\t|\t           Choose Area...                |");
            System.out.println("\t\t==================================================");
            System.out.println("\t\t|\t           [1] AREA 1                    |");
            System.out.println("\t\t|\t           [2] AREA 2                    |");
            System.out.println("\t\t|\t           [3] AREA 3                    |");
            System.out.println("\t\t|\t           [4] BACK                      |");
            System.out.println("\t\t==================================================");
            System.out.print("\t\t\t         Select Action: ");
            do {
                op = intScan.nextInt();
            }while (op < 1 || op > 4);

            switch (op) { //Switch case for the map
                case 1: num = 1;
                        areaAction(num);
                        break;
                case 2: System.out.println("Slave Cap in Area not possible. A war against Creature activists is on going\n");
                        break;
                case 3: System.out.println("Slave Cap in Area not possible. A war against Creature activists is on going\n");
                        break;
                case 4: term = 1;
                        break;
            }
       }while (term != 1);

    }

    /**
     * Method for displaying the map and action movement
     * @param num = this is a paramater for the constrictor in Area class.
     */
    private void areaAction(int num) {
        Area area = new Area(num);
        int op, term = 0;
        boolean spook = false;

        do {
            System.out.print("\n\n");
            area.displayArea();
            System.out.println("====================================");
            System.out.println("|\t      Movement...          |");
            System.out.println("====================================");
            System.out.println("| [1] Up                [2] Down   |");
            System.out.println("| [3] Left              [4] Right  |");
            System.out.println("| [5] Exit                         |");
            System.out.println("====================================");
            System.out.print("Select Action: ");
           
           /*This code allows the user to make the character move within a given area using the Area class, they are able to move up,down,left, or right
            * depending on the intention of the user and its calling the functions inside the Area class in order to execute the moves properly. 
            */
            do {
                op = intScan.nextInt();
            }while (op < 1 || op > 5);

            switch (op) {
                case 1: area.moveUp();
                        if (area.getpRow() > 0) {
                            spook = area.rateSpawn();
                            if (spook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(num);
                            }
                        }
                        break;
                case 2: area.moveDown();
                        if (area.getpRow() < area.getnRows() - 1) {
                            spook = area.rateSpawn();
                            if (spook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(num);
                            }
                        }
                        break;
                case 3: area.moveLeft();
                        if (area.getpCol() > 0) {
                             spook = area.rateSpawn();
                            if (spook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(num);
                            }
                        }
                        break;
                case 4: area.moveRight();
                        if (area.getpCol() < area.getnCols() - 1) {
                            spook = area.rateSpawn();
                            if (spook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(num);
                            }
                        }
                        break;
                case 5: term = 1;
                        break;
            }
            
        }while (term != 1);
    }

    /**
     * Method to show battle part
     * @param num = paramater for the constrictor in Area class.
     */
    private void showBattle(int num) {
        Area area = new Area(num);
        Creature enemy, creep;
        int blood;
        int op, damage = 0, hit = 0;;
        int counter = 3;
        int capRate = 0;
        int capScore = 0;
           
        int id = rand.nextInt(10);
        CCreeps.addCreature();
        enemy = CCreeps.getCreepMap().get(id);
        creep = CInventory.getActive();
        area.setHp(50);
        do {
            hit = rand.nextInt(10) + 1;
            area.battleSpook(enemy, CInventory);
            System.out.println("====================================");
            System.out.println("| Runs in: " + counter + "                       |");
            System.out.println("====================================");
            System.out.println("|\t       Action...           |");
            System.out.println("====================================");
            System.out.println("| [1] Attack         [2] Switch    |");
            System.out.println("| [3] Capture        [4] Run       |");
            System.out.println("====================================");
            System.out.print("Select Action: ");
            
            /*This do while loop scans the user's pokemon and enemy pokemon type and if it finds a weakness the damage increases by 1.5 
            as well as having an option to switch pokemon and trying to capture the enemy once it is lower hp and lastly having a run away button.*/
            do {
                op = intScan.nextInt();
            }while (op < 1 || op > 4);
            
            switch (op) {
                case 1: damage = hit * CInventory.getActive().getnEl();
                        if ((creep.getStrType() == "Fire" && enemy.getStrType() == "Grass")  
                        || (creep.getStrType() == "Water" && enemy.getStrType() == "Fire")
                        || (creep.getStrType() == "Grass" && enemy.getStrType() == "Water")) {
                            damage *= 1.5f;

                            System.out.println("Weakness exploited");
                            System.out.println("Damage: -" + damage + "\n");
                            blood = area.getHp();
                            blood = blood - damage;
                            area.setHp(blood);
                            counter--;
                            if (counter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }

                        else {
                            System.out.println("Damage: -" + damage + "\n");
                            blood = area.getHp();
                            blood = blood - damage;
                            area.setHp(blood);
                            counter--;
                            if (counter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }
                        break;

                case 2: displayBag(CInventory);
                        counter--;
                        if (counter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        break;

                case 3: capRate = (40 + 50 - area.getHp());
                        capScore = rand.nextInt(100) + 1;

                        System.out.println("Trying to catch creature");
                        if(capScore <= capRate) {
                            System.out.println("Slave obtained");
                            CInventory.addCreature(enemy);
                            counter = 0;
                        }

                        else {
                            System.out.println("You tripped");
                            counter--;
                            if (counter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }
                       
                        break;

                case 4: counter = 0;
                        System.out.println("You chickened out\n\n");
                        break;
            }

        }while (counter != 0);
    }

    /**
     * Method to display choosing the starter
     */
    public void gameStart() {
        int op;
        Creature creep;

        CCreeps.addCreature();
        System.out.println("\t\t==================================================");
        System.out.println("\t\t|\t        Choose your Creature...          |");
        System.out.println("\t\t==================================================");
        System.out.println("\t\t|\t [1] Strawander Type: Fire EL: 1         |");
        System.out.println("\t\t|\t [2] Brownisaur Type: Grass EL: 1        |");
        System.out.println("\t\t|\t [3] Squirpie Type: Water EL: 1          |");
        System.out.println("\t\t==================================================");
        System.out.print("\t\t\t      My sl... creature is: ");
        
        //This do while loop will ask the user to input a number between 1 to 3 in order to select a pokemon that they will start with.
        do {
            op = intScan.nextInt();
        }while (op < 1 || op > 3);

        switch (op){
            case 1: creep = CCreeps.getCreepMap().get(1);
                    CInventory.addCreature(creep);
                    System.out.println("\t\t\t\t     CULTURED\n"); 
                    break;
            case 2: creep = CCreeps.getCreepMap().get(4);
                    CInventory.addCreature(creep);
                    System.out.println("\t\t\t\t  Bruh... seriously?\n");
                    break;
            case 3: creep = CCreeps.getCreepMap().get(7);
                    CInventory.addCreature(creep);
                    System.out.println("\t\t\t\t    Acceptable\n");
                    break;
        }
    }

    /**
     * Method to display options
     */
    public void displayOptions() {
        int op;
        int term = 0;

        do {
            System.out.println("\n\t\t==================================================");
            System.out.println("\t\t|\t              OPTIONS...                 |");
            System.out.println("\t\t==================================================");
            System.out.println("\t\t|\t        [1] Inventory                    |");
            System.out.println("\t\t|\t        [2] Areas                        |");
            System.out.println("\t\t|\t        [3] Evolution                    |");
            System.out.println("\t\t|\t        [4] Exit                         |");
            System.out.println("\t\t==================================================");
            System.out.print("\t\t\t         Select Action: ");

            // this do while loop with a switch case serves as the way to switch between functions inv, area, evo, and exiting.
            do {
             op = intScan.nextInt();
            }while (op < 1 || op > 4);
            
            switch (op) {
                case 1: displayBag(CInventory);
                        break;
                case 2: mapSelect();
                        break;
                case 3:  System.out.println("Unavailable");
                        break;
                case 4: term = 1;
                        System.out.println("Thank you for playing. Save files will be added soon... Maybe, IDK... Prob if we ain't lazy");
                        break;
            }

        }while (term != 1);
    }
}