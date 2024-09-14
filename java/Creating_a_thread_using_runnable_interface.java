public class Creating_a_thread_using_runnable_interface implements Runnable
{
    public static void main(String[]args)
    {
        Creating_a_thread_using_runnable_interface c = new Creating_a_thread_using_runnable_interface();
        Thread t1 = new Thread (c);
        t1.start();
    }
    public void run()
    {
        System.out.println("hello world");
    }
}
