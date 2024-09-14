/* This program demonstrates the multithread concept */

class Multithread extends Thread
{
    public static void main(String[]args)
    {
        Multithread t1 = new Multithread();
        t1.setName("Thread 1");
        Multithread t2 = new Multithread();
        t2.setName("Thread 2");
        Multithread t3 = new Multithread();
        t3.setName("Thread 3");
        t1.start();
        t2.start();
        t3.start();
    }
    public void run ()
    {
        System.out.println("Thread one");
        System.out.println(Thread.currentThread().getName());
    }
}