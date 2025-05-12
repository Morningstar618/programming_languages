import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;


public class MyCollection {
    
    public static void main(String[] args) {
        
        Set<Integer> nums = new TreeSet<Integer>();
        nums.add(6);
        nums.add(2);
        nums.add(8);
        nums.add(5);

        // System.out.println(nums.get(2));             //List Method
        // System.out.println(nums.indexOf(5));         //List Method


        System.out.println("-------------------------");
        for (int n: nums) {
            System.out.println(n);
        }

        System.out.println(nums);

        System.out.println("----------------------------");

        Iterator<Integer> values = nums.iterator();

        while (values.hasNext()) {
            System.out.println(values.next());
        }

    }

}
