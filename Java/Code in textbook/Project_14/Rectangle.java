package Project_14;
public class Rectangle extends Shape {
    private double length, width;      
    public Rectangle(){
        this(0.0,0.0);
    }
    public Rectangle(double length,double width){
        super("矩形");
        this.length = length;
        this.width = width;
    }
    public void setLenght(double length){
        this.length = length;
    }
    @Override
    public double getlenght(){
        return length;
    }
    
    @Override
    public double getPerimeter(){
        return 2 * (length + width);
    }
    @Override
    public double getArea(){
        return length * width;
    }
    @Override
    public String toString(){
        return "[矩形] length and width = " + length + width;
    }
    
}
