<template>
  <div> 
    <img :src=icon alt="">
    <p id="itemName">{{name}}</p>
    <hr>
    <h3>材料：</h3>
    <!-- <ul v-for="item in material">
        <li>{{item.name}}*{{item.num}}</li>
      </ul>             -->
      <List v-for="item in material" border size="small"> 
            <ListItem class="itemList">
            <!-- <ListItem>{{item.name}}*{{item.num}} -->
              <ListItemMeta avatar="https://dev-file.iviewui.com/userinfoPDvn9gKWYihR24SpgC319vXY8qniCqj4/avatar" :title=item.name :description=item.num />
            </ListItem>
      </List>
  </div>
</template>

<script>
import idata from '../static/data.json'
export default {
  name:'center',
  data(){
      return{
        activeId:0,
        name:'大头菜',
        material:[],
        icon:''
      };
  },
  watch:{
    activeId:function(){

    }
  },
  components: {
    
  },
  methods:{
    pushma(_name,_num){
      this.material.push({
        name:_name,
        num:_num
      })
    },
    readJison(){
    this.name = idata["name"];
    this.icon = idata["url"];
    for(let i in idata["ma"]){
      this.pushma(i,idata["ma"][i]);
    }
    }
  },
  mounted: function(){
    this.readJison();
  }
  
}
</script>

<style scoped>
.itemList{
  background: transparent;
  background-color: rgba(255 , 255, 255, 0.2);
}
#itemName{
  font-style:initial;
}
</style>