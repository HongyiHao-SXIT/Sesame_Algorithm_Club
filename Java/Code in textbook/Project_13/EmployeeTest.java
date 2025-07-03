package Project_13;

public class EmployeeTest {
    public static void main(String[] args){
        var emp = new Employee("Hao",20,5000);
        System.out.println("Name = " + emp.name);
        System.out.println("Age = " + emp.age);
        emp.sayHello();
        System.out.println(emp.computeSalary(10, 50.0));
    }
}
