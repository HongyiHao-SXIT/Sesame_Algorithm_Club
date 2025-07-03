package Project_10; 

public class ArrayDemo{
    public static void main(String[] args){
        var marks = new double[5];
        marks[0] = 79;
        marks[1] = 84.5;
        marks[2] = 63;
        marks[3] = 90;
        marks[4] = 98;
        System.out.println(marks[2]);
        System.out.println(marks.length);

        for(var i = 0; i < marks.length; i++){
            System.out.print(marks[i] + " ");
        }
    }
}