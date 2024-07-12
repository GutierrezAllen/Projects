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
    private void displayBag(Inventory Cbag) {
        int nCount = 1;

        System.out.println("\n");
        System.out.println("\t\t==========================================================");
        System.out.println("\t\t|\t                   BAG...                        |");
        System.out.println("\t\t==========================================================");
        
        /*These lines of code allow the user to see how many pokemons are in their current inventory whether captured or starter pokemon. */
        for (Creature creep: Cbag.getInventory()) {
            if (creep.getbStat() == true) {
                System.out.print("\t\t [" + nCount + "] " + creep.getStrName()  +  "|"  + " Type: " + creep.getStrType() + " |" + " Family: " + creep.getcFamily() + " |"  + " EL: " + creep.getnEl() + "  <ACTIVE>\n");
            }

            else {
                System.out.println("\t\t [" + nCount + "] " + creep.getStrName()  +  "|"  + " Type: " + creep.getStrType() + " |" + " Family: " + creep.getcFamily() + " |"  + " EL: " + creep.getnEl());
            }
            nCount++;
        }
        System.out.println("\n\t\t==========================================================");
        System.out.println("\t\t|\t                   END...                        |");
        System.out.println("\t\t==========================================================");

    }

    /**
     * Method for changing active creature
     * This loop allows the user to first select whether or not they want to switch their active pokemon. They are then allowed to choose 
     * which pokemon in their inventory they want to use by setting it depending on where they are in the inventory.
     * @param bag = parameter name for an inventory variable.
     * This method is also used to swap creatures in battle.
     */
    private void invSelect(Inventory Cbag) {
        int nSize = Cbag.getInventorySize();
        int nTerm = 0, nOp, nChoice;
        
        do {
            if (nSize != 1) {
                System.out.println("\t\t \t              [1] SET ACTIVE                     ");
                System.out.println("\t\t \t              [2]   BACK                     ");
                System.out.print("\t\t\t            Select Action: ");
            }

            else {
                System.out.println("\t\t \t              [1]   BACK                     ");
                System.out.print("\t\t\t            Select Action: ");
            }
                nOp = intScan.nextInt();
            switch (nOp) {
                case 1: if (nSize != 1) {
                            System.out.println("\t\t \t              CHOOSE ACTIVE                     ");
                            System.out.print("\t\t\t               SET ACTIVE: ");
                            nChoice = intScan.nextInt();
                            Cbag.setActive(nChoice);
                            nTerm = 1;
                        }

                        else {
                            nTerm = 1;
                        }
                        break;
                
                case 2: if (nSize == 1) {
                            System.out.print("\t\t\t                Choose from list");
                        }

                        else {
                            nTerm = 1;
                        }
                      
                        break;

                default: System.out.print("\t\t\t                Choose from list");
                        break;
            }
        }while (nTerm != 1);
    }

    /**
     * Method for selecting which area to go
     */
    private void mapSelect() {
        int nTerm = 0, nOp, nNum;
        
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
                nOp = intScan.nextInt();
            }while (nOp < 1 || nOp > 4);

            switch (nOp) { //Switch case for the map
                case 1: nNum = 1;
                        areaAction(nNum);
                        break;
                case 2: 
                        nNum = 2;
                        areaAction(nNum);
                        break;
                case 3: nNum = 3;
                        areaAction(nNum);
                        break;
                case 4: nTerm = 1;
                        break;
            }
       }while (nTerm != 1);

    }

    /**
     * Method for displaying the map and action movement
     * @param num = this is a paramater for the constrictor in Area class.
     */
    private void areaAction(int nNum) {
        Area area = null;
        int nOp, nTerm = 0;
        boolean bSpook = false;

        if(nNum == 1) {
            area = new Area();
        }
        else if(nNum == 2) {
            area = new Area2();
        }
        else if(nNum == 3) {
            area = new Area3();
        }

        System.out.print("\n");
        System.out.println("=========================");
        System.out.println("|\t    Area...     |");
        System.out.println("=========================");
        System.out.println("| Rows = " + area.getnRows() + "              |");
        System.out.println("| Columns = " +  area.getnCols() +  "           |");
        System.out.println("=========================");

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
                nOp = intScan.nextInt();
            }while (nOp < 1 || nOp > 5);

            switch (nOp) {
                case 1: area.moveUp();
                        if (area.getpRow() > 0) {
                            bSpook = area.rateSpawn();
                            if (bSpook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(nNum);
                            }
                        }
                        break;
                case 2: area.moveDown();
                        if (area.getpRow() < area.getnRows() - 1) {
                            bSpook = area.rateSpawn();
                            if (bSpook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(nNum);
                            }
                        }
                        break;
                case 3: area.moveLeft();
                        if (area.getpCol() > 0) {
                             bSpook = area.rateSpawn();
                            if (bSpook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(nNum);
                            }
                        }
                        break;
                case 4: area.moveRight();
                        if (area.getpCol() < area.getnCols() - 1) {
                            bSpook = area.rateSpawn();
                            if (bSpook == true) {
                                System.out.print("\033\143");
                                System.out.flush();
                                System.out.println("Creature caught lacking in a bush");
                                showBattle(nNum);
                            }
                        }
                        break;
                case 5: nTerm = 1;
                        break;
            }
            
        }while (nTerm != 1);
    }

    /**
     * Method to show battle part
     * @param num = paramater for the constrictor in Area class.
     */
    private void showBattle(int nNum) {
        Area area = null;
        Creature Cenemy, Ccreep;
        int nBlood;
        int nOp, nDamage = 0, nHit = 0;;
        int nCounter = 3;
        int nCapRate = 0;
        int nCapScore = 0;
        int nId = 0;

        if(nNum == 1) {
            area = new Area();
            nId = rand.nextInt(10);
        }
        else if(nNum == 2) {
            area = new Area2();
            nId = rand.nextInt(19);
        }
        else if(nNum == 3) {
            area = new Area3();
            nId = rand.nextInt(37);
        }
           
        CCreeps.addCreature();
        Cenemy = CCreeps.getCreepMap().get(nId);
        Ccreep = CInventory.getActive();
        area.setHp(50);
        do {
            nHit = rand.nextInt(10) + 1;
            area.battleSpook(Cenemy, CInventory);
            System.out.println("====================================");
            System.out.println("| Runs in: " + nCounter + "                       |");
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
                nOp = intScan.nextInt();
            }while (nOp < 1 || nOp > 4);
            
            switch (nOp) {
                case 1: nDamage = nHit * CInventory.getActive().getnEl();
                        if ((Ccreep.getStrType() == "Fire" && Cenemy.getStrType() == "Grass")  
                        || (Ccreep.getStrType() == "Water" && Cenemy.getStrType() == "Fire")
                        || (Ccreep.getStrType() == "Grass" && Cenemy.getStrType() == "Water")) {
                            nDamage *= 1.5f;

                            System.out.println("Weakness exploited");
                            System.out.println("Damage: -" + nDamage + "\n");
                            nBlood = area.getHp();
                            nBlood = nBlood - nDamage;
                            area.setHp(nBlood);
                            nCounter--;
                            if (nCounter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }

                        else {
                            System.out.println("Damage: -" + nDamage + "\n");
                            nBlood = area.getHp();
                            nBlood = nBlood - nDamage;
                            area.setHp(nBlood);
                            nCounter--;
                            if (nCounter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }
                        break;

                case 2: displayBag(CInventory);
                        nCounter--;
                        if (nCounter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        break;

                case 3: nCapRate = (40 + 50 - area.getHp());
                        nCapScore = rand.nextInt(100) + 1;

                        System.out.println("Trying to catch creature");
                        if(nCapScore <= nCapRate) {
                            System.out.println("Slave obtained");
                            CInventory.addCreature(Cenemy);
                            nCounter = 0;
                        }

                        else {
                            System.out.println("You tripped");
                            nCounter--;
                            if (nCounter == 0) {
                                System.out.println("It refuses chains\n\n");
                            }
                        }
                       
                        break;

                case 4: nCounter = 0;
                        System.out.println("You chickened out\n\n");
                        break;
            }

        }while (nCounter != 0);
    }


    /**
     * @param bag = parameter for calling the Inventory.
     * This code just checks if you have 2 of the same Family and EL.
     * The result of this evolution will get the creature that it evolved into and makes it the active creature.
     */
    public void evolveCheck(Inventory Cbag) {

        if (Cbag.getInventorySize() < 2) {
            System.out.println("\nYou need more sla.... I mean creatures in your inventory to evolve");
        }

        else {
            displayBag(Cbag);
            creepEvolve(Cbag);
        }
    }

    /**
     * @param bag = parameter for calling the Inventory.
     * This just checks whether the first and second creature that you choose to evolve
     * is of the same family and EL, if not it will show invalid.
     * If it is of the same family and EL, it will then combine both creatures into an evolved creature.
     * The evolved creature will now become the active creature.
     */
    public void creepEvolve(Inventory Cbag) {
        int nOp1, nOp2;
        System.out.print("\n\t\t \t              Enter first creature: ");
        nOp1 = intScan.nextInt() - 1;
        System.out.print("\n\t\t \t             Enter second creature: ");
        nOp2 = intScan.nextInt() - 1;

        if(nOp1 < 0 || nOp1 >= Cbag.getInventorySize() || nOp2 < 0 || nOp2 >= Cbag.getInventorySize()) {
            System.out.println("Invalid creature selection. Choose among the ones present in the inventory");
        }

        else {
            Creature Ccreep1 = Cbag.getInventory().get(nOp1);
            System.out.println("Creature 1: " + Ccreep1.getStrName());
            Creature Ccreep2 = Cbag.getInventory().get(nOp2);
            System.out.println("Creature 2: " + Ccreep2.getStrName());
            Creature Cevolved =  new Creature();
            Creature Ccreature  = new Creature();
            if(Ccreep1.getnEl() == Ccreep2.getnEl() && Ccreep1.getcFamily() == Ccreep2.getcFamily() && Ccreep1.getnEl() != 4 && Ccreep2.getnEl() != 4) {
                Map<Integer, Creature> hCreepMap = Ccreature.getCreepMap();
                Ccreature.addCreature();
                for (Map.Entry<Integer, Creature> entry : hCreepMap.entrySet()) {
                    Ccreature = entry.getValue();
                    if (Ccreature.getnEl() == Ccreep1.getnEl() + 1 && Ccreature.getcFamily() == Ccreep1.getcFamily()) {
                        Cevolved = Ccreature;
                        Cbag.addCreature(Cevolved);
                        int nIndex = Cbag.getInventory().indexOf(Cevolved);
                        Cbag.setActive(nIndex + 1); 
                        System.out.println("Cannibali... Evolution was a Succes");
                        System.out.println("The sacrifices will be disposed");
                        System.out.println("The creature " + Cevolved.getStrName() + " is added to the collection and is set to active");
                        Cbag.delCreature(Ccreep1);
                        Cbag.delCreature(Ccreep2);
                        break;
                    }
                } 
            }
            else {
                System.out.println("The selected creatures don't have similarities in EL and Family");
            }
        }
    }

    public void addLoop(Creature Ccreep) {
        int i;
        for(i = 1; i < 18; i++) {
            CInventory.addCreature(Ccreep);
        } 
        System.out.println("Imported Slaves");
    }

    /**
     * Method to display choosing the starter
     */
    public void gameStart() {
        int nOp;
        Creature Ccreep;

        CCreeps.addCreature();
        System.out.println("\t\t==================================================");
        System.out.println("\t\t|\t        Choose your Creature...          |");
        System.out.println("\t\t==================================================");
        System.out.println("\t\t|\t [1] Strawander Type: Fire EL: 1         |");
        System.out.println("\t\t|\t [2] Chocowool Type: Fire EL: 1          |");
        System.out.println("\t\t|\t [3] Parfwit Type: Fire EL: 1            |");
        System.out.println("\t\t|\t [4] Brownisaur Type: Grass EL: 1        |");
        System.out.println("\t\t|\t [5] Frubat Type: Grass EL: 1            |");
        System.out.println("\t\t|\t [6] Malts Type: Grass EL: 1             |");
        System.out.println("\t\t|\t [7] Squirpie Type: Water EL: 1          |");
        System.out.println("\t\t|\t [8] Chocolite Type: Water EL: 1         |");
        System.out.println("\t\t|\t [9] Oshacone Type: Water EL: 1          |");
        System.out.println("\t\t==================================================");
        System.out.print("\t\t\t      My sl... creature is: ");
        
        //This do while loop will ask the user to input a number between 1 to 3 in order to select a pokemon that they will start with.
        do {
            nOp = intScan.nextInt();
        }while (nOp < 1 || nOp > 9);

        switch (nOp){
            case 1: Ccreep = CCreeps.getCreepMap().get(1);
                    CInventory.addCreature(Ccreep);
                    break;
            case 2: Ccreep = CCreeps.getCreepMap().get(2);
                    CInventory.addCreature(Ccreep);
                    break;
            case 3: Ccreep = CCreeps.getCreepMap().get(3);
                    CInventory.addCreature(Ccreep);
                    break;
            case 4: Ccreep = CCreeps.getCreepMap().get(4);
                    CInventory.addCreature(Ccreep);
                    break;
            case 5: Ccreep = CCreeps.getCreepMap().get(5);
                    CInventory.addCreature(Ccreep);
                    break;
            case 6: Ccreep = CCreeps.getCreepMap().get(6);
                    CInventory.addCreature(Ccreep);
                    break;
            case 7: Ccreep = CCreeps.getCreepMap().get(7);
                    CInventory.addCreature(Ccreep);
                    addLoop(Ccreep);
                    break;
            case 8: Ccreep = CCreeps.getCreepMap().get(8);
                    CInventory.addCreature(Ccreep);
                    break;
            case 9: Ccreep = CCreeps.getCreepMap().get(9);
                    CInventory.addCreature(Ccreep);
                    break;
        }
    }

    /**
     * Method to display options
     */
    public void displayOptions() {
        int nOp;
        int nTerm = 0;

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
             nOp = intScan.nextInt();
            }while (nOp < 1 || nOp > 4);
            
            switch (nOp) {
                case 1: displayBag(CInventory);
                        invSelect(CInventory);
                        break;
                case 2: mapSelect();
                        break;
                case 3: evolveCheck(CInventory);
                        break;
                case 4: nTerm = 1;
                        System.out.println("Thank you for playing. Save files will be added soon... Maybe, IDK... Prob if we ain't lazy");
                        break;
            }

        }while (nTerm != 1);
    }
}