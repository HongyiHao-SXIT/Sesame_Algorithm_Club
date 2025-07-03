package Project_14;
public class PolymorphismDemo {
    public static double sumArea(Shape[] shapes){
        var sumArea = 0.0;
        for(var shape: shapes){
            System.out.println(shape.getArea());
            sumArea = sumArea + shape.getArea();
        }
        return sumArea;
    } 

    public static void main(String [] args){
        var d = 0.0;
        var shapes = new Shape[5];
        for(var i = 0; i< shapes.length; i++){
            d = Math.random();
            if(d>0.5){
                shapes[i] = new Circle(1);
            }
            else {
                shapes[i] = new Rectangle(1,2);
            }
        }
        var sumArea = sumArea(shapes);
        System.out.printf("形状的面积是 = %.2f",sumArea);
    }
}

