public class Board
{
    private char[][] arr;

    public Board()
    {
        this.arr = new char[][]
                {

                        new char[]{ '1', '2', '3' },
                        new char[]{ '4', '5', '6' },
                        new char[]{ '7', '8', '9' }

                };


    }

    public int getRow(int index)
    {
        return ((index - 1) / 3);
    }
    public int getCol(int index)
    {
        return ((index - 1) % 3);
    }
    public boolean isEmpty(int index)
    {
        if (index < 1 || index > 9) return false;
        int row = getRow(index);
        int col = getCol(index);

        if (this.arr[row][col] == 'o'|| this.arr[row][col] == 'x' )
            return false;
        return true;
    }
    public boolean replaceChar(int index, Player player)
    {
        if (isEmpty(index))
        {
            int row = getRow(index);
            int col = getCol(index);
            this.arr[row][col] = player.getOperator();
            return true;
        }
        return false;
    }

    public void draw()
    {
        for (int i = 0; i < 3; i++)
        {
            System.out.println("-----------------");
            for (int j = 0; j < 3; j++)
            {
                System.out.print("| " + this.arr[i][j] + "  ");
            }
            System.out.println(" |");

        }
        System.out.println("-----------------");
    }

    public boolean isFull()
    {
        int count = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (isEmpty(i)) count++;
        }
        if (count == 0) return true;
        return false;
    }
    public boolean isWin(Player player)
    {
        if (this.arr[0][0] == player.getOperator() && this.arr[0][1] == player.getOperator() && this.arr[0][2] == player.getOperator())
            return true;
        if (this.arr[1][0] == player.getOperator() && this.arr[1][1] == player.getOperator() && this.arr[1][2] == player.getOperator())
            return true;
        if (this.arr[2][0] == player.getOperator() && this.arr[2][1] == player.getOperator() && this.arr[2][2] == player.getOperator())
            return true;
        if (this.arr[0][0] == player.getOperator() && this.arr[1][0] == player.getOperator() && this.arr[2][0] == player.getOperator())
            return true;
        if (this.arr[0][1] == player.getOperator() && this.arr[1][1] == player.getOperator() && this.arr[2][1] == player.getOperator())
            return true;
        if (this.arr[0][2] == player.getOperator() && this.arr[1][2] == player.getOperator() && this.arr[2][2] == player.getOperator())
            return true;
        if (this.arr[0][0] == player.getOperator() && this.arr[1][1] == player.getOperator() && this.arr[2][2] == player.getOperator())
            return true;
        if (this.arr[0][2] == player.getOperator() && this.arr[1][1] == player.getOperator() && this.arr[2][0] == player.getOperator())
            return true;
        return false;
    }

}
