import java.util.Arrays;

class Item {
    int weight, value;
    Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
}

public class FractionalKnapsack {
    static double knapsack(int capacity, Item[] items) {
        Arrays.sort(items, (a, b) -> Double.compare((double) b.value / b.weight, (double) a.value / a.weight));
        double totalValue = 0;
        for (Item item : items) {
            if (capacity >= item.weight) {
                capacity -= item.weight;
                totalValue += item.value;
            } else {
                totalValue += (double) item.value * capacity / item.weight;
                break;
            }
        }
        return totalValue;
    }
    
    public static void main(String[] args) {
        Item[] items = { new Item(10, 60), new Item(20, 100), new Item(30, 120) };
        int capacity = 50;
        System.out.println("Max value = " + knapsack(capacity, items));
    }
}
