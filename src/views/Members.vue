<template>
  <div class="p-6">
    <h2 class="text-2xl font-semibold mb-4">核心成员</h2>
    <ul class="grid grid-cols-2 gap-4">
      <li v-for="member in members" :key="member.id" class="border p-2 rounded shadow">
        <h3 class="font-bold">{{ member.name }}</h3>
        <p>{{ member.role }}</p>
      </li>
    </ul>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const members = ref([
  { id: 1, name: '张三', role: '社长' },
  { id: 2, name: '李四', role: '技术负责人' }
])
</script>