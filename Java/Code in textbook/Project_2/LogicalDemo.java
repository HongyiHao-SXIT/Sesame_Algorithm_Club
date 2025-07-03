package Project_2;
public class LogicalDemo {
    public static void main(String[] args) {
        int a = 1,b = 2, c = 3;
        boolean u = false;
        u = (a>= --b||b++ < c--)&&b==c;
        System.out.println("u = " + u);
        b= 2;
        u = (a >= --b| b++<c--)&b==c;
        System.out.println("u = " + u);
    }
}
