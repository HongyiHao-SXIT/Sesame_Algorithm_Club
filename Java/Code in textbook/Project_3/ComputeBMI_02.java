package Project_3;
import java.util.Scanner;

public class ComputeBMI_02 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        System.out.println("欢迎使用BMI计算器");
        System.out.print("请输入您的体重（kg）：");
        double weight = input.nextDouble();

        System.out.print("请输入您的身高（m）：");
        double height = input.nextDouble();

        double bmi = calculateBMI(weight, height);
        System.out.println("您的BMI指数为：" + bmi);
        System.out.println("BMI指数结果解读：");
        interpretBMI(bmi);
    }
public static double calculateBMI(double weight, double height) {
        return weight / (height * height);
    }
public static void interpretBMI(double bmi) {
        if (bmi < 18.5) {
            System.out.println("您的体重过轻");
        } else if (bmi < 24) {
            System.out.println("您的体重正常");
        } else if (bmi < 28) {
            System.out.println("您的体重超重");
        } else {
            System.out.println("您的体重肥胖");
        }
    }

}
