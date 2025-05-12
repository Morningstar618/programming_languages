import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class SQLInsert {

    public static void main(String[] args) {

        String url = "jdbc:mysql://localhost:3306/students";
        String uname = "root";
        String pass = "12341234";
        String query = "select * from names";

        int userid = 6;
        String username = "shiva";
        String insertQuery = "insert into names values (?, ?)";

        try {
            Connection con = DriverManager.getConnection(url, uname, pass);
            PreparedStatement st = con.prepareStatement(insertQuery);

            st.setInt(1, userid);
            st.setString(2, username);
            int i = st.executeUpdate();      // For DML

            System.out.println("row/s effected : " + i);

            st.close();
            con.close();

        } catch (Exception e) {
            System.out.println("Something went wrong");;
        }

    }

}
