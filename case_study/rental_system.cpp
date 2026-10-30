
import java.util.ArrayList;
import java.util.Scanner;

// Vehicle class
class Vehicle {
    private int vehicleId;
    private String brand;
    private String model;
    private double rentPerDay;
    private boolean available;

    // Constructor
    public Vehicle(int vehicleId, String brand, String model, double rentPerDay) {
        this.vehicleId = vehicleId;
        this.brand = brand;
        this.model = model;
        this.rentPerDay = rentPerDay;
        this.available = true;
    }

    // Getter methods
    public int getVehicleId() {
        return vehicleId;
    }

    public double getRentPerDay() {
        return rentPerDay;
    }

    public boolean isAvailable() {
        return available;
    }

    // Rent vehicle
    public void rentVehicle() {
        available = false;
    }

    // Return vehicle
    public void returnVehicle() {
        available = true;
    }

    // Display vehicle details
    public void displayVehicle() {
        System.out.println(
            "ID: " + vehicleId +
            " | Brand: " + brand +
            " | Model: " + model +
            " | Rent/Day: Rs. " + rentPerDay +
            " | Status: " + (available ? "Available" : "Rented")
        );
    }
}

// Customer class
class Customer {
    private int customerId;
    private String name;

    // Constructor
    public Customer(int customerId, String name) {
        this.customerId = customerId;
        this.name = name;
    }

    // Getter methods
    public int getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }
}

// RentalSystem class
class RentalSystem {
    private ArrayList<Vehicle> vehicles = new ArrayList<>();
    private ArrayList<Customer> customers = new ArrayList<>();

    // Add vehicle
    public void addVehicle(Vehicle vehicle) {
        vehicles.add(vehicle);
    }

    // Add customer
    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

    // Display all vehicles
    public void displayVehicles() {
        System.out.println("\n----- VEHICLE LIST -----");

        if (vehicles.isEmpty()) {
            System.out.println("No vehicles registered.");
            return;
        }

        for (Vehicle vehicle : vehicles) {
            vehicle.displayVehicle();
        }
    }

    // Find vehicle by ID
    private Vehicle findVehicle(int vehicleId) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getVehicleId() == vehicleId) {
                return vehicle;
            }
        }

        return null;
    }

    // Rent vehicle
    public void rentVehicle(int vehicleId, int days) {
        if (days <= 0) {
            System.out.println("Rental days must be greater than zero.");
            return;
        }

        Vehicle vehicle = findVehicle(vehicleId);

        if (vehicle == null) {
            System.out.println("Vehicle not found.");
            return;
        }

        if (!vehicle.isAvailable()) {
            System.out.println("Vehicle is already rented.");
            return;
        }

        double totalCost = vehicle.getRentPerDay() * days;

        vehicle.rentVehicle();

        System.out.println("\nVehicle rented successfully!");
        System.out.println("Vehicle ID: " + vehicleId);
        System.out.println("Rental Days: " + days);
        System.out.printf("Total Cost: Rs. %.2f%n", totalCost);
    }

    // Return vehicle
    public void returnVehicle(int vehicleId) {
        Vehicle vehicle = findVehicle(vehicleId);

        if (vehicle == null) {
            System.out.println("Vehicle not found.");
            return;
        }

        if (vehicle.isAvailable()) {
            System.out.println("Vehicle is already available.");
            return;
        }

        vehicle.returnVehicle();

        System.out.println("Vehicle returned successfully!");
    }
}

// Main class
public class VehicleRentalSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        RentalSystem system = new RentalSystem();

        // Create vehicle objects
        Vehicle v1 = new Vehicle(101, "Toyota", "Innova", 2500);
        Vehicle v2 = new Vehicle(102, "Honda", "City", 1800);
        Vehicle v3 = new Vehicle(103, "Mahindra", "Thar", 3000);

        // Create customer objects
        Customer c1 = new Customer(1, "Rahul");
        Customer c2 = new Customer(2, "Amit");

        // Add vehicles to the system
        system.addVehicle(v1);
        system.addVehicle(v2);
        system.addVehicle(v3);

        // Add customers to the system
        system.addCustomer(c1);
        system.addCustomer(c2);

        int choice;

        do {
            System.out.println("\n===== VEHICLE RENTAL SYSTEM =====");
            System.out.println("1. Display Vehicles");
            System.out.println("2. Rent Vehicle");
            System.out.println("3. Return Vehicle");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            if (!sc.hasNextInt()) {
                System.out.println("Invalid input. Please enter a number.");
                sc.next();
                continue;
            }

            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    system.displayVehicles();
                    break;

                case 2:
                    System.out.print("Enter Vehicle ID: ");

                    if (!sc.hasNextInt()) {
                        System.out.println("Invalid vehicle ID.");
                        sc.next();
                        break;
                    }

                    int rentId = sc.nextInt();

                    System.out.print("Enter number of days: ");

                    if (!sc.hasNextInt()) {
                        System.out.println("Invalid number of days.");
                        sc.next();
                        break;
                    }

                    int days = sc.nextInt();
                    system.rentVehicle(rentId, days);
                    break;

                case 3:
                    System.out.print("Enter Vehicle ID: ");

                    if (!sc.hasNextInt()) {
                        System.out.println("Invalid vehicle ID.");
                        sc.next();
                        break;
                    }

                    int returnId = sc.nextInt();
                    system.returnVehicle(returnId);
                    break;

                case 4:
                    System.out.println("Thank you for using Vehicle Rental System!");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
            }

        } while (choice != 4);

        sc.close();
    }
}