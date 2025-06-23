CREATE DATABASE IF NOT EXISTS sesame DEFAULT CHARSET utf8mb4 COLLATE utf8mb4_general_ci;
USE sesame;

CREATE TABLE user (
    id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL UNIQUE COMMENT '用户名',
    password VARCHAR(255) NOT NULL COMMENT '加密后的密码',
    email VARCHAR(100) NOT NULL UNIQUE COMMENT '邮箱',
    role TINYINT DEFAULT 0 COMMENT '0 普通用户，1 管理员',
    create_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '注册时间'
);

CREATE TABLE problem (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100) NOT NULL COMMENT '题目标题',
    description TEXT NOT NULL COMMENT '题目描述',
    input_description TEXT NOT NULL COMMENT '输入描述',
    output_description TEXT NOT NULL COMMENT '输出描述',
    sample_input TEXT COMMENT '样例输入',
    sample_output TEXT COMMENT '样例输出',
    create_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间'
);

CREATE TABLE submission (
    id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT NOT NULL COMMENT '提交用户 ID',
    problem_id INT NOT NULL COMMENT '题目 ID',
    code TEXT NOT NULL COMMENT '用户提交的代码',
    language VARCHAR(20) NOT NULL COMMENT '编程语言',
    result VARCHAR(20) DEFAULT 'Pending' COMMENT '判题结果（Accepted、Wrong Answer 等）',
    submit_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '提交时间',
    FOREIGN KEY (user_id) REFERENCES user(id) ON DELETE CASCADE,
    FOREIGN KEY (problem_id) REFERENCES problem(id) ON DELETE CASCADE
);

CREATE TABLE video (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100) NOT NULL COMMENT '视频标题',
    description TEXT COMMENT '视频描述',
    url VARCHAR(255) NOT NULL COMMENT '视频地址（存储路径或云存储链接）',
    upload_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '上传时间'
);

CREATE TABLE announcement (
    id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(100) NOT NULL COMMENT '公告标题',
    content TEXT NOT NULL COMMENT '公告内容',
    create_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP COMMENT '发布时间'
);
