using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MineGame{
    //空白格子
    public class EmptyCell :Cell{
        public EmptyCell(int row, int col) :
            base(row, col, ""){
        }
        public override int Open(List<Cell> AllCells){
            int count = 0;

            // 翻开格子
            if (this.IsOpen) return 0;
            this.IsOpen = true;
            count++;
            List<Cell> cells = GetRoundCells(AllCells);
            //翻开周围的格子
            for (int i = 0; i < cells.Count; i++){
                count += cells[i].Open(AllCells);
            }
            return count;
        }
    }
}
