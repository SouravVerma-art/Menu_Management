#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Restaurant {
    string ItemID, ItemName, Price, Category;
    string sID, sItem;
    fstream file;
    
public:
    void addItem();
    void removeItem();
    void vegMenu();
    void nonVegMenu();
    void drinks();
    void snacks();
    void desserts();
    void partySpecial();
} obj;

int main() {
    int choice;

    do {
        cout << "\n===== Restaurant Menu Management System =====";
        cout << "\n1 - Add a New Item/Dish";
        cout << "\n2 - Remove an Item";
        cout << "\n3 - View Veg Menu";
        cout << "\n4 - View Non-Veg Menu";
        cout << "\n5 - View Drinks";
        cout << "\n6 - View Snacks";
        cout << "\n7 - View Desserts";
        cout << "\n8 - Party Specials / Offers";
        cout << "\n9 - Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        cin.ignore(); // to clear input buffer

        switch (choice) {
            case 1: obj.addItem(); break;
            case 2: obj.removeItem(); break;
            case 3: obj.vegMenu(); break;
            case 4: obj.nonVegMenu(); break;
            case 5: obj.drinks(); break;
            case 6: obj.snacks(); break;
            case 7: obj.desserts(); break;
            case 8: obj.partySpecial(); break;
            case 9: cout << "\nExiting..."; break;
            default: cout << "\nInvalid choice!\n"; break;
        }
    } while (choice != 9);

    return 0;
}

// Add new item to menu
void Restaurant::addItem() {
    bool dupilicate = false ;
    string tempID, tempName, tempPrice, tempCategory;

    cout << "\nEnter ItemID: ";
    getline(cin, ItemID);

file.open("Restaurant_Menu_Data", ios::in);
    while (getline(file, tempID, '|')) {
        getline(file, tempName, '|');
        getline(file, tempPrice, '|');
        getline(file, tempCategory);

        tempID.erase(remove(tempID.begin(), tempID.end(), ' '), tempID.end());
        ItemID.erase(remove(ItemID.begin(), ItemID.end(), ' '), ItemID.end());


    if(ItemID == tempID ){
        dupilicate = true ;
            break ;
    }
}
file.close();   

    if(dupilicate){
        cout << "\n Item ID already exists! Please try with a different ID.\n";
        return ;
    }
  
    cout << "\nEnter ItemName: ";
    getline(cin, ItemName);
    cout << "\nEnter Price: ";
    getline(cin, Price);
    cout << "\nEnter Category (Veg/Non-Veg/Drink/Snack/Dessert): ";
    getline(cin, Category);

    file.open("Restaurant_Menu_Data", ios::out | ios::app);
    if (file.is_open()) {
        file << ItemID << " | " << ItemName << " | " << Price << " | " << Category << "\n";
        file.close();
        cout << "\nItem added Successfully!";
    } else {
        cout << "\nError opening file!";
    }
}

// Remove item from menu
void Restaurant::removeItem() {
    bool found = false;
    cout << "\nEnter Item ID to Delete: ";
    getline(cin, sID);

    file.open("Restaurant_Menu_Data", ios::in);
    ofstream temp("Temp.txt");

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        if (ItemID != sID)
            temp << ItemID << " | " << ItemName << " | " << Price << " | " << Category << "\n";
        else
            found = true;
    }

    file.close();
    temp.close();
    remove("Restaurant_Menu_Data");
    rename("Temp.txt", "Restaurant_Menu_Data");

    if (found)
        cout << "\nItem Deleted Successfully!";
    else
        cout << "\nItem Not Found!";
}

// Show Veg menu
void Restaurant::vegMenu() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** VEG MENU **********\n";
    cout << "ItemId\tItemName\tItemPrice\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        // Clean spaces and lowercase for matching
        Category.erase(0, Category.find_first_not_of(' '));
        Category.erase(Category.find_last_not_of(' ') + 1);
        transform(Category.begin(), Category.end(), Category.begin(), ::tolower);

        if (Category == "veg") {
            cout << ItemID << "       | " << ItemName << "        | " << Price << "\n";
        }
    }
    file.close();
}

// Show Non-Veg menu
void Restaurant::nonVegMenu() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** NON-VEG MENU **********\n";
    cout << "ItemId\tItemName\tItemPrice\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        Category.erase(0, Category.find_first_not_of(' '));
        Category.erase(Category.find_last_not_of(' ') + 1);
        transform(Category.begin(), Category.end(), Category.begin(), ::tolower);

        if (Category == "non-veg") {
            cout << ItemID << "       | " << ItemName << "        | " << Price << "\n";
        }
    }
    file.close();
}

// Show Drinks menu
void Restaurant::drinks() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** DRINKS MENU **********\n";
    cout << "ItemId\tItemName\tItemPrice\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        Category.erase(0, Category.find_first_not_of(' '));
        Category.erase(Category.find_last_not_of(' ') + 1);
        transform(Category.begin(), Category.end(), Category.begin(), ::tolower);

        if (Category == "drink") {
            cout << ItemID << "       | " << ItemName << "        | " << Price << "\n";
        }
    }
    file.close();
}

// Show Snacks menu
void Restaurant::snacks() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** SNACKS MENU **********\n";
    cout << "ItemId\tItemName\tItemPrice\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        Category.erase(0, Category.find_first_not_of(' '));
        Category.erase(Category.find_last_not_of(' ') + 1);
        transform(Category.begin(), Category.end(), Category.begin(), ::tolower);

        if (Category == "snack") {
            cout << ItemID << "       | " << ItemName << "        | " << Price << "\n";
        }
    }
    file.close();
}

// Show Desserts menu
void Restaurant::desserts() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** DESSERTS MENU **********\n";
    cout << "ItemId\tItemName\tItemPrice\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        Category.erase(0, Category.find_first_not_of(' '));
        Category.erase(Category.find_last_not_of(' ') + 1);
        transform(Category.begin(), Category.end(), Category.begin(), ::tolower);

        if (Category == "dessert") {
            cout << ItemID << "       | " << ItemName << "        | " << Price << "\n";
        }
    }
    file.close();
}

// Show Party Specials (all items)
void Restaurant::partySpecial() {
    file.open("Restaurant_Menu_Data", ios::in);
    cout << "\n********** PARTY SPECIALS / OFFERS **********\n";
    cout << "ItemId\tItemName\tItemPrice\tCategory\n";

    while (getline(file, ItemID, '|')) {
        getline(file, ItemName, '|');
        getline(file, Price, '|');
        getline(file, Category);

        cout << ItemID << "       | " << ItemName << "        | " << Price << "        | " << Category << "\n";
    }
    file.close();
}
