import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;
import java.util.Scanner;

class Menu extends JFrame
{
    Connection cn;
    Statement st;
    PreparedStatement ps;
    ResultSet rs;
    static Scanner scan = new Scanner(System.in);

    public Menu() throws Exception {
        Class.forName("com.mysql.cj.jdbc.Driver");
        cn = DriverManager.getConnection("jdbc:mysql://localhost:3306/anurodh", "root", "");
        if (cn == null) {
            throw new SQLException("Unable to Connect");
        }
        st = cn.createStatement();
        System.out.println("Database Connected");
    }

    public void SelectAll() throws Exception {
        System.out.println("___Records___");
        rs = st.executeQuery("SELECT * FROM student");
        while (rs.next()) {
            int id = rs.getInt("id");
            String name = rs.getString("name");
            float grade = rs.getFloat("grade");

            System.out.println("ID: " + id + "    Name: " + name + "   Grade: " + grade);
        }
    }

    public void AvgGrade() throws Exception {
        //st = cn.createStatement();
        rs = st.executeQuery("SELECT AVG(grade) FROM student");
        rs.next();
        System.out.println("Average Grade: " + rs.getFloat(1));
    }

    public void Insert() throws Exception {
        String q = "INSERT INTO student VALUES (?, ?, ?)";
        ps = cn.prepareStatement(q);
        int count = 0;
        String prompt;
        do {
            System.out.println("Enter name: ");
            String name = scan.next();

            System.out.println("Enter ID: ");
            int id = scan.nextInt();

            System.out.println("Enter Grade: ");
            float grade = scan.nextFloat();

            ps.setInt(1, id);
            ps.setString(2, name);
            ps.setFloat(3, grade);
            ps.executeUpdate();
            count++;

            System.out.println("Type 'n' or 'N' to exit, any key to continue:  ");
            prompt = scan.next();
        } while (!(prompt.toLowerCase().startsWith("n")));

        System.out.println(count + " records inserted.");
    }

    public void SwingTable() throws Exception {
        showTable();
    }

    JTable table;
    DefaultTableModel model;

    public void showTable() throws Exception {
        setSize(400, 400);
        setTitle("Records");
        model = new DefaultTableModel();
        model.addColumn("ID");
        model.addColumn("Name");
        model.addColumn("Grade");
        fetchRecord();
        table = new JTable(model);
        add(new JScrollPane(table));
        setVisible(true);
    }

    public void fetchRecord() throws Exception
    {
        rs = st.executeQuery("SELECT * FROM student");

        while (rs.next())
        {
            Object[] rowData = {rs.getInt(1), rs.getString(2), rs.getFloat(3)};
            model.addRow(rowData);
        }
    }

    public void exit() throws Exception
    {
        cn.close();
        System.out.println("____CONNECTION__CLOSED____");
        System.exit(0);
    }

    public void showMenu()
    {
        System.out.println("**********MENU**********");
        System.out.println("1. SELECT ALL RECORDS");
        System.out.println("2. Calculate AVG GRADE");
        System.out.println("3. INSERT INTO TABLE");
        System.out.println("4. Swing Table");
        System.out.println("5. EXIT");
        System.out.println("************************");
    }

    public static void main(String[] args) throws Exception
    {
     Menu obj = new Menu();
        obj.showMenu();
        while(true)
        {
            System.out.println("Enter your Choice: ");
            int choice = scan.nextInt();

            switch(choice)
            {
                case 1:
                    obj.SelectAll();
                    break;
                case 2:
                    obj.AvgGrade();
                    break;
                case 3:
                    obj.Insert();
                    break;
                case 4:
                    obj.SwingTable();
                    break;
                case 5:
                    obj.exit();
                    break;
                default:
                    obj.showMenu();
            }
        }
    }
}