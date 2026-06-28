interface Test
{
    int square(int n);
}

class Arithmetic implements Test
{
    public int square(int n)
    {
        return n * n;
    }
}

public class ToTestInt
{
    public static void main(String[] args)
    {
        Arithmetic obj = new Arithmetic();

        int result = obj.square(5);

        System.out.println("Square = " + result);
    }
}
