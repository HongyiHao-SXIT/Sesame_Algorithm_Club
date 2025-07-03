package Project_9;

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
        temp.setA(this.getA()*cn.getA() - this.getB()*cn.getB());
        temp.setB(this.getB()*cn.getA() + this.getA()*cn.getB());
        return temp;
    }
    public Complex divide(Complex cn){
        Complex temp = new Complex();
        temp.setA((this.getA()*cn.getA() + this.getB()*cn.getB())/(cn.getA()*cn.getA()+cn.getB()*cn.getB()));
        temp.setB((this.getB()*cn.getA() - this.getA()*cn.getB())/(cn.getA()*cn.getA() +cn.getB()*cn.getB()));
        return temp;
    }
    public double abs(){
        return Math.sqrt(this.getA() * this.getA() + this.getB() * this.getB());
    }

    public String toString(){
        if(a == 0.0)
            return b + "i";
        if(b == 0.0)
            return a + "i";
        if(b < 0.0)
            return a+ "" + b +"i";
        else
        return a + "+" + b + "i";
    }

    public static void main(String[] args) {
        Complex a = new Complex(3.5,5.5);
        Complex b = new Complex(-1.0,3.0);
        System.out.println("(" + a +")"+"+("+b+")=" + (a.add(b)));
        System.out.println("(" + a +")"+"-("+b+")=" + (a.subtract(b)));
        System.out.println("(" + a +")"+"*("+b+")=" + (a.multiply(b)));
        System.out.println("(" + a +")"+"/("+b+")=" + (a.divide(b)));
        System.out.println("|(" + a +")|" + (a.abs()));
    }


}
