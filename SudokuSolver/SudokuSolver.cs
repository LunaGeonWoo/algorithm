using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.ComponentModel.Design;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Security;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SudokuSolveBacktrackingr
{
    internal class Program
    {
        public struct Point
        {
            public Point(int y, int x)
            {
                Y = y;
                X = x;
            }
            public int Y { get; }
            public int X { get; }
        }

        public static int[,] board = new int[9, 9] {
            {6,3,0,0,0,2,1,0,0},
            {8,0,1,0,0,6,0,7,0},
            {0,5,0,0,8,0,0,0,0},
            {0,0,0,0,0,7,0,0,9},
            {4,0,2,0,6,0,5,0,0},
            {0,8,0,0,0,0,0,0,0},
            {0,0,0,2,0,0,0,5,0},
            {1,0,6,0,4,0,2,0,0},
            {0,0,3,0,0,0,0,0,0},
        };
        public static List<int[,]> validSudokus = new List<int[,]>();
        public static List<Point> validCheck = new List<Point>();

        static void PrintSudoku(int[,] board)
        {
            Console.WriteLine("┌───────┬───────┬───────┐");
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j % 3 == 0) Console.Write("│ ");

                    if (board[i,j] == 0) Console.Write("  ");
                    else Console.Write(board[i,j].ToString()+' ');
                }
                Console.Write("│ ");

                if (i == 2 || i == 5)
                {
                    Console.Write("\n├───────┼───────┼───────┤");
                }
                Console.WriteLine();
            }
            Console.WriteLine("└───────┴───────┴───────┘");
        }

        static bool IsValid(int y, int x, int n)
        {
            for(int i=0; i<9; i++)
            {
                if (board[y,i] == n || board[i,x] == n || board[y / 3 * 3 + i / 3,x / 3 * 3 + i % 3] == n)
                {
                    return false;
                }
            }
            return true;
        }

        static void SudokuSolveBacktracking(int index)
        {
            if(index == validCheck.Count)
            {
                validSudokus.Add(board.Clone() as int[,]); //This code for Deep Copy
                return;
            }
            

            int x = validCheck[index].X, y = validCheck[index].Y;
            for(int i=1; i<=9; i++)
            {
                if (IsValid(y, x, i))
                {
                    board[y, x] = i;
                    SudokuSolveBacktracking(index + 1);
                    board[y, x] = 0;
                }
            }
        }

        static void Main(string[] args)
        {
            PrintSudoku(board);

            for (int i=0; i<9; i++)
                for(int j=0; j<9; j++)
                    if (board[i, j] == 0) 
                        validCheck.Add(new Point(i,j));

            SudokuSolveBacktracking(0);

            for(int i=0; i<validSudokus.Count; i++)
                PrintSudoku(validSudokus[i]);
        }
    }
}
