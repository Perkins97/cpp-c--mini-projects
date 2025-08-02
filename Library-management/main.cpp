#include <iostream>
#include <vector>

 using namespace std;

struct  Book  {
public:
    string bookId, bookTitle, bookAuthor, bookYear;
    int bookQuantity;
    vector <int> booksQuantity;
    vector <string> booksId, booksTitle, booksAuthor, booksYear;

    void addBooks() {
        cin.ignore();
        cout << "Enter book ID :" ;
        getline(cin, bookId);
        booksId.push_back(bookId);

        cout << "Enter title :" ;
        getline(cin, bookTitle);
        booksTitle.push_back(bookTitle);

        cout << "Enter author's name :"  ;
        getline(cin, bookAuthor);
        booksAuthor.push_back(bookAuthor);

        cout << "Year of publication : " ;
        getline(cin, bookYear);
        booksYear.push_back(bookYear);

        cout << "Enter quantity :" ;
        cin >> bookQuantity;
        booksQuantity.push_back(bookQuantity);
    }
    void viewBooks() const {
        if (booksId.empty()) {
            cout << "No books available in library." << endl;
        }
        for (int i = 0; i < booksId.size(); ++i) {
            cout << i + 1 << ". Book ID: " << booksId[i]
          << " | Title: " << booksTitle[i]
          << " | Author: " << booksAuthor[i]
          << " | Year: " << booksYear[i]
          << " | Quantity: " << booksQuantity[i] << endl;
        }
    }

     void bookSearch() const {
        string bookKey;
        bool found = false;
        cin.ignore();
        cout << "Search by ID :" ;
        getline(cin, bookKey);

        for (int i = 0; i < booksId.size(); i++) {
            if (booksId[i] == bookKey) {
                cout <<"Book Found " << endl;
                cout << " Book ID: " << booksId[i]
                << " | Title: " << booksTitle[i]
                << " | Author: " << booksAuthor[i]
                << " | Year: " << booksYear[i]
                << " | Quantity: " << booksQuantity[i] << endl;
                found = true;
                break;
            }
        }
        if (!found || booksId.empty()) {
            cout << "Book Not Found / Book not available !!!." << endl;
        }
    }

    void borrowBook()  {
           string borrowTitle;
        char borrowChoice;
        cin.ignore();
        cout << "Enter book title to borrow :" ;
        getline(cin, borrowTitle);
        if (booksId.empty()) {
            cout << "No books available to borrow." << endl;
        }
        for  (int i = 0; i < booksId.size(); ++i) {

            if (booksTitle[i] == borrowTitle) {
                if (booksQuantity[i] > 0) {
                    cout << "Do you want to borrow this book ? (Y/N)" << endl;
                    cin >> borrowChoice;

                    if (borrowChoice == 'Y' || borrowChoice == 'y') {
                        booksQuantity[i]--;
                        cout << "Book borrowed Successfully." << endl;
                    }
                    else {
                        cout << "Borrow cancelled." << endl;
                    }
                    return;
                }
            }
            else if (booksQuantity[i] <= 0) {
                cout << "Book out of stock or unavailable." << endl;
            }

        }

    }

    void returnBook() {
        string returnTitle;
        char returnChoice;

        cin.ignore();
        cout << "Enter book title :" ;
        getline(cin, returnTitle);

        for  (int i = 0; i < booksId.size(); ++i) {

                if (booksTitle[i]== returnTitle) {
                    cout << "Do you want to return this book ? (Y/N)" << endl;
                    cin >> returnChoice;

                    if (returnChoice == 'Y' || returnChoice == 'y') {
                        booksQuantity[i]++;
                        cout << "Book returned Successfully." << endl;
                    }
                    else {
                        cout << "Return cancelled." << endl;
                    }
                    return;
                }


        }
    }

    void deleteBook() {
        char confirm;
        string deleteId;
        if (booksId.empty()) {
            cout << "No books available to delete !!! ." << endl;
            return;
        }

        cout << "Enter book ID to delete :" ;
        cin.ignore();
        getline(cin, deleteId);

        bool found = false;

        for (int i = 0; i < booksId.size(); ++i) {


            if (deleteId == booksId[i]) {
                cout << "Do you want to delete this book from library? (Y/N)." << endl;
                cin >> confirm;
                if (confirm == 'Y' || confirm == 'y') {
                    booksId.erase(booksId.begin() + i);
                    booksTitle.erase(booksTitle.begin ()+ i);
                    booksAuthor.erase(booksAuthor.begin() + i);
                    booksYear.erase(booksYear.begin() + i);
                    booksQuantity.erase(booksQuantity.begin() + i);

                    cout << "Book successfully deleted." << endl;
                }else {
                    cout << "Deletion Cancelled."<< endl;
                }
                found = true;
                break;
            }
            else {

            }

        }
        if (!found) {
            cout << "No book found with that ID." << endl;
        }
    }
};




int main () {
    Book book1;

    char extraBooks;
    int choice;
    do {
        cout <<"== ADMIN DASHBOARD ==" << endl;
        cout <<"1. Add New Books" << endl;
        cout <<"2. View All Books" << endl;
        cout <<"3. Search Book" << endl;
        cout <<"4. Borrow Book" << endl;
        cout <<"5. Return Book" << endl;
        cout <<"6. Delete Book" << endl;
        cout <<"7. Exit " << endl;
        cin >> choice;

//BOOK ADDING SESSION
        if (choice ==1 ) {
            cout << "== ADD BOOK TO LIBRARY ==" << endl;
            book1.addBooks();
            cout << "Books Added." << endl;

            do {

                cout << "Add another set of Books ? (Y/N)" << endl;
                cin >> extraBooks;
                if (extraBooks == 'y' || extraBooks == 'Y') {
                    book1.addBooks();
                }
                else {
                    cout << "All Books added successfully." << endl;
                }

            } while (extraBooks == 'Y' || extraBooks == 'y');
        }
// WHEN USER WANTS TO VIEW ALL AVAILABLE BOOKS IN THE LIBRARY
        else if (choice == 2) {
            cout << "== BOOKS IN LIBRARY ==" << endl;
            book1.viewBooks();
        }
//WHEN USER WANTS TO SEARCH FOR A PARTICULAR BOOK
        else if (choice == 3) {
            cout << "== BOOK SEARCH ==" << endl;
            book1.bookSearch();
        }
//BOOK BORROWING SESSION
        else if (choice == 4) {
            cout << "== BORROW BOOK ==" << endl;
            book1.viewBooks();
            book1.borrowBook();
            cin.ignore();
        }
//BOOK RETURN SESSION WHEN STUDENT RETURNS A BORROWED BOOK
        else if (choice == 5) {
            cout << "== BOOK RETURN ==" << endl;
            book1.returnBook();
        }
//DELETE SESSION, WHERE USER CAN DELETE BOOKS THAT ARE NO LONGER NEEDED
        else if (choice == 6) {
            cout << "== BOOK DELETION ==" << endl;
            book1.deleteBook();
        }

    } while ( choice != 7);



    return 0;
}