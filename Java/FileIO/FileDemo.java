package FileIO;
import java.io.*;
class FileDemo {
    public static void main(String[] args) {
        try{
            var succcess = false;
            var file = new File("Hello.txt");
            System.out.println(file.exists());
            succcess = file.createNewFile();
            System.out.println(succcess);
            System.out.println(file.exists());
        }catch(IOException e) {
            System.out.println(e.toString());
        }
    }
    
}