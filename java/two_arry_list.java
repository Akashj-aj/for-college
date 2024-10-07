import java.io.*;
import java.util.*;

public class two_arry_list {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> al1 = new ArrayList<Integer>();
        ArrayList<Integer> al2 = new ArrayList<Integer>();
        
        for (;;) {
            System.out.println("Menu\n 1. Insert\n 2. Get specified Index\n 3. Delete\n 4. Display\n 5. Compare Array lists\n 6. Exit\n Enter your choice: ");
            int n = sc.nextInt();
            
            switch (n) {
                case 1: 
                    System.out.println("Enter the array list name: 1 for al1 and 2 for al2");
                    int alname = sc.nextInt();
                    System.out.println("Enter element: ");
                    int alitem = sc.nextInt();
                    switch (alname) {
                        case 1:
                            al1.add(alitem);
                            break;
                        case 2:
                            al2.add(alitem);
                            break;
                        default:
                            System.out.println("Wrong array list name");
                    }
                    break;

                case 2: 
                    System.out.println("Enter the array list name: 1 for al1 and 2 for al2");
                    int alname2 = sc.nextInt();
                    System.out.println("Enter index: ");
                    int alindex2 = sc.nextInt();
                    switch (alname2) {
                        case 1:
                            if (alindex2 < al1.size()) {
                                System.out.println("Element at index " + alindex2 + " in array list 1 is " + al1.get(alindex2));
                            } else {
                                System.out.println("Invalid index");
                            }
                            break;
                        case 2:
                            if (alindex2 < al2.size()) {
                                System.out.println("Element at index " + alindex2 + " in array list 2 is " + al2.get(alindex2));
                            } else {
                                System.out.println("Invalid index");
                            }
                            break;
                        default:
                            System.out.println("Wrong array list name");
                    }
                    break; 

                case 3:
                    System.out.println("Enter the array list name: 1 for al1 and 2 for al2");
                    int alname3 = sc.nextInt();
                    System.out.println("Enter index: ");
                    int alindex3 = sc.nextInt();
                    switch (alname3) {
                        case 1:
                            if (alindex3 < al1.size()) {
                                System.out.println("Element removed from al1: " + al1.remove(alindex3));
                            } else {
                                System.out.println("Invalid index");
                            }
                            break;
                        case 2:
                            if (alindex3 < al2.size()) {
                                System.out.println("Element removed from al2: " + al2.remove(alindex3));
                            } else {
                                System.out.println("Invalid index");
                            }
                            break;
                        default:
                            System.out.println("Wrong array list name");
                    }
                    break; 

                case 4: 
                    System.out.println("ArrayList 1: " + al1);
                    System.out.println("ArrayList 2: " + al2);
                    break; 

                case 5: 
                    if (al1.equals(al2)) {
                        System.out.println("Both array lists have the same contents");
                    } else {
                        System.out.println("The two array lists have different contents");
                    }
                    break; 

                case 6: 
                    System.exit(0);

                default:
                    System.out.println("Wrong choice");
            }
        }
    }
}
