package Project_8.Demo.src;
import com.boda.MyDate;
public class MyDateDemo {
    public static void main(String[] args) {
    MyDate today = new MyDate();
    System.out.println(today.tostring());
    MyDate birthday = new MyDate(2002,10,26);
    System.out.println(birthday.getyear + "年" + (birthday.isLeapYear()?"是闰年":"不是闰年"));
    System.out.println("你已出生" + today.between(birthday) + "天。");
    }
}
