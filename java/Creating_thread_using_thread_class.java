/* creating a threas using "thread class" method */

class Creating_thread_using_thread_class extends Thread
{
    public static void main(String[]args)
    {
        Creating_thread_using_thread_class c = new Creating_thread_using_thread_class();
        c.start();
    }
    public void run()
    {
        System.out.println("hello");
    }
}
