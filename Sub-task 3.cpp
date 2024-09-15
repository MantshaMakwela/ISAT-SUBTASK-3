#include <iostream>
using namespace std;

const int SIZE = 5; // Adjust this based on the number of orders

int OrderID[SIZE] = { 101, 102, 103, 104, 105 };
string CustomerName[SIZE] = { "Thabo", "Lerato", "Nomvula", "Sipho", "Nomsa" };
int NumberOfMagwinyas[SIZE] = { 3, 5, 2, 4, 1 };
float TotalAmount[SIZE] = { 15.50, 30.00, 10.00, 22.00, 5.00 };

void displayOrders() {
    cout << "OrderID\tCustomerName\tNumber of Magwinyas\tTotalAmount" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << OrderID[i] << "\t" << CustomerName[i] << "\t\t"
            << NumberOfMagwinyas[i] << "\t\t" << TotalAmount[i] << endl;
    }
}

float calculateTotalAmount(int quantity) {
    const float pricePerMagwinya = 5.00;
    return quantity * pricePerMagwinya;
}

void addOrder(int id, string name, int quantity) {
    for (int i = 0; i < SIZE; i++) {
        if (OrderID[i] == 0) { // Assuming 0 means the slot is available
            OrderID[i] = id;
            CustomerName[i] = name;
            NumberOfMagwinyas[i] = quantity;
            TotalAmount[i] = calculateTotalAmount(quantity);
            break;
        }
    }
}

void modifyOrder(int id, string newName, int newQuantity) {
    for (int i = 0; i < SIZE; i++) {
        if (OrderID[i] == id) {
            CustomerName[i] = newName;
            NumberOfMagwinyas[i] = newQuantity;
            TotalAmount[i] = calculateTotalAmount(newQuantity);
            break;
        }
    }
}

void deleteOrder(int id) {
    for (int i = 0; i < SIZE; i++) {
        if (OrderID[i] == id) {
            OrderID[i] = 0;
            CustomerName[i] = "";
            NumberOfMagwinyas[i] = 0;
            TotalAmount[i] = 0.0;
            break;
        }
    }
}

void menu() {
    int choice;
    do {
        cout << "1. Display Orders\n2. Add Order\n3. Modify Order\n4. Delete Order\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayOrders();
            break;
        case 2: {
            int id, quantity;
            string name;
            cout << "Enter OrderID: ";
            cin >> id;
            cout << "Enter Customer Name: ";
            cin >> name;
            cout << "Enter Number of Magwinyas: ";
            cin >> quantity;
            addOrder(id, name, quantity);
            break;
        }
        case 3: {
            int id, quantity;
            string name;
            cout << "Enter OrderID to modify: ";
            cin >> id;
            cout << "Enter new Customer Name: ";
            cin >> name;
            cout << "Enter new Number of Magwinyas: ";
            cin >> quantity;
            modifyOrder(id, name, quantity);
            break;
        }
        case 4: {
            int id;
            cout << "Enter OrderID to delete: ";
            cin >> id;
            deleteOrder(id);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}
