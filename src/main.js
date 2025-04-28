import { createApp } from 'vue'
import { createRouter, createWebHistory } from 'vue-router'
import { createI18n } from 'vue-i18n'
import App from './App.vue'
import HomeView from './views/HomeView.vue'

// 国际化配置
const messages = {
  zh: {
    hero: {
      title: '创造未来的智能科技',
      subtitle: '来自理工科高校的福瑞控团队，用专业与热情打造创新产品',
      cta: '了解我们的项目'
    },
    products: {
      title: '我们的产品',
      details: '查看详情'
    },
    team: {
      title: '我们的团队'
    }
  },
  en: {
    hero: {
      title: 'Creating Future Intelligent Technology',
      subtitle: 'A team of tech-savvy furry fans building innovative products with expertise and passion',
      cta: 'Explore Our Projects'
    },
    products: {
      title: 'Our Products',
      details: 'View Details'
    },
    team: {
      title: 'Our Team'
    }
  }
}

const i18n = createI18n({
  locale: 'zh',
  fallbackLocale: 'en',
  messages
})

// 路由配置
const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/', component: HomeView },
    // 其他路由...
  ]
})

// 创建应用
const app = createApp(App)

app.use(i18n)
app.use(router)

app.mount('#app')