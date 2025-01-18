import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

class User {
    private final String name;
    private final String email;

    public User(String name, String email) {
        this.name = name;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public void display() {
        System.out.println("Name: " + name + ", Email: " + email);
    }
}

class UserManager {
    private final List<User> users;

    public UserManager() {
        this.users = new ArrayList<>();
    }

    public void addUser(String name, String email) {
        users.add(new User(name, email));
    }

    public void displayAllUsers() {
        if (users.isEmpty()) {
            System.out.println("No users available.");
            return;
        }

        for (User user : users) {
            user.display();
        }
    }

    public List<User> getUsers() {
        return users;
    }
}

class UserSaver {
    public void saveUsersToFile(List<User> users, String filename) {
        System.out.println("Saving users to file: " + filename);
        for (User user : users) {
            System.out.println("Saving: " + user.getName() + ", " + user.getEmail());
        }
    }
}

abstract class Discount {
    protected BigDecimal discountedPrice = new BigDecimal(0);

    public abstract BigDecimal calculateDiscount(BigDecimal basePrice);

    public void display() {
        System.out.println("Discounted price: " + discountedPrice);
    }
}

final class RegularDiscount extends Discount {
    private BigDecimal basePrice;

    public RegularDiscount(double basePrice) {
        this.basePrice = BigDecimal.valueOf(basePrice);
        calculateDiscount(this.basePrice);
    }

    @Override
    public BigDecimal calculateDiscount(BigDecimal basePrice) {
        if (basePrice.intValue() != 0) {
            this.basePrice = basePrice;
        }
        discountedPrice = this.basePrice.multiply(BigDecimal.valueOf(0.9));
        return discountedPrice;
    }
}

final class SeasonalDiscount extends Discount {
    private BigDecimal basePrice;

    public SeasonalDiscount(double basePrice) {
        this.basePrice = BigDecimal.valueOf(basePrice);
        calculateDiscount(this.basePrice);
    }

    @Override
    public BigDecimal calculateDiscount(BigDecimal basePrice) {
        if (basePrice.intValue() != 0) {
            this.basePrice = basePrice;
        }
        discountedPrice = this.basePrice.multiply(BigDecimal.valueOf(0.8));
        return discountedPrice;
    }
}

interface Shape {
    double getArea(); 
}


class Rectangle implements Shape {
    protected double width;
    protected double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public void setWidth(double w) {
        this.width = w;
    }

    public void setHeight(double h) {
        this.height = h;
    }

    @Override
    public double getArea() {
        return width * height;
    }
}

class Square implements Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    public void setSide(double s) {
        this.side = s;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}

interface Printer {
    void print();
}


interface Scanner {
    void scan();
}

class MultiFunctionMachine implements Printer, Scanner {
    @Override
    public void print() {
        System.out.println("Printing document...");
    }

    @Override
    public void scan() {
        System.out.println("Scanning document...");
    }
}

interface MessageService {
    void sendMessage(String message);
}

class EmailService implements MessageService {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending Email: " + message);
    }
}

class Notification {
    private final MessageService messageService;

    public Notification(MessageService service) {
        this.messageService = service;
    }

    public void notify(String message) {
        messageService.sendMessage(message);
    }
}

public class lab7 {
    public static void main(String[] args) {
        UserManager userManager = new UserManager();

        userManager.addUser("Alice", "alice@example.com");
        userManager.addUser("Bob", "bob@example.com");

        System.out.println("All users:");
        userManager.displayAllUsers();

        UserSaver userSaver = new UserSaver();
        userSaver.saveUsersToFile(userManager.getUsers(), "users.txt");

        System.out.println("");

        RegularDiscount regular = new RegularDiscount(12);
        regular.display();

        SeasonalDiscount seasonal = new SeasonalDiscount(12);
        seasonal.display();

        System.out.println("");

        Rectangle rect = new Rectangle(5, 3);
        Square sq = new Square(4);

        Shape shape1 = rect;
        Shape shape2 = sq;

        System.out.println("Area of Rectangle: " + shape1.getArea());
        System.out.println("Area of Square: " + shape2.getArea());

        System.out.println("");

        MultiFunctionMachine mfm = new MultiFunctionMachine();
        mfm.print();
        mfm.scan();

        System.out.println("");
        
        EmailService emailService = new EmailService();
        Notification notification = new Notification(emailService);

        notification.notify("Witaj w SOLID!");
    }
}