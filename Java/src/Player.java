public class Player
{
    private char Operator;
    private String Name;

    public Player() { }

    public Player(String name, char op)
    {
        this.Name = name;
        this.Operator = op;
    }
    public char getOperator() {
        return Operator;
    }

    public void setOperator(char operator) {
        Operator = operator;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }



}
