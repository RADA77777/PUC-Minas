public class main
{
    public static void main(String[] args) 
    {
        System.out.println("OI");
        
        Teste<No> t = new Teste<>();
        No t2 = new No();
        t2.set(10);
        t.set(t2);
        System.out.println(t.get());
        
    }
}


interface Entidade {
    public int get();
    public void set(int a);
}


class Teste<G extends Entidade>
{
    public int a;

    void set(G a)
    {
        G b = new G(No.class.getConstructor());
        this.a = a.get();
    }

    int get()
    {
        return this.a;
    }
}

class No implements Entidade
{
    int contem = 0;

    <G>No()
    {
        this.contem = 0;
    }
    public void set(int a)
    {
        this.contem = a;
    }

    public int get()
    {
        return this.contem;
    }
}