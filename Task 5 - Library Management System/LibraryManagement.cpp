#include <bits/stdc++.h>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};

struct Borrower {
    string name;
    string contact;
};

struct Transaction {
    Book book;
    Borrower borrower;
    time_t checkoutDate;
    time_t dueDate;
    bool returned;
};

class Library {
private:
    unordered_map<string, Book> booksDatabase;
    vector<Transaction> transactions;

public:
    void addBook(const string& title, const string& author, const string& ISBN) {
        Book book = {title, author, ISBN, true};
        booksDatabase[ISBN] = book;
    }

    vector<Book> searchBooks(const string& query) {
        vector<Book> results;
        for (auto& pair : booksDatabase) {
            Book& book = pair.second;
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.ISBN.find(query) != string::npos) {
                results.push_back(book);
            }
        }
        return results;
    }

    void checkoutBook(const string& ISBN, const Borrower& borrower) {
        if (booksDatabase.count(ISBN)) {
            Book& book = booksDatabase[ISBN];
            if (book.available) {
                time_t now = time(0);
                time_t dueDate = now + 30 * 24 * 60 * 60; // Due date is 1 month from now
                Transaction transaction = {book, borrower, now, dueDate, false};
                transactions.push_back(transaction);
                book.available = false;
                cout << "Book checked out successfully.\n";
            } 
            else {
                cout << "Book is not available for checkout.\n";
            }
        } 
        else {
            cout << "Book not found in the database.\n";
        }
    }

    void returnBook(const string& ISBN) {
        for (Transaction& transaction : transactions) {
            if (transaction.book.ISBN == ISBN && !transaction.returned) {
                time_t now = time(0);
                double diff = difftime(now, transaction.dueDate);
                double daysOverdue = diff / (24 * 60 * 60);
                if (daysOverdue > 0) {
                    double fine = daysOverdue * 1; // INR 1 fine per day overdue
                    cout << "Fine for overdue book : ₹" << fine << endl;
                }
                transaction.returned = true;
                booksDatabase[ISBN].available = true;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "No active transaction found for this book.\n";
    }
};

int main() {
    Library library;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Books\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            
            case 1: {
                string title, author, ISBN;
                cout << "Enter book title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter book ISBN: ";
                getline(cin, ISBN);
                library.addBook(title, author, ISBN);
                break;
            }
            
            case 2: {
                string ISBN;
                cout << "Enter ISBN of the book to remove: ";
                cin >> ISBN;
                library.returnBook(ISBN);
                break;
            }
            
            case 3: {
                string query;
                cout << "Enter search query: ";
                cin.ignore();
                getline(cin, query);
                vector<Book> results = library.searchBooks(query);
                if (results.empty()) {
                    cout << "No books found matching the query.\n";
                } else {
                    cout << "Search Results:\n";
                    for (const Book& book : results) {
                        cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN <<", Availability : "<<book.available << endl;
                    }
                }
                break;
            }
            
            case 4: {
                string ISBN, name, contact;
                cout << "Enter book ISBN to checkout: ";
                cin >> ISBN;
                cout << "Enter borrower name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter borrower contact: ";
                getline(cin, contact);
                Borrower borrower = {name, contact};
                library.checkoutBook(ISBN, borrower);
                break;
            }
            
            case 5: {
                string ISBN;
                cout << "Enter book ISBN to return: ";
                cin >> ISBN;
                library.returnBook(ISBN);
                break;
            }
            
            case 6:
                cout << "Thank you! Please visit again.\n";
                return 0;
            
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}