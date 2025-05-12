// We are fetching data in this code

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class Demo {

    public static void main(String[] args) {

        String url = "jdbc:mysql://localhost:3306/students";
        String uname = "root";
        String pass = "12341234";
        String query = "select * from names";
        String insertQuery = "insert into names values (4, 'mohini')";

        try {
//            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection(url, uname, pass);
            Statement st = con.createStatement();
//            ResultSet rs = st.executeQuery(query);      // For DQL
            int i = st.executeUpdate(insertQuery);      // For DML

//            String userData = "";
//
//            while (rs.next()) {
//                userData = rs.getInt(1) + " : " + rs.getString(2);
//                System.out.println(userData);
//            }

            st.close();
            con.close();

        } catch (Exception e) {
            System.out.println("Something went wrong");;
        }

    }

}
