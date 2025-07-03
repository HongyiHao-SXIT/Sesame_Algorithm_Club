package Project_7;
public class Account{
    public int id;
    public String name;
    public double balance;

    public Account(){}

    public void deposit(double amount){
        balance = balance + amount;
        System.out.println("目前账户余额是： " + balance);
    }
    public void withdraw(double amount){
        balance = balance - amount;
        System.out.println("目前账户余额是： " + balance);
    }
}