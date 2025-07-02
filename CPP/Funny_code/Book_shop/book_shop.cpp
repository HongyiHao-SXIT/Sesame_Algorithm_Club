#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string Name;
    string ID;
    bool isborrowed = false;

public:
    Book() = default;
    Book(string name, string id) : Name(name), ID(id) {}

    string getName() const {
        return Name;
    }

    void setName(const string& name) {
        Name = name;
    }

    string getID() const {
        return ID;
    }

    void setID(const string& id) {
        ID = id;
    }

    bool getIsBorrowed() const {
        return isborrowed;
    }

    void setIsBorrowed(bool status) {
        isborrowed = status;
    }
};

class User {
private:
    string Account;
    string Password;
    int Max_borrow = 20;
    int Num_borrow = 0;

public:
    User() = default;
    User(const string& account, const string& password)
        : Account(account), Password(password) {}

    void setAccount(const string& account) {
        Account = account;
    }

    string getAccount() const {
        return Account;
    }

    void setPassword(const string& password) {
        Password = password;
    }

    string getPassword() const {
        return Password;
    }

    int getMaxBorrow() const {
        return Max_borrow;
    }

    int getNumBorrow() const {
        return Num_borrow;
    }

    bool borrowBook() {
        if (Num_borrow < Max_borrow) {
            Num_borrow++;
            return true;
        }
        return false;
    }

    bool returnBook() {
        if (Num_borrow > 0) {
            Num_borrow--;
            return true;
        }
        return false;
    }
};

vector<User> users;
const string USER_FILE = "users.dat";

void loadUsers() {
    ifstream file(USER_FILE);
    if (!file.is_open()) return;

    string account, password;
    while (file >> account >> password) {
        users.emplace_back(account, password);
    }

    file.close();
}

void saveUsers() {
    ofstream file(USER_FILE);
    if (!file.is_open()) {
        cout << "Failed to save user data!" << endl;
        return;
    }

    for (const auto& user : users) {
        file << user.getAccount() << " " << user.getPassword() << endl;
    }

    file.close();
}

void login() {
    string account, password;
    cout << "Account: ";
    cin >> account;
    cout << "Password: ";
    cin >> password;

    bool success = false;
    for (const auto& user : users) {
        if (user.getAccount() == account && user.getPassword() == password) {
            success = true;
            cout << "Login successful! Welcome " << account << endl;
            break;
        }
    }

    if (!success) {
        cout << "Invalid account or password!" << endl;
    }
}

void registerUser() {
    string account, password, confirmPassword;

    cout << "Please enter a new account: ";
    cin >> account;

    for (const auto& user : users) {
        if (user.getAccount() == account) {
            cout << "This account already exists!" << endl;
            return;
        }
    }

    do {
        cout << "Please enter a password (at least 6 characters): ";
        cin >> password;
        if (password.length() < 6) {
            cout << "Password must be at least 6 characters long!" << endl;
        }
    } while (password.length() < 6);

    do {
        cout << "Please confirm the password: ";
        cin >> confirmPassword;
        if (confirmPassword != password) {
            cout << "The passwords do not match! Please re-enter." << endl;
        }
    } while (confirmPassword != password);

    users.emplace_back(account, password);
    saveUsers();
    cout << "Registration successful! You can now log in." << endl;
}

int main() {
    loadUsers();

    int choice;
    while (true) {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Please choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 0:
                cout << "Thank you for using the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    }
}
