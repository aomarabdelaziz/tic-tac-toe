import 'board.dart';
import 'player.dart';
import 'dart:io';
class Game 
{
    Board myBoard = Board();
    Player p1 = Player();
    Player p2 = Player();
    int _count = 0;

    void readPlayerData()
    {
        stdout.write("Enter Player 1 Name: ");
        String? name = stdin.readLineSync();
        p1.setName = name;
        stdout.write("Player 1 Select your Operator 'x' Or 'o': ");
        String? op = stdin.readLineSync();
        p1.setOperator = op;
        stdout.write("Enter Player 2 Name: ");
        name = stdin.readLineSync();
        p2.setName = name;
        stdout.write("Player 2 Select your Operator 'x' Or 'o': ");
        op = stdin.readLineSync();
        p2.setOperator = p1.getOperator == "x" ? "o" : "x";

    }

    void play() 
    {
        readPlayerData();
        myBoard.draw();
        while (!myBoard.isFull()) 
        {
             Player currentPlayer = p1;
             if (_count % 2 == 1) currentPlayer = p2;
             while(true)
             {
                 stdout.writeln( currentPlayer.getName! + " : " +  "Select Empty Position from 1 to 9 : ");
                 int pos = int.parse(stdin.readLineSync()!);
                 if(myBoard.replaceCharacter(pos, currentPlayer))
                 {
                     break; 
                 }
             }
             myBoard.draw();
            if (myBoard.isWin(currentPlayer))
            {
                 stdout.writeln("The winner is : " + currentPlayer.getName! );
                break;
            }
            _count++;

        }

         if (myBoard.isFull())
        {
            stdout.writeln("Game is Draw ..");
        }
    }
}