package com.sesame.controller;
 
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
 
@RestController
public class TestControllerRest{
 
    @RequestMapping("/test")
    public String testRest(){
        return "欢迎使用VS Code 和 Spring Boot";
    }
}