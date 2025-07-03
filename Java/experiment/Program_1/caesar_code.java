
import java.util.Scanner;
 
public class caesar_code {
    public static void main(String[] args) {
        System.out.print("请输入密文：");
        Scanner input = new Scanner(System.in);
        String string=input.nextLine();
        System.out.print("请输入秘钥：");
        int key=input.nextInt();
        key=key%26;
        System.out.println("-------------------------");
        System.out.print("明文是：");
        char ch[]=string.toCharArray();
        for (int i = 0; i < ch.length; i++) {
            if (ch[i]==' '){
                System.out.print(ch[i]);
            }   
            if (ch[i]>='a'&&ch[i]<='z') {
                ch[i] = (char)(((ch[i]-'a')+key)%26+'a');
            }
            else if(ch[i]>='A'&&ch[i]<='Z'){
                ch[i] = (char)(((ch[i]-'A')+key)%26+'A');
            }
            System.out.print(ch[i]);
        }
    }
}