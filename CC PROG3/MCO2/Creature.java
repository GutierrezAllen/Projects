import java.util.*;

public class Creature {
    private String strName;
    private String strType;
    private char cFamily;
    private int nEl;
    private boolean bStat;
    private HashMap<Integer, Creature> hCreepMap = new HashMap<>();

    /**
     * Reads predefined information of creatures.
     */
    public Creature() {
        this.strName = "";
        this.strType = "";
        this.cFamily = ' ';
        this.nEl = 0;
        this.bStat = false;
        this.hCreepMap = new HashMap<>();
    }

    /**
     * This constrictor is used for adding of creatures into the HashMap.
     * @param strName = Name of creature
     * @param strType = Type of creature (Fire, Grass, Water)
     * @param cFamily = Family of creature
     * @param nEl = Evolution level of creature (E1,E2,E3)
     */
    public Creature(String strName, String strType, char cFamily, int nEl) {
        this.strName = strName;
        this.strType = strType;
        this.cFamily = cFamily;
        this.nEl = nEl;
        this.bStat = false;
    }

    /**
     * Gets the name of the creature
     * @return = name of the creature.
     */
    public String getStrName() {
        return this.strName;
    }

    /**
     * Gets the type of the creature
     * @return = type of the creature.
     */
    public String getStrType() {
        return this.strType;
    }

    /**
     * Gets the family of the creature
     * @return = family of the creature.
     */
    public char getcFamily() {
        return this.cFamily;
    }

    /**
     * Gets the evolution level of the creature
     * @return = evolution level of the creature.
     */
    public int getnEl() {
        return this.nEl;
    }

    /**
     * 
     * @return = returns true if the creature is active else false
     */
    public boolean getbStat() {
        return this.bStat;
    }

    /**
     * 
     * @param strName = sets the name of the creature.
     */
    public void setStrName(String strName) {
        this.strName = strName;
    }

    /**
     * 
     * @param strType = sets the type of the creature
     */
    public void setStrType(String strType) {
        this.strType = strType;
    }

    /**
     * @param cFamily = sets the family of the creature.
     */
    public void setcFamily(char cFamily) {
        this.cFamily = cFamily;
    }

    /**
     * @param nEl = sets the evoluton level of the creature.
     */
    public void setnEl(int nEl) {
        this.nEl = nEl;
    }

    /**
     * @param bStat = Sets the status of the creature whether active(true) or not(false)
     */
    public void setbStat(boolean bStat) {
        this.bStat = bStat;
    }

    /**
     * This shows the list of creatures/pokemons that are available to the user once you start playing the game wherein at the very start
     * you are allowed to choose between 3 creatures and later on find the rest in the area/battlefield.
     * This adds the creature into a hashmap. The hashmap is the list of all available creatures, that's why there is no parameter.
     */
    public void addCreature() {
        // EL: 1 Creatures
        hCreepMap.put(1, new Creature("Strawander", "Fire", 'A', 1));
        hCreepMap.put(2, new Creature("Chocowool", "Fire", 'B', 1));
        hCreepMap.put(3, new Creature("Parfwit", "Fire", 'C', 1));
        hCreepMap.put(4, new Creature("Brownisaur", "Grass", 'D', 1));
        hCreepMap.put(5, new Creature("Frubat", "Grass", 'E', 1));
        hCreepMap.put(6, new Creature("Malts", "Grass", 'F', 1));
        hCreepMap.put(7, new Creature("Squirpie", "Water", 'G', 1));
        hCreepMap.put(8, new Creature("Chocolite", "Water", 'H', 1));
        hCreepMap.put(9, new Creature("Oshacone", "Water", 'I', 1));
    
        // EL: 2 Creatures
        hCreepMap.put(10, new Creature("Strawleon", "Fire", 'A', 2));
        hCreepMap.put(11, new Creature("Chocofluff", "Fire", 'B', 2));
        hCreepMap.put(12, new Creature("Parfure", "Fire", 'C', 2));
        hCreepMap.put(13, new Creature("Chocosaur", "Grass", 'D', 2));
        hCreepMap.put(14, new Creature("Golberry", "Grass", 'E', 2));
        hCreepMap.put(15, new Creature("Kiricake", "Grass", 'F', 2));
        hCreepMap.put(16, new Creature("Tartortle", "Water", 'G', 2));
        hCreepMap.put(17, new Creature("Chocolish", "Water", 'H', 2));
        hCreepMap.put(18, new Creature("Dewice", "Water", 'I', 2));

        // EL: 3 Creatures
        hCreepMap.put(19, new Creature("Strawizard", "Fire", 'A', 3));
        hCreepMap.put(20, new Creature("Candaros", "Fire", 'B', 3));
        hCreepMap.put(21, new Creature("Parfelure", "Fire", 'C', 3));
        hCreepMap.put(22, new Creature("Fudgasaur", "Grass", 'D', 3));
        hCreepMap.put(23, new Creature("Croberry", "Grass", 'E', 3));
        hCreepMap.put(24, new Creature("Velvevoir", "Grass", 'F', 3));
        hCreepMap.put(25, new Creature("Pietoise", "Water", 'G', 3));
        hCreepMap.put(26, new Creature("Icesundae", "Water", 'H', 3));
        hCreepMap.put(27, new Creature("Samurcone", "Water", 'I', 3));

        // EL:4 Creatures
        hCreepMap.put(28, new Creature("Mega Strawizard", "Fire", 'A', 4));
        hCreepMap.put(29, new Creature("Mega Candaros", "Fire", 'B', 4));
        hCreepMap.put(30, new Creature("Mega Parfelure", "Fire", 'C', 4));
        hCreepMap.put(31, new Creature("Mega Fudgasaur", "Grass", 'D', 4));
        hCreepMap.put(32, new Creature("Mega Croberry", "Grass", 'E', 4));
        hCreepMap.put(33, new Creature("Mega Velvevoir", "Grass", 'F', 4));
        hCreepMap.put(34, new Creature("Mega Pietoise", "Water", 'G', 4));
        hCreepMap.put(35, new Creature("Mega Icesundae", "Water", 'H', 4));
        hCreepMap.put(36, new Creature("Mega Samurcone", "Water", 'I', 4));

    }

    /**
     * @return = returns HashMap
     */
    public Map<Integer, Creature> getCreepMap() {
        return this.hCreepMap;
    }
}