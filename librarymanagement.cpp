 #include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    bool available;

    Book(std::string t, std::string a, std::string i)
        : title(t), author(a), isbn(i), available(true) {}
};

struct Borrower {
    std::string name;
    std::string contactInfo;

    Borrower(std::string n, std::string c)
        : name(n), contactInfo(c) {}
};

struct Transaction {
    std::string isbn;
    std::string borrowerName;
    std::time_t checkoutDate;
    std::time_t returnDate;
    bool returned;

    Transaction(std::string i, std::string b)
        : isbn(i), borrowerName(b), returned(false) {
        checkoutDate = std::time(nullptr);
        returnDate = 0;
    }
};

std::vector<Book> books;
std::unordered_map<std::string, Borrower> borrowers;
std::vector<Transaction> transactions;
void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
    books.emplace_back(title, author, isbn);
}

void searchBook(const std::string& query) {
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.isbn == query) {
            std::cout << "Title: " << book.title << ", Author: " << book.author 
                      << ", ISBN: " << book.isbn << ", Available: " << (book.available ? "Yes" : "No") << '\n';
        }
    }
}
 void checkoutBook(const std::string& isbn, const std::string& borrowerName) {
    for (auto& book : books) {
        if (book.isbn == isbn && book.available) {
            book.available = false;
            transactions.emplace_back(isbn, borrowerName);
            std::cout << "Book checked out successfully.\n";
            return;
        }
    }
    std::cout << "Book not available or not found.\n";
}

void returnBook(const std::string& isbn) {
    for (auto& book : books) {
        if (book.isbn == isbn && !book.available) {
            book.available = true;
            for (auto& transaction : transactions) {
                if (transaction.isbn == isbn && !transaction.returned) {
                    transaction.returned = true;
                    transaction.returnDate = std::time(nullptr);
                    std::cout << "Book returned successfully.\n";
                    return;
                }
            }
        }
    }
    std::cout << "Book not found or already returned.\n";
}
 double calculateFine(const std::string& isbn) {
    for (const auto& transaction : transactions) {
        if (transaction.isbn == isbn && transaction.returned) {
            std::time_t now = std::time(nullptr);
            double daysOverdue = difftime(now, transaction.checkoutDate) / (60 * 60 * 24) - 14; // Assuming a 2-week loan period
            if (daysOverdue > 0) {
                return daysOverdue * 0.50; // Assuming a fine of $0.50 per day
            }
        }
    }
    return 0.0;
}
void showMenu() {
    std::cout << "\n\n\nLibrary Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Search Book\n";
    std::cout << "3. Checkout Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Calculate Fine\n";
    std::cout << "6. Exit\n";
}

int main() {
    int choice;
    std::string title, author, isbn, borrowerName;

    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character after choice input

        switch (choice) {
        case 1:
            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            addBook(title, author, isbn);
            break;
        case 2:
            std::cout << "Enter title/author/ISBN to search: ";
            std::getline(std::cin, title);
            searchBook(title);
            break;
        case 3:
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter borrower name: ";
            std::getline(std::cin, borrowerName);
            checkoutBook(isbn, borrowerName);
            break;
        case 4:
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            returnBook(isbn);
            break;
        case 5:
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Fine: $" << calculateFine(isbn) << '\n';
            break;
        case 6:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}