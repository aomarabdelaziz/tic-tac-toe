namespace XO
{
    internal class Player
    {
        private char m_operator;
        private string m_name;
        public char Operator { get { return m_operator; } set { m_operator = value; } }
        public string Name { get { return m_name; } set { m_name = value; } }

        public Player() { }
        public Player(string name, char op)
        {
            this.m_name = name;
            this.m_operator = op;
        }

    }
}
