
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle {
private:
    int vehicleId;
    string brand;
    string model;
    double rentPerDay;
    bool available;

public:
    Vehicle(int vehicleId, string brand, string model, double rentPerDay) {
        this->vehicleId = vehicleId;
        this->brand = brand;
        this->model = model;
        this->rentPerDay = rentPerDay;
        this->available = true;
    }

    int getVehicleId() {
        return vehicleId;
    }

    double getRentPerDay() {
        return rentPerDay;
    }

    bool isAvailable() {
        return available;
    }

    void rentVehicle() {
        available = false;
    }

    void returnVehicle() {
        available = true;
    }

    void displayVehicle() {
        cout << "ID: " << vehicleId
             << " | Brand: " << brand
             << " | Model: " << model
             << " | Rent/Day: Rs. " << rentPerDay
             << " | Status: " << (available ? "Available" : "Rented")
             << endl;
    }
};

class Customer {
private:
    int customerId;
    string name;

public:
    Customer(int customerId, string name) {
        this->customerId = customerId;
        this->name = name;
    }

    int getCustomerId() {
        return customerId;
    }

    string getName() {
        return name;
    }
};

class RentalSystem {
private:
    vector<Vehicle> vehicles;
    vector<Customer> customers;

    Vehicle* findVehicle(int vehicleId) {
        for (auto &vehicle : vehicles) {
            if (vehicle.getVehicleId() == vehicleId) {
                return &vehicle;
            }
        }
        return nullptr;
    }

public:
    void addVehicle(Vehicle vehicle) {
        vehicles.push_back(vehicle);
    }

    void addCustomer(Customer customer) {
        customers.push_back(customer);
    }

    void displayVehicles() {
        cout << "\n----- VEHICLE LIST -----" << endl;

        if (vehicles.empty()) {
            cout << "No vehicles registered." << endl;
            return;
        }

        for (auto &vehicle : vehicles) {
            vehicle.displayVehicle();
        }
    }

    void rentVehicle(int vehicleId, int days) {
        if (days <= 0) {
            cout << "Rental days must be greater than zero." << endl;
            return;
        }

        Vehicle* vehicle = findVehicle(vehicleId);

        if (vehicle == nullptr) {
            cout << "Vehicle not found." << endl;
            return;
        }

        if (!vehicle->isAvailable()) {
            cout << "Vehicle is already rented." << endl;
            return;
        }

        double totalCost = vehicle->getRentPerDay() * days;

        vehicle->rentVehicle();

        cout << "\nVehicle rented successfully!" << endl;
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Rental Days: " << days << endl;
        cout << fixed << setprecision(2);
        cout << "Total Cost: Rs. " << totalCost << endl;
    }

    void returnVehicle(int vehicleId) {
        Vehicle* vehicle = findVehicle(vehicleId);

        if (vehicle == nullptr) {
            cout << "Vehicle not found." << endl;
            return;
        }

        if (vehicle->isAvailable()) {
            cout << "Vehicle is already available." << endl;
            return;
        }

        vehicle->returnVehicle();

        cout << "Vehicle returned successfully!" << endl;
    }
};

int main() {
    RentalSystem system;

    Vehicle v1(101, "Toyota", "Innova", 2500);
    Vehicle v2(102, "Honda", "City", 1800);
    Vehicle v3(103, "Mahindra", "Thar", 3000);

    Customer c1(1, "Rahul");
    Customer c2(2, "Amit");

    system.addVehicle(v1);
    system.addVehicle(v2);
    system.addVehicle(v3);

    system.addCustomer(c1);
    system.addCustomer(c2);

    int choice;

    do {
        cout << "\n===== VEHICLE RENTAL SYSTEM =====" << endl;
        cout << "1. Display Vehicles" << endl;
        cout << "2. Rent Vehicle" << endl;
        cout << "3. Return Vehicle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                system.displayVehicles();
                break;

            case 2: {
                int rentId, days;

                cout << "Enter Vehicle ID: ";
                if (!(cin >> rentId)) {
                    cout << "Invalid vehicle ID." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                cout << "Enter number of days: ";
                if (!(cin >> days)) {
                    cout << "Invalid number of days." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                system.rentVehicle(rentId, days);
                break;
            }

            case 3: {
                int returnId;

                cout << "Enter Vehicle ID: ";
                if (!(cin >> returnId)) {
                    cout << "Invalid vehicle ID." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }

                system.returnVehicle(returnId);
                break;
            }

            case 4:
                cout << "Thank you for using Vehicle Rental System!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
