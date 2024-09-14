/*Create a class book which contains 4 members: name, author, price, number of pages. 
Include a constructor to set the value of to the members. 
Include methods to set  and get the details of the objects.
Develop a java program to creqate 'n' book objects.  */
import static java.lang.System.exit;
import java.util.Scanner;
public class Book
{
	String name,author;
	int price,num_of_pages;
	String complete_details;
	Book()
	{
		name = "ABC";
		author="ABC_AUTHOR";
		price=0;
		num_of_pages=0;
	}
	void set()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("enter the name:");
		name=sc.nextLine();
		System.out.println("enter the author:");
		author=sc.nextLine();
		System.out.println("enter the price:");
		price=sc.nextInt();
		System.out.println("enter the number of pages:");
		num_of_pages=sc.nextInt();
		complete_details="name="+name+"\n"+"author:"+author+"\n"+"price: "+Integer.toString(price)+"\n"+"number of pages: "+Integer.toString(num_of_pages);
		
	}
	void get()
	{
		System.out.println(complete_details);
	}

	public static void main(String[] args)
	{
		int ch,c=0;
		Scanner sc=new Scanner(System.in);
		Book[] b=new Book[10];
		for(;;)
		{
			System.out.println("menu\n1.Insert\n2.Display \n3.Exit");
			System.out.println("enter your choice");
			ch=sc.nextInt();
			switch(ch)
			{
			    case 1:b[c]=new Book();
			           b[c++].set();
			           break;
			    case 2:System.out.println("Book details:");
			           for(int i=0;i<c;i++)
			              b[i].get();
			           break;
			    case 3:System.out.println("Thank you");
			           exit(0);
			    default:System.out.println("Invalid choice");
			            break;
			}
		}
		

	}

}