class Point
{
    private int x;
    private int y;

    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void setX(int x)
    {
        this.x = x;
    }

    public void setY(int y)
    {
        this.y = y;
    }

    public void setXY(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void show()
    {
        System.out.println("x = " + x);
        System.out.println("y = " + y);
    }
}

public class PointDemo
{
    public static void main(String[] args)
    {
        Point p = new Point();

        p.setX(10);
        p.setY(20);
        p.show();

        p.setXY(30, 40);
        p.show();
    }
}
