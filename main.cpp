#include <iostream>
#include <string>
#include<conio.h>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    bool isIssued;

public:
    // Constructor
    Book(int id, const std::string& t, const std::string& a)
        : bookID(id), title(t), author(a), isIssued(false) {}

    // Issue the book
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            std::cout << "Book \"" << title << "\" has been issued." << std::endl;
        } else {
            std::cout << "Book \"" << title << "\" is already issued." << std::endl;
        }
    }

    // Return the book
    void returnBook() {
        if (isIssued) {
            isIssued = false;
            std::cout << "Book \"" << title << "\" has been returned." << std::endl;
        } else {
            std::cout << "Book \"" << title << "\" is not issued." << std::endl;
        }
    }

    // Display book details
    void displayDetails() const {
        std::cout << "Book ID: " << bookID << ", Title: \"" << title << "\", Author: \"" << author 
                  << "\", Issued: " << (isIssued ? "Yes" : "No") << std::endl;
    }

    // Getter for title (for member display)
    const std::string& getTitle() const {
        return title;
    }
};

class Member {
private:
    int memberID;
    std::string name;
    Book* bookIssued;

public:
    // Constructor
    Member(int id, const std::string& n) : memberID(id), name(n), bookIssued(nullptr) {}

    // Borrow a book
    void borrowBook(Book& book) {
        if (bookIssued == nullptr) {
            book.issueBook();
            bookIssued = &book;
        } else {
            std::cout << name << " has already borrowed a book." << std::endl;
        }
    }

    // Return the borrowed book
    void returnBook() {
        if (bookIssued != nullptr) {
            bookIssued->returnBook();
            bookIssued = nullptr;
        } else {
            std::cout << name << " has no book to return." << std::endl;
        }
    }

    // Display member details
    void displayMember() const {
        std::cout << "Member ID: " << memberID << ", Name: \"" << name << "\", Book Issued: " 
                  << (bookIssued ? bookIssued->getTitle() : "None") << std::endl;
    }
};

int main() {
    // Create books
    Book book1(1, "1984", "George Orwell");
    Book book2(2, "To Kill a Mockingbird", "Harper Lee");

    // Create a member
    Member member1(1, "Alice");

    // Display book details
    std::cout << "Initial Book Details:" << std::endl;
    book1.displayDetails();
    book2.displayDetails();
    std::cout << std::endl;

    // Member borrows a book
    std::cout << "Alice borrows a book:" << std::endl;
    member1.borrowBook(book1);
    member1.displayMember();
    std::cout << std::endl;

    // Return the book
    std::cout << "Alice returns the book:" << std::endl;
    member1.returnBook();
    member1.displayMember();
    std::cout << std::endl;

    // Attempt to borrow another book
    std::cout << "Alice borrows another book:" << std::endl;
    member1.borrowBook(book2);
    member1.displayMember();
    std::cout << std::endl;

    // Return the second book
    std::cout << "Alice returns the second book:" << std::endl;
    member1.returnBook();
    member1.displayMember();
    std::cout << std::endl;

    // Attempt to return a book when none is issued
    std::cout << "Alice tries to return a book again:" << std::endl;
    member1.returnBook();
    std::cout << std::endl;

    // Display final book details
    std::cout << "Final Book Details:" << std::endl;
    book1.displayDetails();
    book2.displayDetails();

    return 0;
}
