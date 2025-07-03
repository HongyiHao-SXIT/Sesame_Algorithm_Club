package Project_11;

public class BubbleSort {
    public static void main(String[] args) {
        int []a = {75,53,32,12,46,199,17,54};
        System.out.print("初始元素： ");
        for(var n:a){
            System.out.print("n" + n);
        }
        System.out.println();
        for(var i = 0; i < a.length - 1; i ++){
            for(var j = 0; j < a.length - i - 1; i++){
                if(a[j] > a[j+1]){
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
            System.out.println("第" + (i + 1) + "趟结果： ");
            for(var n:a){
                System.out.print(" "  +n);
            }
            System.out.println();
        }

    }
}
