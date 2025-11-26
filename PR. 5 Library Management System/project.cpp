#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    string isbn;

public:
    Book(string t, string a, string d, string code) {
        if (code.size() < 5) throw runtime_error("Invalid ISBN");
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        isbn = code;
    }

    void checkOut() override {
        cout << getTitle() << " book issued.\n";
    }

    void returnItem() override {
        cout << getTitle() << " book returned.\n";
    }

    void displayDetails() override {
        cout << "\n[Book]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Author: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "ISBN: " << isbn << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur) {
        if (dur <= 0) throw runtime_error("Invalid duration");
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        duration = dur;
    }

    void checkOut() override {
        cout << getTitle() << " DVD issued.\n";
    }

    void returnItem() override {
        cout << getTitle() << " DVD returned.\n";
    }

    void displayDetails() override {
        cout << "\n[DVD]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Producer: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Duration: " << duration << " min\n";
    }
};

class Magazine : public LibraryItem {
private:
    int issue;

public:
    Magazine(string t, string a, string d, int num) {
        if (num <= 0) throw runtime_error("Invalid issue number");
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        issue = num;
    }

    void checkOut() override {
        cout << getTitle() << " magazine issued.\n";
    }

    void returnItem() override {
        cout << getTitle() << " magazine returned.\n";
    }

    void displayDetails() override {
        cout << "\n[Magazine]\n";
        cout << "Title: " << getTitle() << endl;
        cout << "Publisher: " << getAuthor() << endl;
        cout << "Due Date: " << getDueDate() << endl;
        cout << "Issue No: " << issue << endl;
    }
};

#define MAX_ITEMS 50

LibraryItem* items[MAX_ITEMS];
int countItems = 0;

void addBook() {
    string t, a, d, isbn;
    cout << "Title: ";
    cin >> t;
    cout << "Author: ";
    cin >> a;
    cout << "Due Date: ";
    cin >> d;
    cout << "ISBN: ";
    cin >> isbn;

    try {
        items[countItems++] = new Book(t, a, d, isbn);
        cout << "Book added.\n";
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void addDVD() {
    string t, a, d;
    int dur;
    cout << "Title: ";
    cin >> t;
    cout << "Producer: ";
    cin >> a;
    cout << "Due Date: ";
    cin >> d;
    cout << "Duration: ";
    cin >> dur;

    try {
        items[countItems++] = new DVD(t, a, d, dur);
        cout << "DVD added.\n";
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void addMagazine() {
    string t, a, d;
    int num;
    cout << "Title: ";
    cin >> t;
    cout << "Publisher: ";
    cin >> a;
    cout << "Due Date: ";
    cin >> d;
    cout << "Issue No: ";
    cin >> num;

    try {
        items[countItems++] = new Magazine(t, a, d, num);
        cout << "Magazine added.\n";
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
}

void showAll() {
    if (countItems == 0) {
        cout << "No items.\n";
        return;
    }

    for (int i = 0; i < countItems; i++) {
        items[i]->displayDetails();
    }
}

void checkoutItem() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= countItems) {
        cout << "Invalid index.\n";
        return;
    }

    items[i]->checkOut();
}

void returnItem() {
    int i;
    cout << "Enter index: ";
    cin >> i;

    if (i < 0 || i >= countItems) {
        cout << "Invalid index.\n";
        return;
    }

    items[i]->returnItem();
}

int main() {
    int choice;

    
    for (;;) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Show All Items\n";
        cout << "5. Checkout Item\n";
        cout << "6. Return Item\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) addDVD();
        else if (choice == 3) addMagazine();
        else if (choice == 4) showAll();
        else if (choice == 5) checkoutItem();
        else if (choice == 6) returnItem();
        else if (choice == 7) {
            cout << "Goodbye!\n";
            break;              
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
/* I have used ChatGPT as i was phasing some problem in the logic part */