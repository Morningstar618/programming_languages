class A {
    public void show() {
        System.out.println("in A Show");
    }
}

class B extends A {
    public void show() {
        System.out.println("in B show");
    }
}

class Main {
    public static void main(String a[]) {

        A obj = (A) new B();
        obj.show();

        
        

    }
}