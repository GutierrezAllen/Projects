import java.util.*;

public class Inventory {
    private List<Creature> invBag; //This shows the list of creatures in the inventory.


    /**
     * This method is the array list of the inventory.
     * Instantiates the arraylist.
     */
    public Inventory() {
       this.invBag = new ArrayList<>();
    }

    /**
     * This adds a creature to the inventory.
     * @param wCreep = Creature to be added
     * @return = returns true if its the starter creature, otherwise false
     */
    public boolean addCreature(Creature Ccreep){
        invBag.add(Ccreep);
        if (invBag.size() == 1) {
            invBag.get(0).setbStat(true);
        }
        return false;
    }

    public void delCreature(Creature Ccreep) {
        invBag.remove(Ccreep);
    }
    
    /**
     * This sets a creature to become the active creature being used by the user.
     * @param num = returns the index of the element 
     */
    public void setActive(int nNum) {
        nNum -= 1;
        if (nNum >= 0 && nNum < invBag.size()) {
            invBag.get(nNum).setbStat(true);
            for (int i = 0; i < invBag.size(); i++) {
             if (i != nNum) {
                invBag.get(i).setbStat(false);
                }
            }
        }
        else {
            System.out.println("Wrong input. Try again");
        }
    }

    /**
     * Gets the active creature set by the user.
     * @return = returns the active creature.
     */
    public Creature getActive() {
        for (Creature sCreeps : invBag) {
            if (sCreeps.getbStat() == true) {
                return sCreeps;
            }
        }
        return null;
    }

    /**
     * Shows the list of inventory.
     * @return = returns inventory
     */
    public List<Creature> getInventory() {
        return invBag;
    }

    /**
     * Inventory size of the user.
     * @return = returns size of inventory (no. of elements)
     */
    public int getInventorySize(){
        int size = invBag.size();
        return size;
    }
}