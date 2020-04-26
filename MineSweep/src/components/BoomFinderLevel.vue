<template>
  <div class="content"> 
    <h1>难度选择</h1>
            <CellGroup v-for="item in difficult">
                <Cell :title=item.text class="cell" @click.native="choose(item.data)">
                </Cell>
            </CellGroup>
            <!--<ul v-for="item in difficult">
              <li @click="choose(item.data)">{{item.text}}</li>
            </ul>-->
             
  </div>
</template>

<script>

export default {
  name: 'boomFinderLevel',
  methods:{
    choose(level){
      this.$emit("chooseLevel",level);
    }
  },
  data(){
    return{
      difficult:[
      {
        text:'简单',
        data:[9,9,10]
      },
      {
        text:'中等',
        data:[9,12,20]
      },
      {
        text:'困难',
        data:[16,30,99]
      }
    ]
    }
    
  },
  mounted: function(){
    
  }
}
</script>

<style scoped>
.cell{
  border-radius: 15px;
}
.cell:active{
  background: ivory;
}
.cell:checked{
  background: lawngreen;
}
.content{
  margin-left: 40%;
  margin-right: 40%;
  background: transparent;
  background-color: rgba(255, 255, 255, 0.4);
}
</style>