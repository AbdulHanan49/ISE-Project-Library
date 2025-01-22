#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//Struct to hold Book details
struct Book {
    int id;
    string name;
    string type;
    string author;
    bool isIssued;

    Book(int id, string name, string type, string author) : id(id), name(name), type(type), author(author), isIssued(false) {}
};

//Struct to hold User details
struct User {
    string username;
    string password;
    vector<int> issuedBooks;

    User(string username, string password) : username(username), password(password) {}
};

vector<Book> books;
vector<User> users;

void loadBooks() {
    ifstream file("Books.txt");
    int id;
    string name, type, author;
    bool isIssued;

    while (file >> id) {
        file.ignore();
        getline(file, name);
        getline(file, type);
        getline(file, author);
        file >> isIssued;
        file.ignore();
        books.push_back(Book(id, name, type, author));
    }
    file.close();
}

void saveBooks() {
    ofstream file("Books.txt");
    for (const auto& book : books) {
        file << book.id << endl;
        file << book.name << endl;
        file << book.type << endl;
        file << book.author << endl;
        file << book.isIssued << endl;
    }
    file.close();
}

void loadUsers() {
    ifstream file("Users.txt");
    string username, password;
    while (file >> username >> password) {
        users.push_back(User(username, password));
    }
    file.close();
}

void saveUsers() {
    ofstream file("Users.txt");
    for (const auto& user : users) {
        file << user.username << " " << user.password << endl;
    }
    file.close();
}

void displayBooks() {
    cout << "\n============================================================================================\n";
    cout << setw(5) << left << "ID"
        << setw(30) << left << "Name"
        << setw(15) << left << "Type"
        << setw(25) << left << "Author"
        << setw(12) << left << "Status" << endl;
    cout << "============================================================================================\n";

    for (const auto& book : books) {
        cout << setw(5) << left << book.id
            << setw(30) << left << book.name
            << setw(15) << left << book.type
            << setw(25) << left << book.author
            << setw(12) << left << (book.isIssued ? "Issued" : "Available") << endl;
    }
    cout << "--------------------------------------------------------------------------------------------\n";
}

Book* findBookById(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            return &book;
        }
    }
    return nullptr;
}

void addBook() {
    int id = books.empty() ? 1 : books.back().id + 1;  // Generate unique ID for the new book
    string name, type, author;
    cout << "\nEnter book name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter book type: ";
    getline(cin, type);
    cout << "Enter book author: ";
    getline(cin, author);

    books.push_back(Book(id, name, type, author));
    saveBooks();
    cout << "\nBook added successfully!" << endl;
}

void removeBook() {
    int id;

    displayBooks();

    cout << "\nEnter book ID to remove: ";
    cin >> id;

    auto book = findBookById(id);
    if (book) {
        books.erase(remove_if(books.begin(), books.end(), [id](const Book& book) {
            return book.id == id;
            }), books.end());
        saveBooks();
        cout << "\nBook removed successfully!" << endl;
    }
    else {
        cout << "\nBook not found!" << endl;
    }
}

void editBook() {
    int id;

    displayBooks();

    cout << "\nEnter book ID to edit: ";
    cin >> id;

    auto book = findBookById(id);
    if (book) {
        string name, type, author;
        cout << "\nEnter new book name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter new book type: ";
        getline(cin, type);
        cout << "Enter new book author: ";
        getline(cin, author);

        book->name = name;
        book->type = type;
        book->author = author;
        saveBooks();
        cout << "\nBook details updated!" << endl;
    }
    else {
        cout << "\nBook not found!" << endl;
    }
}

void issueBook(User& user) {
    int id;

    displayBooks();

    cout << "\nEnter book ID to issue: ";
    cin >> id;

    auto book = findBookById(id);
    if (book) {
        if (!book->isIssued) {
            book->isIssued = true;
            user.issuedBooks.push_back(id);
            saveBooks();
            cout << "\nBook issued successfully!" << endl;
        }
        else {
            cout << "\nBook is already issued!" << endl;
        }
    }
    else {
        cout << "\nBook not found!" << endl;
    }
}

void returnBook(User& user) {
    int id;
    cout << "\nEnter book ID to return: ";
    cin >> id;

    auto book = findBookById(id);
    if (book) {
        auto it = find(user.issuedBooks.begin(), user.issuedBooks.end(), id);
        if (it != user.issuedBooks.end()) {
            book->isIssued = false;
            user.issuedBooks.erase(it);
            saveBooks();
            cout << "\nBook returned successfully!" << endl;
        }
        else {
            cout << "\nYou have not issued this book!" << endl;
        }
    }
    else {
        cout << "\nBook not found!" << endl;
    }
}

void signUp() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    users.push_back(User(username, password));
    saveUsers();
    cout << "\nUser signed up successfully!" << endl;
}

User* login() {
    string username, password;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (auto& user : users) {
        if (user.username == username && user.password == password) {
            return &user;
        }
    }

    cout << "\nInvalid username or password!" << endl;
    return nullptr;
}

void librarianMenu() {
    int choice;
    while (true) {

        cout << "\n==========================" << endl;
        cout << "      Librarian Menu" << endl;
        cout << "==========================\n\n";

        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Edit Book\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            editBook();
            break;
        case 4:
            return;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    }
}

void userMenu(User& user) {
    int choice;
    while (true) {
        cout << "\n==========================" << endl;
        cout << "       User Menu" << endl;
        cout << "==========================\n\n";

        cout << "1. Issue Book\n";
        cout << "2. Return Book\n";
        cout << "3. View Books\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            issueBook(user);
            break;
        case 2:
            returnBook(user);
            break;
        case 3:
            displayBooks();
            break;
        case 4:
            return;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    }
}

int main() {

    cout << "\n     ======================================" << endl;
    cout << "      WELCOME TO LIBRARY MANAGEMENT SYSTEM!" << endl;
    cout << "     ======================================\n\n";

    loadBooks();
    loadUsers();

    int choice;
    while (true) {
        cout << "==========================" << endl;
        cout << "      Main Menu" << endl;
        cout << "==========================\n\n";
        cout << "1. Librarian Login\n";
        cout << "2. User Sign Up\n";
        cout << "3. User Login\n";
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            librarianMenu();
            break;
        case 2:
            signUp();
            break;
        case 3:
        {
            User* user = login();
            if (user) {
                userMenu(*user);
            }
        }
        break;
        case 4:
            return 0;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    }
    system("pause");
}
