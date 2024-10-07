import java.util.*;
import java.io.*;
public class hashmap {
    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        HashMap <String, String> student = new HashMap <String, String> ();
        for(;;){
            System.out.println("Menu\n 1. Insert\n 2. search\n 3. Delete\n 4. Display\n 5. exit\n Enter your choice: ");
            int n = sc.nextInt();
            switch(n){
                case 1:
                    System.out.println("enter student usn: ");
                    String stdUSN = sc.next();
                    System.out.println("enter student name: ");
                    String stdname = sc.next();
                    student.put(stdUSN, stdname);
                    break;
                case 2:
                    System.out.println("enter USN to search: ");
                    String searchUSN = sc.next();
                    System.out.println(searchUSN + ":" + student.get(searchUSN));
                    break;
                case 3:
                    System.out.println("enter USN to delete: ");
                    String delUSN = sc.next();
                    System.out.println(delUSN + ":" + student.remove(delUSN));
                    break;
                case 4:
                    for(String i: student.keySet())
                        System.out.println("key: " + i + "value: " + student.get(i));
                    break;
                case 5:
                    System.exit(0);
                    break;
                default:
                    System.out.println("wrong choice");
            }
        }
    }
}
