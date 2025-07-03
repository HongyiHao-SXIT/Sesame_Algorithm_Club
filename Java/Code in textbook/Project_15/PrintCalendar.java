package Project_15;
import java.util.Scanner;
import java.util.Locale;
import java.time.LocalDate;
import java.time.format.TextStyle;

public class PrintCalendar{
    public static void main(String[] args) {
        var input = new Scanner(System.in);
        System.out.print("请输入一个年份：");
        var year = input.nextInt();
        for(int month = 1 ; month <=12; month++){
            var dates = LocalDate.of(year,month,1);
            String monthName = dates.getMonth().getDisplayName(TextStyle.FULL,Locale.getDefault());
            var daysOfMonth = dates.lengthOfMonth();
            System.out.println(year +"年      " + monthName);
            System.out.println("-------------------------------");
            System.out.printf("%3s%3s%3s%3s%3s%3s%3s%n", "一","二","三","四","五","六","日");
            var dayOfWeek = dates.getDayOfWeek().getValue();
            for(var i = 2; i <= daysOfMonth; i++){
                System.out.printf("%4d", i);
                if((dayOfWeek + i-1)%7 == 0)
                    System.out.println();
            }
            System.out.printf("%n%n");


        }
    }
}