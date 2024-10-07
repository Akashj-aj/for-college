class FirstThread extends Thread
{
		  public static void main(String[]args) throws InterruptedException //use only in 'main'
		  {  
				    FirstThread f1 = new FirstThread();
				    System.out.println(f1.isAlive()); //False
				    f1.start();
				    System.out.println(f1.isAlive()); //True
		  }
}