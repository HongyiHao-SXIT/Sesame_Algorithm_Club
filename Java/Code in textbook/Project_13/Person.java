package Project_13;

public class Person {
    public String name;
    public int age;
    public Person(){
    }
    public Person(String name, int age){
        this. name = name;
        this.age = age;
    }
    public void sayHello(){
        System.out.println("Hello, My name is " + name);
    }
}
