public class Narcissistic_number{
    public static void main(String [] args){
        int num =153;
        int final_num;
        int w1, w2, w3;
        w1 = num /100;
        w2 = num /10 %10;
        w3 = num % 10;
        final_num = w1 * w1 * w1 + w2 * w2 * w2 + w3  *w3 * w3;
        if(final_num == num){
            System.out.println(num + " is Narcissistic number");
        }
        else 
        {
            System.out.println(num + " is not Narcissistic number");
        }

    }
}