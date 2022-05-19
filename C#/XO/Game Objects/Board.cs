namespace XO
{
    using System;
    internal class Board
    {
        private char[][] m_arr;
        public char[][] Arr { get { return m_arr; } set { m_arr = value; } }

        public Board()
        {
            this.Arr = new char[][]
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
        public bool isEmpty(int index)
        {
            if (index < 1 || index > 9) return false;
            int row = getRow(index);
            int col = getCol(index);
            string op = this.Arr[row][col].ToString().ToLower();
            if (op == "o" || op == "x")
                return false;
            return true;
        }
        public bool replaceChar(int index, Player player)
        {
            if (isEmpty(index))
            {
                int row = getRow(index);
                int col = getCol(index);
                this.Arr[row][col] = player.Operator;
                return true;
            }
            return false;
        }

        public void draw()
        {
            for (int i = 0; i < 3; i++)
            {
                Console.WriteLine("-----------------");
                for (int j = 0; j < 3; j++)
                {
                    Console.Write("| " + this.Arr[i][j] + "  ");
                }
                Console.WriteLine(" |");
            }
            Console.WriteLine("-----------------");
        }

        public bool isFull()
        {
            int count = 0;
            for (int i = 1; i <= 9; i++)
            {
                if (isEmpty(i)) count++;
            }
            if (count == 0) return true;
            return false;
        }
        public bool isWin(Player player)
        {
            if (this.Arr[0][0] == player.Operator && this.Arr[0][1] == player.Operator && this.Arr[0][2] == player.Operator)
                return true;
            if (this.Arr[1][0] == player.Operator && this.Arr[1][1] == player.Operator && this.Arr[1][2] == player.Operator)
                return true;
            if (this.Arr[2][0] == player.Operator && this.Arr[2][1] == player.Operator && this.Arr[2][2] == player.Operator)
                return true;
            if (this.Arr[0][0] == player.Operator && this.Arr[1][0] == player.Operator && this.Arr[2][0] == player.Operator)
                return true;
            if (this.Arr[0][1] == player.Operator && this.Arr[1][1] == player.Operator && this.Arr[2][1] == player.Operator)
                return true;
            if (this.Arr[0][2] == player.Operator && this.Arr[1][2] == player.Operator && this.Arr[2][2] == player.Operator)
                return true;
            if (this.Arr[0][0] == player.Operator && this.Arr[1][1] == player.Operator && this.Arr[2][2] == player.Operator)
                return true;
            if (this.Arr[0][2] == player.Operator && this.Arr[1][1] == player.Operator && this.Arr[2][0] == player.Operator)
                return true;
            return false;
        }

    }
}
