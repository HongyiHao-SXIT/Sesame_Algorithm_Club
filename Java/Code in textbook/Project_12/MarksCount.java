package Project_12;

public class MarksCount {
    public static void main(String[] args) {
        int[][]marks = {
            {80,75,78,93},
            {67,87,98,65},
            {76,80,76,63},
            {82,70,90,67}
        };
        int [] totals = new int[5];
        for(var row = 0; row < marks.length; row++ ){
            for( var col = 0; col < marks[row].length; col++){
                totals[row] = totals[row] + marks[row][col];
            }
        }

        int max_total = totals[0];
        int index = 0;
        for(var s = 0; s < totals.length; s++){
            if(totals[s]>max_total){
                max_total = totals[s];
                index = s;
            }
            System.out.println("学生：" + s + "总成绩：" + totals[s]);
        }
        System.out.println();
        System.out.println("最高分：" + max_total + "行号=" + index + "\n\n");
        for(var col = 0; col<marks[0].length;col++){
            int max = marks[0][col];
            int r = 0;
            for(var row = 1; row<marks.length;row++){
                if(marks[row][col] > max){
                max = marks[row][col];
                r = row;
                }
            }
        System.out.println("第" + col + "科最高分：" + max + "行号：" + r);
        }
    }
}
