import 'player.dart';
class Board 
{

  final array = List.generate(3, (i) => List.generate(3, (j) => (i * 3 + j + 1).toString(), growable: false),growable: false);

  int getRow(int index) => (index - 1) ~/ 3 ;
  int getColumn(int index) => (index - 1) % 3 ;

  bool isEmpty(int index)
  {
    if(index < 1 || index > 9) return false;
    int row = getRow(index);
    int col = getColumn(index);

    if(array[row][col] == "o" || array[row][col] == "x") 
    {
      return false;
    }

    return true;

  }

  bool replaceCharacter(int index , Player player)
  {
      if(isEmpty(index))
      {
        
         int row = getRow(index).toInt();
         int col = getColumn(index).toInt();
         array[row][col] = player.getOperator!;
         return true;
      
      }

      return false;
  }

  void draw()
  {

    //  for (int i = 0; i < 3; i++) 
    //  {
    //        stdout.writeln("-----------------");
    //         for (int j = 0; j < 3; j++)
    //         {
    //            stdout.writeln("| ${array[i][j]} "  " ");
    //         }
    //         stdout.writeln(" |");
    //  }
    //       stdout.writeln("-----------------");

        array.forEach((element) => print(element));


  }

  bool isFull()
  {
      bool full = true;
       for (int i = 1; i <= 9; ++i) {
        if (isEmpty(i))
        {
            full = false;
            break;
        }
    }
    return full;
  }

  bool isWin(Player player)
    {
        if (array[0][0] == player.getOperator && array[0][1] == player.getOperator && array[0][2] == player.getOperator)
            return true;
        if (array[1][0] == player.getOperator && array[1][1] == player.getOperator && array[1][2] == player.getOperator)
            return true;
        if (array[2][0] == player.getOperator && array[2][1] == player.getOperator && array[2][2] == player.getOperator)
            return true;
        if (array[0][0] == player.getOperator && array[1][0] == player.getOperator && array[2][0] == player.getOperator)
            return true;
        if (array[0][1] == player.getOperator && array[1][1] == player.getOperator && array[2][1] == player.getOperator)
            return true;
        if (array[0][2] == player.getOperator && array[1][2] == player.getOperator && array[2][2] == player.getOperator)
            return true;
        if (array[0][0] == player.getOperator && array[1][1] == player.getOperator && array[2][2] == player.getOperator)
            return true;
        if (array[0][2] == player.getOperator && array[1][1] == player.getOperator && array[2][0] == player.getOperator)
            return true;
        return false;
    }



}