<template>
  <div id="app">
    <NavBar />
    <router-view />
    <FooterSection />
  </div>
</template>

<script setup>
import NavBar from '@/components/NavBar.vue'
import FooterSection from '@/components/FooterSection.vue'
</script>

<style>
@import url('https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700&display=swap');

:root {
  --primary-blue: #0066cc;
  --secondary-orange: #ff6600;
  --dark-bg: #1a1a1a;
  --light-bg: #f5f5f5;
}

* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

body {
  font-family: 'Roboto', 'Microsoft YaHei', sans-serif;
  color: #333;
  line-height: 1.6;
}

#app {
  display: flex;
  flex-direction: column;
  min-height: 100vh;
}

section {
  padding: 80px 5%;
}

h2 {
  font-size: 2.5rem;
  margin-bottom: 2rem;
  text-align: center;
  color: var(--primary-blue);
}
</style>