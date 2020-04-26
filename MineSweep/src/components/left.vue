<template>
  <div> 
                <CellGroup>              
                <Cell title="基础" to="#" class="cell">
                    <!-- <Badge :count="12" slot="extra" /> -->
                </Cell>
                <Cell title="基础" to="#" class="cell">
                    <!-- <Badge :count="12" slot="extra" /> -->
                </Cell>
            </CellGroup>
             
  </div>
</template>

<script>

export default {
  name: 'about',
  components: {
    
  },
  methods:{
    
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
</style>