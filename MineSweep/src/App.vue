<template>
  <div id="app">
<!--    <div id="nav">
      <router-link to="/">Home</router-link> |
      <router-link to="/about">About</router-link>
    </div>-->
    <router-view/>
  </div>
</template>



<style>
html,body{
	height: 100%;
}
body{
  padding: 0;
  margin: 0;
  background: #e9f4ec url(https://3g.ali213.net/images/zhuanti/dongsen/bg.jpg) repeat-x center 0;
  background-repeat: no-repeat;
  background-size: 100% 100%;
}
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

#nav {
  padding: 0;
  margin: 0;
  width: 100%;
  height: 50px;
  background: gray;
}

#nav a {
  font-weight: bold;
  color: #2c3e50;
}

#nav a.router-link-exact-active {
  color: #42b983;
}

</style>
