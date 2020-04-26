import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import GeminiScrollbar from 'vue-gemini-scrollbar'
import iView from 'view-design';
import 'view-design/dist/styles/iview.css';

Vue.use(GeminiScrollbar);
Vue.use(iView);

Vue.config.productionTip = false

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')

