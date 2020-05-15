using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MineGame{
    public class Map{
        public List<Cell> AllCells { get; set; }
        public int Rows { get; set; }
        public int Cols { get; set; } 
        public int Mines { get; set; } 
        public int Total { get; set; } 
        public Map(int rows, int cols,int mines){
            AllCells = new List<Cell>();
            Init(rows, cols,mines);
        }
        public void Init(int rows, int cols,int mines){
            this.Rows = rows;
            this.Cols = cols;
            this.Mines = mines;
            this.Total = 0;
            AllCells.Clear();
            //创建所有格子对象
            for(int i=0;i<rows;i++)
                for (int j = 0; j < cols; j++){
                    Cell cell = new Cell(i, j);
                    AllCells.Add(cell);
                }
            //随机分布地雷
            Random random = new Random();
            for (int i = 0; i < Mines; ){
                int index = random.Next(AllCells.Count - 1);
                if (!(AllCells[index] is MineCell)){
                    AllCells[index]  = new MineCell(AllCells[index].Row, AllCells[index].Col);
                    i++;
                }
            }
            //计算每个格子周围的地雷数
            for (int i = 0; i < AllCells.Count; i++){
                if (AllCells[i] is MineCell)
                    continue;
                List<Cell> cells = AllCells[i].GetRoundCells(AllCells);
                int count = 0;
                foreach (var cell in cells){
                    if (cell is MineCell)
                        count++;
                }
                if (count > 0)
                    AllCells[i] = new NumberCell(AllCells[i].Row, AllCells[i].Col, count);
                else
                    AllCells[i] = new EmptyCell(AllCells[i].Row, AllCells[i].Col);
            }
        }
        public void Open(int index)
        {
            Cell cell = AllCells[index];
            int count = cell.Open(AllCells);

            //根据是否踩到地雷，给已经翻开的格子数赋值
            if (count == AllCells.Count)
                Total = count;
            else
                Total += count;
        }
        public int Judge(){
            if (Total == AllCells.Count)
                return 0;
            else if (Total == AllCells.Count - Mines)
                return 1;
            else
                return -1;
        }
    }
}
