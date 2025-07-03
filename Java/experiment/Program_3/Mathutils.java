package Program_3;
import java.util.Scanner;
public class Mathutils{
    public static boolean isPrime(int n){
        for(var divisor = 2; divisor * divisor <= n; divisor++){
            if(n % divisor ==0)
            return false;
        }
        return true;
    }
    public static boolean isPalindrome( int n){
        var s = String.valueOf(n);
        var low = 0;
        var heigh = s.length() - 1;
        while(low < heigh){
            if(s.charAt(low)!=s.charAt(heigh)){
                return false;
            }
            low++;
            heigh --;
        }
        return true;
    }
    public static void main(String[] args){
        var count = 0;
        var n = 2;
        for(var n = 2; n<= 1000;n++){
            if(isPrime(n) && isPalindrome(n)){
                count ++;
                if(count %10 ==0){
                    System.out.printf("%5s%n",n);
                }else{
                    System.out.printf("%5s",n);
                }
            }
        }
    }
}