using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MineGame
{
    public class MineCell : Cell{
        public MineCell(int row, int col) :
            base(row, col, "*"){
        }
        public override int Open(List<Cell> AllCells){
            for (int i = 0; i < AllCells.Count; i++) {
                AllCells[i].IsOpen = true;
            }
            return AllCells.Count;
        }
    }
}
