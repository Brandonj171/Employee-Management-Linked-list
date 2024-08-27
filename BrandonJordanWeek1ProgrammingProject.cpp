#include <iostream>
#include <string>
#include <fstream>

class Employees {
public:
    int employeeId;
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string emailAddress;
    double salary;

    // Constructor 
    Employees(int id, std::string fname, std::string lname, std::string phone, std::string email, double sal) {
        employeeId = id;
        firstName = fname;
        lastName = lname;
        phoneNumber = phone;
        emailAddress = email;
        salary = sal;
    }

    // Method to display employee data
    void DescribeTheEmployee() const {
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "First Name: " << firstName << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Email Address: " << emailAddress << std::endl;
        std::cout << "Salary: $ " << salary << std::endl;
    }
};

class Node {
public:
    Employees data; // This stores the employee data or object 
    Node* next; // This stores the pointer to the next node

    // Constructor to initialize a node 
    Node(Employees emp) : data(emp), next(nullptr) {}
};

class LinkedList {
private:
    Node* head; // Pointer to the first node in the list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to clean up the list
    ~LinkedList();

    // Method to insert a node in the list
    void insert(Employees emp);

    // Method to display the list
    void display() const;
};

LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next; // Save the next node
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
}

void LinkedList::insert(Employees emp) {
    Node* newNode = new Node(emp); // Create a new node
    Node** current = &head;

    // Find the insertion point
    while (*current != nullptr && (*current)->data.employeeId < emp.employeeId) {
        current = &(*current)->next;
    }

    // Insert the new node
    newNode->next = *current;
    *current = newNode;
}

void LinkedList::display() const {
    Node* current = head;

    while (current != nullptr) {
        current->data.DescribeTheEmployee(); // Call method to display employee data
        current = current->next; // Move to the next node
    }
}

int main() {
    LinkedList employeeList; // Initialize the LinkedList

    // Open the file. Use double backslashes or forward slashes.
    std::ifstream file("C:\\CS3330\\BrandonJordanWeek1ProgrammingProject\\Week 1-employeeDataset_Project 1.txt");
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Exit the program if the file can't be opened
    }

    // Variables to hold employee data
    int id;
    std::string fname, lname, phone, email;
    double sal;

    // Read each line and parse the data
    while (file >> id >> fname >> lname >> phone >> email >> sal) {
        Employees emp(id, fname, lname, phone, email, sal);
        employeeList.insert(emp);
    }

    file.close(); // Close the file after reading

    employeeList.display(); // Display the list of employees

    return 0;
}
