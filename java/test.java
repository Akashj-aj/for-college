abstract class shape
{
    int a, b;
    abstract void printArea (double a, double b);
}

class rectangle extends shape
{
    void printArea (double a, double b)
    {
        System.out.println("area of rectangle: "+(a*b));
    }
}

class triangle extends shape
{
    void printArea(double a, double b)
    {
        System.out.println("area of triangle: "+(0.5*a*b));
    }
}

class circle extends shape
{
    void printArea(double a, double b)
    {
        System.out.println("area of circle: "+(3.14*a*b));
    }
}

class test
{
    public static void main(String[] args) 
    {
        rectangle r = new rectangle();
        r.printArea(2, 5);
        triangle t = new triangle();
        t.printArea(4, 5);
        circle c = new circle();
        c.printArea(3, 5);
    }
}