import java.util.HashMap;
import java.util.Map;

public class MyMap {
    
    public static void main(String[] args) {
        
        Map<String, Integer> students = new HashMap<>();

        students.put("Ayush", 66);
        students.put("Abhishek", 46);
        students.put("Navin", 50);
        students.put("Sanjay", 87);
        students.put("Sanjay", 77);


        System.out.println(students);
        System.out.println(students.get("Ayush"));

        for (String key: students.keySet()) {
            System.out.println(key + " : " + students.get(key));
        }

    }

}
