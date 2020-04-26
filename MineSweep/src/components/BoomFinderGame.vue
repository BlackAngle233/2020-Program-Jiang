<template>
<div>
  <div 
        v-for="row in rows" :key="Math.random() + row"
        class="game-content-row">
        <span 
            v-for="col in cols" :key="Math.random() + col"
            class="game-block"
            :class="[nodes[(row - 1) * cols + col - 1].isOpen ? 'open' : '',nodes[(row - 1) * cols + col - 1].isMarked ? 'isMarked' : '']"
            @click.left="leftClick(nodes[(row - 1) * cols + col - 1])"
            @click.right.prevent="rightClick(nodes[(row - 1) * cols + col - 1])">
            <span v-if="isOver">
                <span v-if="nodes[(row - 1) * cols + col - 1].isBoom">
                💣
                </span>
                <span v-else>
                {{ nodes[(row - 1) * cols + col - 1].boomNum }}
                </span>
            </span>
            <span v-else>
                <span v-if="nodes[(row - 1) * cols + col - 1].isMarked">
                ×
                </span>
                <span v-else-if="nodes[(row - 1) * cols + col - 1].boomNum">
                {{ nodes[(row - 1) * cols + col - 1].boomNum }}
                </span>
                <span v-else>
                     .
                </span>
            </span>


        </span>
    </div>
    <div class="toolList">
        <cell-group>
            <cell class="cbutton" @click.native="restart">
                重新开始
            </cell>
            <cell class="cbutton">
                剩余炸弹数：{{lastedNum}}
            </cell>
            <cell class="cbutton" @click.native="back">
                选择难度
            </cell>
        </cell-group>
    </div>
  </div>
</template>

<script>

export default {
  name: 'boomFinderGame',
  methods:{
      init() {
          Object.assign(this.$data, this.$options.data());
        this.rows = this.mapInfo[0];
        this.cols = this.mapInfo[1];
        this.boomNum = this.mapInfo[2];
        this.setBoom();
        this.initNode();
        this.nodes.forEach(i =>{

                console.log(i.isBoom);

        });
        this.lastedNum = this.boomNum;
    },
      setBoom() {
        let bucket = [];
        for (let i = 0; i < this.boomNum; i++) {
            const n = Math.floor(Math.random() * this.rows * this.cols);

            if (bucket.indexOf(n) == -1) {
                bucket.push(n);
            } else {
                i--;
            }
        }
        this.boomPos = bucket;
    },
      initNode(){
        let arr=[];
        for(let i = 0;i < this.rows * this.cols;i++){
            let temp = {
                isMarked:false,
                isOpen:false,
                isBoom:false,
                boomNum:0,
                index:i
            };
            temp.isBoom = this.boomPos.indexOf(i) > -1;

            if(!temp.isBoom){
                this.getBoomAround(temp,i);
            }
            arr.push(temp);
            console.log(i +":" + temp.isMarked);
        }
        this.nodes = arr;
      },
      getNodeAround(index){
          index++;
          let aroundRes = [];
          const localRow = Math.ceil(index/this.cols);
          const localCol = Math.ceil(index % this.cols) || this.cols;

          for(let i = (localRow == 1 ? 0:-1);i < (localRow == this.rows ? 1 : 2);i++){
              for(let j = (localCol == 1 ? 0:-1);j < (localCol == this.cols ? 1 : 2);j++){
                  const tempIndex = (localRow + i - 1) * this.cols + localCol + j;
                  aroundRes.push(tempIndex - 1);
              }
          }
          return aroundRes;
      },
      // getFour(index){
      //     let arr = [];
      //     let r = Math.floor(index/this.cols);
      //     let c = index %this.cols;
      //     console.log(index+":"+r+" "+c);
      //     if(r > 0){
      //         arr.push((r -1)*this.cols + c);
      //     }
      //     if(r < this.rows - 1){
      //         arr.push((r + 1)*this.cols +c);
      //     }
      //     if(c > 0){
      //         arr.push((c - 1)+ r*this.cols);
      //     }
      //     if(c < this.cols - 1){
      //         arr.push((c + 1)+r*this.cols);
      //     }
      //
      //     return arr;
      // },
      getBoomAround(node,index){
          const nodeArr = this.getNodeAround(index);
          nodeArr.forEach(i =>{
              if(this.boomPos.indexOf(i) > -1){
                  node.boomNum++;
              }
          })
      },
      leftClick(node){
          if(this.isOver){
              return;
          }

          if(!node.isOpen) {
              if (!node.isBoom) {
                  if (node.boomNum) {
                      node.isOpen = true;
                  } else {
                      node.isOpen = true;
                      this.floodFill(node.index);
                  }
              }else{
                  node.isOpen = true;
                  this.gameOver(1);
              }
          }
      },
      rightClick(node){
          if(this.isOver){
              return;
          }
          if(!node.isOpen){
              node.isMarked = !node.isMarked;
              this.check(node);
          }
      },
      floodFill(index){
          let arr =  this.getNodeAround(index);
          arr.forEach(i =>{
             if(!this.nodes[i].isMarked && !this.nodes[i].isOpen && !this.nodes[i].isBoom){
                 if(this.nodes[i].boomNum){
                     this.nodes[i].isOpen = true;
                     return;
                 }else {
                     this.nodes[i].isOpen = true;
                     this.floodFill(i);
                 }
             }
          });

      },
      gameOver(type){
          switch (type) {
              case 1:alert("踩到雷啦！");this.isOver = true;break;
              case 2:alert("恭喜找到了所有的雷！");this.isOver = true;break;
          }
          this.$emit("gameover");
      },
      check(node){
          if(node.isMarked){
              if(this.lastedNum === 0){
                  node.isMarked = false;
                  return;
              }
              if(node.isBoom){
                  this.markNum++;
              }else {
                  this.wrongMarkNum++;
              }
              this.lastedNum--;
          }else {
              if(node.isBoom){
                  this.markNum--;
              }else {
                  this.wrongMarkNum--;
              }
              this.lastedNum++;
          }
          if(this.markNum === this.boomNum){
              this.gameOver(2);
          }
      },
      back(){
        this.$emit("back");
      },
      restart(){
          this.init();
          this.$emit("restart");
      }
  },
  data(){
    return{
      
        rows:9,
        cols:9,
        boomNum:20,
        boomPos:[],
        nodes:[{
          isMarked:false,
          isOpen:false,
          isBoom:false,
          boomNum:0,
          index:0
        }],
        time:0,
        isOver:false,
        markNum:0,
        wrongMarkNum:0,
        lastedNum:0
    }
  },
    props: {
        mapInfo: {
            type: Array
        },
        showGame:{
            type:Boolean
        }
    },
  created: function(){
    this.init();
  }
}
</script>

<style scoped>


.game-block{
  display: inline-block;
  width: 40px;
  height: 40px;
  margin: 2px;
  line-height: 40px;
  background: gray;
  cursor: pointer;
    border: 1px solid gray;
}
.game-block>span{
    visibility: hidden;
}
.open>span{
    visibility: visible;

}
.isMarked>span{
    visibility: visible;
    color: red;

}
.open{
    background-color: #ddd;
}
    .toolList{
        position: fixed;
        right: 0;
        top: 40%;
        background-color: #42b983;
        height: auto;
        border-radius: 15px;
    }
cbutton{
    color: white;
    border-radius: 15px;
}
</style>