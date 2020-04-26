<template>
  <div class="about">
      <Card class="bg">
            <p slot="title">动森材料计算器</p>
            <Row>
              <Col span="8" class="panel">
              <div class="content">
              <left></left>
              </div>
              </Col>

              <Col span="8" class="panel">
                <div class="content">
                  <center></center>
                </div>
              </Col>

              <Col span="8" class="panel">
                <div class="content">
                  
                </div>
              </Col>
            </Row>
      </Card>
  </div>
</template>

<script>
import left from '../components/left'
import center from '../components/center'
export default {
  name: 'about',
  components: {
    left,center
  },
  methods:{
    
  },
  mounted: function(){
    
  }
}
</script>

<style scoped>
.about{
  padding: 20px;
}
.bottom{
  display: flex;
  justify-content:space-around;
}
.panel{
  border-left: 1px solid rgba(50, 50, 50, 0.15);
  height: 735px;
  overflow: hidden;
}
.content{
   padding: 0px 5px 5px;
}
.b-bottom{
  width: 100%;
  height: 80px;
  margin: 0;
  padding: 0;
  background: white;
}
.left li{
  height: 30px;
  display: block;
  position: relative;
  line-height: 30px;
  
  padding: 2px;
  margin: 2px;
  cursor: pointer;
  border-radius: 5px;
}
.left li:hover{
  color: #1d231c;
  background: gray;
}
.bg{
  background: transparent;
  background-color: rgba(112 , 128, 148, 0.5);
}
</style>