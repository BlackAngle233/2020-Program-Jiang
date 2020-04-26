<template>
  <div class="home">
<!--    <img alt="Vue logo" src="../assets/logo.png">-->
    <div class="toolList">
        <h1>时间：{{timer.s}}</h1>
    </div>
  <card class="uuu">
    <div v-if="showGame">
      <boom :map-info="mapInfo" :show-game="showGame" @gameover="stopCount" @back="Showlevel" @restart="restart"></boom>
    </div>
    <div v-else>
      <set @chooseLevel="choose"></set>
    </div>
  </card>
  </div>
</template>

<script>
// @ is an alias to /src
import boom from '@/components/BoomFinderGame.vue'
import set from '@/components/BoomFinderLevel.vue'
export default {
  name: 'Home',
  components: {
    boom,set
  },
  data(){
    return{
      mapInfo:[9,9,10],
      showGame:false,
      timer:{
        ms:0,
        s:0
      }
    }
  },
  methods:{
    choose(level){
      console.log("sdsd");
      this.mapInfo = level;
      this.showGame = true;
      this.startCount();
    },
    countDown(){
      this.timer.ms += 50;
      if(this.timer.ms % 1000 === 0)
      {
        this.timer.s = this.timer.ms / 1000;
      }

    },
    startCount(){
      this.time = setInterval(this.countDown,50);
    },
    stopCount(){
      clearInterval(this.time);
    },
    initCount(){
      this.timer.ms = 0;
      this.timer.s = 0;
    },
      Showlevel(){
          this.showGame = false;
          this.stopCount();
          this.initCount();
      },
      restart() {
          this.stopCount();
          this.initCount();
          this.startCount();
      }
  }
}
</script>
<style scoped>
  .toolList{

  }
    .uuu{
        width: 100%;
        height: 50%;
    }
</style>