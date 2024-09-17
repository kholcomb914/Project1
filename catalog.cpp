//
//  catalog.cpp
//  Project1
//
//  Created by Kaustubh on 9/12/24.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include <sstream>

struct bookT {
    std::string title;
    std::list<std::string> authors;
    int catalogNumber;
    std::list<std::string> subjectHeadings;
    std::string publisher;
    int publicationYear;
    bool isCirculating;
};

struct libraryT {
    std::list<bookT> books;
};

void searchBySubject(libraryT lib, std::string subject);
std::list<bookT> populate();
void titleAuthor(bookT book);

int main() {
    
    libraryT libdata;
    libdata.books = populate();
    bool run = true;
    
    while(run) {
        std::string action;
        std::cout << "LIBRARY OF CONGRESS CATALOG MENU" << std::endl;
        std::cout << "Add new book (add)" << std::endl;
        std::cout << "Search by subject (search)" << std::endl;
        std::cout << "List all books (list)" << std::endl;
        std::cout << "Close menu (exit)" << std::endl;
        std::cout << "Select an action: " << std::endl;
        std::cin >> action;
        std::cout << std::endl;
        
        if(action.compare("add") == 0) {
            
            std::cout << "Title: ";
            std::string title;
            std::cin.ignore();
            std::getline(std::cin, title);
            
            std::cout << "Author: ";
            std::string author;
            std::cin.ignore();
            std::getline(std::cin, author);
            
            std::cout << "Library number: ";
            int libNumber;
            std::cin >> libNumber;
            
            std::cout << "Subject: ";
            std::string subject;
            std::cin.ignore();
            std::getline(std::cin, subject);
            
            std::cout << "Publisher: ";
            std::string publisher;
            std::cin.ignore();
            std::getline(std::cin, publisher);
            
            std::cout << "Year: ";
            int year;
            std::cin >> year;
            
            std::cout << "Circulation status (true/false): ";
            std::string cString;
            std::cin >> cString;
            bool circulation;
            std::istringstream(cString) >> std::boolalpha >> circulation;
            
            std::list<std::string> authors;
            authors.push_back(author);
            std::list<std::string> subjects;
            subjects.push_back(subject);
            bookT newBook = {title, authors, libNumber, subjects, publisher, year, circulation};
            libdata.books.push_back(newBook);
            std::cout << std::endl;
        }
        
        else if(action.compare("search") == 0) {
            std::string subject;
            std::cout << "Enter subject to search for: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, subject);
            searchBySubject(libdata, subject);
            std::cout << std::endl;
        }
        
        else if(action.compare("list") == 0) {
            for(bookT b : libdata.books) {
                titleAuthor(b);
            }
            std::cout << std::endl;
        }
        
        else if(action.compare("exit") == 0) {
            run = false;
        }
        
        else {
            std::cout << "Invalid action command. Please try again. Commands must be lowercase.\n" << std::endl;
        }
    }
    
    std::cout << "Exiting..." << std::endl;
    return 0;
    
}

void searchBySubject(libraryT lib, std::string subject) {
    std::cout << "Books found with subject " << "\"" << subject << "\":" << std::endl;
    for(bookT book : lib.books) {
        for(std::string subj : book.subjectHeadings) {
            if(subject.compare(subj) == 0) {
                std::cout << book.title << ", by " << book.authors.front() << ", No. " << book.catalogNumber << std::endl;
            }
        }
    }
}

void titleAuthor(bookT book) {
    std::cout << book.title << ", by " << book.authors.front() << std::endl;
}

std::list<bookT> populate() {
    
    std::list<std::string> authors1;
    authors1.push_back("H.G. Wells");
    std::list<std::string> subjects1;
    subjects1.push_back("Science Fiction");
    bookT book1 = {"The War of the Worlds", authors1, 24022215, subjects1, "Harper & Brothers", 1922, true};
    
    std::list<std::string> authors2;
    authors2.push_back("Ray Bradbury");
    std::list<std::string> subjects2;
    subjects2.push_back("Science Fiction");
    subjects2.push_back("Dystopian Fiction");
    bookT book2 = {"Fahrenheit 451", authors2, 86203002, subjects2, "Dramatic Pub. Co.", 1986, true};
    
    std::list<std::string> authors3;
    authors3.push_back("Bram Stoker");
    std::list<std::string> subjects3;
    subjects3.push_back("Fantasy");
    subjects3.push_back("Horror");
    bookT book3 = {"Dracula", authors3, 11843662, subjects3, "Page & Co.", 1920, true};
    
    std::list<std::string> authors4;
    authors4.push_back("William Golding");
    std::list<std::string> subjects4;
    subjects4.push_back("Psychological Fiction");
    bookT book4 = {"Lord of the Flies", authors4, 55010081, subjects4, "Coward-McCann", 1954, true};
    
    std::list<std::string> authors5;
    authors5.push_back("Joseph Heller");
    std::list<std::string> subjects5;
    subjects5.push_back("Historical Fiction");
    bookT book5 = {"Catch-22", authors5, 61012846, subjects5, "Simon and Schuster", 1961, true};

    std::list<bookT> books;
    books.push_back(book1);
    books.push_back(book2);
    books.push_back(book3);
    books.push_back(book4);
    books.push_back(book5);
    
    return books;
    
}
