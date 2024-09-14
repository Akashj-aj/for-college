class two_thread extends Thread
{
    public static void main (String[]args)
    {
        A a = new A();
        B b = new B();
        a.start();
        b.start();
    }
}
class A extends two_thread
{
    public void run()
    {
        for(int i=0;i<3;i++)
        {
            try
            {
                Thread.sleep(10000);
            }
            catch (Exception e)
            {
                System.out.println(e);
            }
            System.out.println("vidyavardhaka college of engineering");
        }
    }
}
class B extends two_thread
{
    public void run()
    {
        for(int i=0;i<3;i++)
        {
            try
            {
                Thread.sleep(2000);
            }
            catch(Exception e)
            {
                System.out.println(e);
            }
            System.out.println("CSE - AIML");
        }
    }
}