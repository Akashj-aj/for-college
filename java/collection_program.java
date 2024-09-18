import java.util.ArrayList;
import java.util.Iterator;

class collection_program
{
    public static void main(String[]args)
    {
        ArrayList a1 = new ArrayList<>();
        a1.add(10);
        a1.add(20);
        a1.add(30);
        System.out.println(a1); //10 20 30

        ArrayList a2 = new ArrayList<>();
        a2.add(40);
        a2.add(50);
        System.out.println(a2); // 40 50
        a1.addAll(a2);

        System.out.println(a1.hashCode());
        System.out.println(a1); // 10 20 30 40 50

        System.out.println(a1.equals(a2)); // False

        System.out.println(a1.contains(20)); // True
        System.out.println(a1.contains(a2)); // True

        System.out.println(a1.isEmpty()); // False
        System.out.println((a1.clear())); // NULL

        System.out.println(a1.remove(10)); // 20 30 40 50
        System.out.println(a1.removeAll()); //  NULL

        Iterator itr = a1.iterator();
        while(itr.hasNext())
        {
            System.out.println(itr.next()); 
        }
    }
}