
public class Complex {
    private double a;
    private double b;
    public Complex(){

    }
    public Complex(double a){
        this.a = a;
    }
    public Complex(double a,double b){
        this.a = a;
        this.b = b;
    }
    public double getA(){
        return a;
    }
    public void setA(double a){
        this.a = a;
    }
    public double getB(){
        return b;
    }
    public void setB(double b){
        this.b = b;
    }
    public Complex add(Complex cn){
        Complex temp = new Complex();
        temp.setA(this.getA() + cn.getA());
        temp.setB(this.getA() + cn.getB());
        return temp;
    }
    public Complex subtract (Complex cn){
        Complex temp = new Complex();
        temp.setA(this.getA() - cn.getA());
        temp.setB(this.getB() - cn.getB());
        return temp;
    }
    public Complex multiply(Complex cn){
        Complex temp = new Complex();
        temp.setA(this.getA() * cn.getA() - this.getB() * cn.getB());
        temp.setB(this.getB() * cn.getA() + this.getA() * cn.getB());
        return temp;
    }
    public Complex divide(Complex cn){
        Complex temp = new Complex();
        temp.setA(
            (this.getA() * cn.getA() + this.getB() * cn.getB())/(cn.getA() * cn.getA()) + cn.getB() * cn.getB()));
    }
    temp.setB(
        (this.getB() * cn.getA() - this.getA() * cn.getB())/(cn.getA() * cn.getA() + cn.getB() * cn.getB());
}
}
