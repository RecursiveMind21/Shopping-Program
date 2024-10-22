#ifndef HOME_CPP
#define HOME_CPP

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Product structure
struct Product {
    string name;
    double price;
};

// Global variables
vector<Product> cart;
vector<vector<Product>> orderHistory;

// Function prototypes
void buyProducts();
void viewCart();
void viewOrderHistory();
void settings();

void homepage(){
    while(1){
        cout << "<---------------------------------------------------->" << endl;
        cout << "1. Buy Products" << endl << "2. View Cart" << endl << "3. Order History" << endl << "4. Settings" << endl << "5. Logout" << endl;
        int choice;
        cout << "Enter your selection: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                buyProducts();
                break;
            case 2:
                viewCart();
                break;
            case 3:
                viewOrderHistory();
                break;
            case 4:
                settings();
                break;
            case 5:
                cout << "Logging out..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void buyProducts() {
    vector<Product> availableProducts = {
        {"Laptop", 999.99},
        {"Smartphone", 599.99},
        {"Headphones", 149.99},
        {"Tablet", 299.99}
    };

    cout << "Available Products:" << endl;
    for (int i = 0; i < availableProducts.size(); i++) {
        cout << i+1 << ". " << availableProducts[i].name << " - $" << availableProducts[i].price << endl;
    }

    int productChoice;
    cout << "Enter the product number to add to cart (0 to finish): ";
    cin >> productChoice;

    while (productChoice != 0) {
        if (productChoice > 0 && productChoice <= availableProducts.size()) {
            cart.push_back(availableProducts[productChoice-1]);
            cout << availableProducts[productChoice-1].name << " added to cart." << endl;
        } else {
            cout << "Invalid product number." << endl;
        }
        cout << "Enter the product number to add to cart (0 to finish): ";
        cin >> productChoice;
    }
}

void viewCart() {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }

    cout << "Your Cart:" << endl;
    double total = 0;
    for (const auto& product : cart) {
        cout << product.name << " - $" << product.price << endl;
        total += product.price;
    }
    cout << "Total: $" << total << endl;

    char checkout;
    cout << "Do you want to checkout? (y/n): ";
    cin >> checkout;

    if (checkout == 'y' || checkout == 'Y') {
        orderHistory.push_back(cart);
        cart.clear();
        cout << "Order placed successfully!" << endl;
    }
}

void viewOrderHistory() {
    if (orderHistory.empty()) {
        cout << "No order history available." << endl;
        return;
    }

    cout << "Order History:" << endl;
    for (int i = 0; i < orderHistory.size(); i++) {
        cout << "Order " << i+1 << ":" << endl;
        double total = 0;
        for (const auto& product : orderHistory[i]) {
            cout << product.name << " - $" << product.price << endl;
            total += product.price;
        }
        cout << "Total: $" << total << endl;
        cout << "------------------------ " << endl;
    }
}

void settings() {
    cout << "Settings page (under construction)" << endl;
}

#endif