namespace XO
{
    using System;

    internal class Game
    {
        private Board myBoard = new Board();
        private Player p1 = new Player();
        private Player p2 = new Player();
        private int count = 0;

        public void readPlayerData()
        {

            Console.Write("Enter Player 1 Name : ");
            String s = Console.ReadLine();
            p1.Name = s;
            Console.Write("Select Player 1 Operator 'x' or 'o' : ");
            String op = Console.ReadLine();
            p1.Operator = op[0];
            Console.Write("Enter Player 2 Name : ");
            s = Console.ReadLine();
            p2.Name = s;
            p2.Operator = (op[0] == 'x' ? 'o' : 'x');
        }

        public void play()
        {

            readPlayerData();
            myBoard.draw();

            while (!myBoard.isFull())
            {
                Player currentPlayer = p1;
                if (count % 2 == 1) currentPlayer = p2;

                while (true)
                {
                    int pos;
                    Console.WriteLine($"{currentPlayer.Name} :  Select Empty Posittion from 1 to 9 :");
                    pos = Convert.ToInt32(Console.ReadLine());
                    if (myBoard.replaceChar(pos, currentPlayer))
                    {
                        break;
                    }
                }

                myBoard.draw();
                if (myBoard.isWin(currentPlayer))
                {
                    Console.WriteLine("The winner is : " + currentPlayer.Name);
                    break;
                }
                count++;
            }

            if (myBoard.isFull())
            {
                Console.WriteLine("Game is Draw ..");
            }
        }
    }
}
