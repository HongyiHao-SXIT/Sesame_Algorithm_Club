<template>
  <nav class="navbar">
    <div class="logo">
      <img src="@/assets/images/logo.png" alt="弘茗智能科技" height="40">
    </div>
    <div class="nav-links">
      <router-link to="/">首页</router-link>
      <router-link to="/products">产品</router-link>
      <router-link to="/team">团队</router-link>
      <router-link to="/projects">项目</router-link>
      <router-link to="/contact">联系我们</router-link>
    </div>
    <div class="language-switcher">
      <button @click="switchLanguage('zh')">中文</button>
      <button @click="switchLanguage('en')">EN</button>
    </div>
  </nav>
</template>

<script setup>
import { useI18n } from 'vue-i18n'

const { locale } = useI18n()

const switchLanguage = (lang) => {
  locale.value = lang
}
</script>

<style scoped>
.navbar {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 20px 5%;
  background-color: white;
  box-shadow: 0 2px 10px rgba(0,0,0,0.1);
  position: fixed;
  width: 90%;
  z-index: 100;
}

.logo img {
  height: 40px;
}

.nav-links {
  display: flex;
  gap: 30px;
}

.nav-links a {
  text-decoration: none;
  color: var(--dark-bg);
  font-weight: 500;
  transition: color 0.3s;
}

.nav-links a:hover {
  color: var(--primary-blue);
}

.nav-links a.router-link-exact-active {
  color: var(--secondary-orange);
}

.language-switcher {
  display: flex;
  gap: 10px;
}

.language-switcher button {
  background: none;
  border: 1px solid #ddd;
  padding: 5px 10px;
  border-radius: 4px;
  cursor: pointer;
  transition: all 0.3s;
}

.language-switcher button:hover {
  background: #f0f0f0;
}
</style>