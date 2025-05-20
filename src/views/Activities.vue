<template>
  <div class="p-6">
    <h2 class="text-2xl font-semibold mb-4">近期活动</h2>
    <ul>
      <li v-for="activity in activities" :key="activity.id" class="mb-2">
        <strong>{{ activity.title }}</strong> — {{ activity.date }}
      </li>
    </ul>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const activities = ref([
  { id: 1, title: '春季算法比赛', date: '2025-03-28' },
  { id: 2, title: '算法入门讲座', date: '2025-04-12' }
])
</script>