<template>
  <section class="products-section">
    <h2>{{ t('products.title') }}</h2>
    <div class="product-grid">
      <div 
        v-for="(product, index) in products" 
        :key="index" 
        class="product-card"
        @mouseenter="hoveredCard = index"
        @mouseleave="hoveredCard = null"
      >
        <div class="product-image">
          <img :src="product.image" :alt="product.name">
        </div>
        <h3>{{ product.name }}</h3>
        <p>{{ product.description }}</p>
        <div class="tech-stack">
          <span v-for="(tech, i) in product.techStack" :key="i">{{ tech }}</span>
        </div>
        <button class="detail-button" :class="{ 'hovered': hoveredCard === index }">
          {{ t('products.details') }}
        </button>
      </div>
    </div>
  </section>
</template>

<script setup>
import { ref } from 'vue'
import { useI18n } from 'vue-i18n'

const { t } = useI18n()
const hoveredCard = ref(null)

const products = [
  {
    name: '成熟项目',
    description: '已投入市场的创新解决方案',
    image: require('@/assets/images/product1.jpg'),
    techStack: ['机械工程', '人工智能', '计算机视觉']
  },
  {
    name: '开发中项目',
    description: '即将推出的前沿技术产品',
    image: require('@/assets/images/product2.jpg'),
    techStack: ['微电子', '应用统计', '机械电子']
  }
]
</script>

<style scoped>
.products-section {
  background-color: var(--light-bg);
}

.product-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 30px;
  margin-top: 40px;
}

.product-card {
  background: white;
  border-radius: 10px;
  box-shadow: 0 5px 15px rgba(0,0,0,0.1);
  padding: 30px;
  transition: all 0.3s ease;
  display: flex;
  flex-direction: column;
  height: 100%;
}

.product-card:hover {
  transform: translateY(-10px);
  box-shadow: 0 15px 30px rgba(0,0,0,0.15);
}

.product-image {
  width: 100%;
  height: 200px;
  overflow: hidden;
  border-radius: 8px;
  margin-bottom: 20px;
}

.product-image img {
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: transform 0.5s;
}

.product-card:hover .product-image img {
  transform: scale(1.05);
}

.product-card h3 {
  font-size: 1.8rem;
  margin-bottom: 10px;
  color: var(--primary-blue);
}

.product-card p {
  margin-bottom: 20px;
  flex-grow: 1;
}

.tech-stack {
  display: flex;
  flex-wrap: wrap;
  gap: 8px;
  margin-bottom: 20px;
}

.tech-stack span {
  background: #f0f0f0;
  padding: 5px 10px;
  border-radius: 20px;
  font-size: 0.8rem;
}

.detail-button {
  background: var(--primary-blue);
  color: white;
  border: none;
  padding: 12px 20px;
  border-radius: 5px;
  cursor: pointer;
  transition: all 0.3s;
  align-self: flex-start;
}

.detail-button.hovered {
  background: var(--secondary-orange);
  transform: translateY(-3px);
}
</style>