using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MineGame{
    //数字格子
    public class NumberCell : Cell{
        public NumberCell(int row, int col, int number)
            : base(row, col, number.ToString()){
        }
        public override int Open(List<Cell> AllCells){
            if (this.IsOpen) return 0;
            this.IsOpen = true;
            return 1;
        }
    }
}
