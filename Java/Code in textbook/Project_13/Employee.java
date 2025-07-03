package Project_13;

public class Employee extends Person {
    public double salary;
    public Employee(){
    }
    public Employee(double salary){
        this.salary = salary;
    }
    public Employee (String name, int age, double salary){
        super(name,age);
        this.salary = salary;
    }
    public double computeSalary( int hour, double rate){
        double salary = hour * rate;
        return this.salary+ salary;
    }
}