<template>
    <footer class="site-footer">
      <div class="footer-content">
        <p>© 2025 弘茗智能科技 版权所有</p>
        <div class="social-links">
          <a href="#"><i class="icon-weibo">微博</i></a>
          <a href="#"><i class="icon-github">GitHub</i></a>
          <a href="#"><i class="icon-bilibili">B站</i></a>
        </div>
      </div>
    </footer>
  </template>
  
  <style scoped>
  .site-footer {
    background: var(--dark-bg);
    color: white;
    padding: 30px 5%;
    text-align: center;
    margin-top: auto;
  }
  
  .footer-content {
    max-width: 1200px;
    margin: 0 auto;
  }
  
  .social-links {
    display: flex;
    justify-content: center;
    gap: 20px;
    margin-top: 15px;
  }
  
  .social-links a {
    color: white;
    text-decoration: none;
    transition: color 0.3s;
  }
  
  .social-links a:hover {
    color: var(--secondary-orange);
  }
  </style>