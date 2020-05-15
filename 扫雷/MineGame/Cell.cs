using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MineGame{
    //格子类
    public class Cell{
        public string Character { get; private set; }//格子显示的符号
        public bool IsOpen { get; set; } //是否翻开
        public int Row { get; set; }
        public int Col { get; set; } //格子所在的行和列
        public Cell(int row, int col){
            this.Row = row;
            this.Col = col;
            this.IsOpen = false;
            this.Character = "";
        }
        public Cell(int row, int col, string character)
            :this(row,col){
            this.Character = character;
        }
        public List<Cell> GetRoundCells(List<Cell> AllCells){
            List<Cell> result = new List<Cell>();//装载查找结果的集合
            //从所有格子中循环找出周边的格子
            foreach (var cell in AllCells){
                if(this.Row == cell.Row && (this.Col+1 == cell.Col || this.Col-1==cell.Col)
                  || this.Col == cell.Col && (this.Row +1 == cell.Row || this.Row-1==cell.Row)
                  || this.Row-1==cell.Row && (this.Col-1==cell.Col || this.Col+1==cell.Col)
                  || this.Row + 1 == cell.Row && (this.Col - 1 == cell.Col || this.Col + 1 == cell.Col)
                ){
                    result.Add(cell);
                }
            }
            return result;
        }
        public virtual int Open(List<Cell> AllCells){
            return 0;
        }
    }
}
