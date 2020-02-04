using System;

namespace lab1csVar5
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, m;
            Console.WriteLine("Введите позицию ладьи по горизонтали");
            m=Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("по вертикали");
            n=Convert.ToInt32(Console.ReadLine());
            String[][] chess = new String[8][];
            for(int s=0; s<8; s++)
            {
                chess[s] = new String[8];
                for(int f=0; f<8; f++)
                {
                    chess[s][f] = "1";
                }
            }
            for(int i=0; i<chess.Length; i++)
            {               
                for (int t=0; t<chess.Length; t++)
                {
                if (i == (m-1))
                {
                    chess[i][t] = "*";
                }                  
                if(t == (n-1))
                        {
                        chess[i][t] = "*";
                }
                }                
            }
            chess[m-1][n-1] = "s";
            for(int x=0; x<chess.Length; x++)
            {
                foreach(String u in chess[x])
                {
                    Console.Write(u + "  ");
                }
                Console.WriteLine();
            }  
        }
    }
}
