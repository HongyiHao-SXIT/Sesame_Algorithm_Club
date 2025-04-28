<template>
  <section class="hero-section">
    <div class="hero-content">
      <h1>{{ t('hero.title') }}</h1>
      <p>{{ t('hero.subtitle') }}</p>
      <button class="cta-button" @click="scrollToProducts">
        {{ t('hero.cta') }}
      </button>
    </div>
    <div class="scroll-indicator" @click="scrollToProducts">
      <span></span>
    </div>
  </section>
</template>

<script setup>
import { useI18n } from 'vue-i18n'

const { t } = useI18n()

const scrollToProducts = () => {
  const productsSection = document.querySelector('.products-section')
  productsSection.scrollIntoView({ behavior: 'smooth' })
}
</script>

<style scoped>
.hero-section {
  height: 100vh;
  background: linear-gradient(135deg, var(--primary-blue), var(--dark-bg));
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  color: white;
  text-align: center;
  padding-top: 80px;
  position: relative;
}

.hero-content {
  max-width: 800px;
  padding: 0 20px;
}

.hero-content h1 {
  font-size: 3.5rem;
  margin-bottom: 20px;
  animation: fadeInUp 1s ease;
}

.hero-content p {
  font-size: 1.5rem;
  margin-bottom: 40px;
  animation: fadeInUp 1s ease 0.3s forwards;
  opacity: 0;
}

.cta-button {
  background: var(--secondary-orange);
  color: white;
  border: none;
  padding: 15px 30px;
  font-size: 1.2rem;
  border-radius: 50px;
  cursor: pointer;
  transition: all 0.3s;
  animation: fadeInUp 1s ease 0.6s forwards;
  opacity: 0;
}

.cta-button:hover {
  background: #e65c00;
  transform: translateY(-3px);
  box-shadow: 0 10px 20px rgba(0,0,0,0.2);
}

.scroll-indicator {
  position: absolute;
  bottom: 40px;
  left: 50%;
  transform: translateX(-50%);
  cursor: pointer;
}

.scroll-indicator span {
  display: block;
  width: 30px;
  height: 30px;
  border-bottom: 2px solid white;
  border-right: 2px solid white;
  transform: rotate(45deg);
  margin: -10px;
  animation: scrollAnimation 2s infinite;
}

@keyframes fadeInUp {
  from {
    opacity: 0;
    transform: translateY(20px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

@keyframes scrollAnimation {
  0% {
    opacity: 0;
    transform: rotate(45deg) translate(-10px, -10px);
  }
  50% {
    opacity: 1;
  }
  100% {
    opacity: 0;
    transform: rotate(45deg) translate(10px, 10px);
  }
}
</style>