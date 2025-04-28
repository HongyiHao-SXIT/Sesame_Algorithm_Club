<template>
  <section class="team-section">
    <h2>{{ t('team.title') }}</h2>
    <div class="specialties-chart">
      <div class="chart-container">
        <canvas ref="chartCanvas"></canvas>
      </div>
    </div>
    <div class="team-members">
      <div 
        v-for="(member, index) in teamMembers" 
        :key="index" 
        class="member-card"
        @click="toggleMemberView(index)"
      >
        <div class="member-avatar" :class="{ 'show-fursona': showFursona[index] }">
          <img :src="member.avatar" class="real-avatar" :alt="member.name">
          <img :src="member.fursona" class="fursona-avatar" :alt="member.name + '兽设'">
        </div>
        <h3>{{ member.name }}</h3>
        <p class="major">{{ member.major }}</p>
        <p class="bio">{{ member.bio }}</p>
        <div class="social-links">
          <a v-for="(link, platform) in member.social" :key="platform" :href="link" target="_blank">
            <i :class="`icon-${platform}`"></i>
          </a>
        </div>
      </div>
    </div>
  </section>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { useI18n } from 'vue-i18n'
import Chart from 'chart.js/auto'

const { t } = useI18n()
const chartCanvas = ref(null)
const showFursona = ref([])

const teamMembers = [
  {
    name: '张工程师',
    major: '机械电子工程',
    bio: '专注于机器人运动控制与机构设计',
    avatar: require('@/assets/images/member1.jpg'),
    fursona: require('@/assets/images/fursona1.png'),
    social: {
      github: 'https://github.com',
      bilibili: 'https://bilibili.com'
    }
  },
  // 更多成员...
]

// 初始化时所有成员显示真实头像
showFursona.value = new Array(teamMembers.length).fill(false)

const toggleMemberView = (index) => {
  showFursona.value[index] = !showFursona.value[index]
}

onMounted(() => {
  // 专业分布图表
  const specialtiesData = {
    labels: ['机械工程', '机械电子', '计算机科学', '人工智能', '微电子', '应用统计'],
    datasets: [{
      data: [3, 2, 4, 3, 2, 1],
      backgroundColor: [
        '#FF6384',
        '#36A2EB',
        '#FFCE56',
        '#4BC0C0',
        '#9966FF',
        '#FF9F40'
      ]
    }]
  }

  new Chart(chartCanvas.value, {
    type: 'pie',
    data: specialtiesData,
    options: {
      responsive: true,
      plugins: {
        legend: {
          position: 'right'
        }
      }
    }
  })
})
</script>

<style scoped>
.team-section {
  background: white;
}

.specialties-chart {
  max-width: 600px;
  margin: 0 auto 50px;
}

.chart-container {
  position: relative;
  height: 300px;
}

.team-members {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
  gap: 30px;
  margin-top: 40px;
}

.member-card {
  background: #f9f9f9;
  border-radius: 10px;
  padding: 25px;
  text-align: center;
  transition: all 0.3s;
  cursor: pointer;
}

.member-card:hover {
  transform: translateY(-5px);
  box-shadow: 0 10px 20px rgba(0,0,0,0.1);
}

.member-avatar {
  width: 150px;
  height: 150px;
  border-radius: 50%;
  margin: 0 auto 20px;
  position: relative;
  overflow: hidden;
  border: 3px solid var(--primary-blue);
}

.real-avatar, .fursona-avatar {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: opacity 0.5s;
}

.real-avatar {
  opacity: 1;
  z-index: 1;
}

.fursona-avatar {
  opacity: 0;
  z-index: 2;
}

.show-fursona .real-avatar {
  opacity: 0;
}

.show-fursona .fursona-avatar {
  opacity: 1;
}

.member-card h3 {
  font-size: 1.5rem;
  margin-bottom: 5px;
  color: var(--primary-blue);
}

.major {
  font-weight: 500;
  color: var(--secondary-orange);
  margin-bottom: 15px;
}

.bio {
  margin-bottom: 15px;
  font-size: 0.9rem;
}

.social-links {
  display: flex;
  justify-content: center;
  gap: 15px;
}

.social-links a {
  color: var(--dark-bg);
  font-size: 1.2rem;
  transition: color 0.3s;
}

.social-links a:hover {
  color: var(--primary-blue);
}
</style>