import java.util.Scanner;

public class Game
{
    private Board myBoard = new Board();
    private Player p1 = new Player();
    private Player p2 = new Player();
    private int count = 0;

    public void readPlayerData()
    {

        Scanner scan = new Scanner(System.in);

        System.out.print("Enter Player 1 Name : ");
        String name = scan.next();
        p1.setName(name);
        System.out.print("Select Player 1 Operator 'x' or 'o' : ");
        String op = scan.next();
        p1.setOperator(op.charAt(0));
        System.out.print("Enter Player 2 Name : ");
        name = scan.next();
        p2.setName(name);
        p2.setOperator((op.charAt(0) == 'x' ? 'o' : 'x'));
    }

    public void play()
    {
        Scanner scan = new Scanner(System.in);

        readPlayerData();
        myBoard.draw();

        while (!myBoard.isFull())
        {
            Player currentPlayer = p1;
            if (count % 2 == 1) currentPlayer = p2;

            while (true)
            {
                int pos;
                System.out.println( currentPlayer.getName() + " : " +  "Select Empty Position from 1 to 9 : ");

                pos = scan.nextInt();
                if (myBoard.replaceChar(pos, currentPlayer))
                {
                    break;
                }
            }

            myBoard.draw();
            if (myBoard.isWin(currentPlayer))
            {
                System.out.println("The winner is : " + currentPlayer.getName());
                break;
            }
            count++;
        }

        if (myBoard.isFull())
        {
            System.out.println("Game is Draw ..");
        }
    }
}
