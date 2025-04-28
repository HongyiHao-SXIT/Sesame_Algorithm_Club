export default {
    build: {
      rollupOptions: {
        output: {
          manualChunks: {
            vendor: ['vue', 'vue-router', 'vue-i18n'],
            chartjs: ['chart.js']
          }
        }
      }
    }
  }