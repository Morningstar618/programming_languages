class A extends Thread {
    public void run() {
        for (int i=0; i<=10; i++) {
            System.out.println("Hi");

        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        }
    }


}

class B extends Thread {
    public void run() {
        for (int i=0; i<=10; i++) {
            System.out.println("Hello");

        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        }
    }
}

public class MyThread {

    public static void main(String[] args) {
        
        A obj1 = new A();
        B obj2 = new B();

        System.out.println(obj1.getPriority());

        obj1.start();
        obj2.start();
        
    }
    
}

