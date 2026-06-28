class Box
{
    int length;
    int breadth;

    Box(int length, int breadth)
    {
        this.length = length;
        this.breadth = breadth;
    }

    void area()
    {
        int area = length * breadth;
        System.out.println("Area = " + area);
    }
}

public class Box3D extends Box
{
    int height;

    Box3D(int length, int breadth, int height)
    {
        super(length, breadth);
        this.height = height;
    }

    void volume()
    {
        int volume = length * breadth * height;
        System.out.println("Volume = " + volume);
    }

    public static void main(String[] args)
    {
        Box3D obj = new Box3D(5, 4, 3);

        obj.area();
        obj.volume();
    }
}
