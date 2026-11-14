#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Ticket {
    string passengerName;
    string destination;
    int ticketNumber;
    double ticketPrice;
};

class FlightTicketSystem {
private:
    Ticket tickets[100];
    int totalTickets = 0;
    int nextTicketNumber = 1001;

public:
    void bookTicket() {
        if (totalTickets >= 100) {
            cout << "\nTicket storage is full.\n";
            return;
        }

        Ticket newTicket;

        cout << "\nEnter passenger name: ";
        getline(cin >> ws, newTicket.passengerName);

        cout << "Enter destination: ";
        getline(cin, newTicket.destination);

        cout << "Enter ticket price: ";
        cin >> newTicket.ticketPrice;

        if (newTicket.ticketPrice <= 0) {
            cout << "Invalid ticket price.\n";
            return;
        }

        newTicket.ticketNumber = nextTicketNumber++;

        tickets[totalTickets] = newTicket;
        totalTickets++;

        cout << "\nTicket booked successfully!\n";
        cout << "Ticket Number: " << newTicket.ticketNumber << endl;
    }

    void displayTickets() {
        if (totalTickets == 0) {
            cout << "\nNo tickets have been booked.\n";
            return;
        }

        cout << "\n========== BOOKED FLIGHT TICKETS ==========\n";

        for (int i = 0; i < totalTickets; i++) {
            cout << "\nTicket Number: " << tickets[i].ticketNumber;
            cout << "\nPassenger: " << tickets[i].passengerName;
            cout << "\nDestination: " << tickets[i].destination;
            cout << "\nPrice: K" << fixed << setprecision(2)
                 << tickets[i].ticketPrice << endl;
        }
    }

    void searchTicket() {
        int number;

        cout << "\nEnter ticket number: ";
        cin >> number;

        for (int i = 0; i < totalTickets; i++) {
            if (tickets[i].ticketNumber == number) {
                cout << "\nTicket Found!\n";
                cout << "Passenger: " << tickets[i].passengerName << endl;
                cout << "Destination: " << tickets[i].destination << endl;
                cout << "Price: K" << tickets[i].ticketPrice << endl;
                return;
            }
        }

        cout << "\nTicket not found.\n";
    }

    void showMenu() {
        int choice;

        do {
            cout << "\n========== FLIGHT TICKET SYSTEM ==========\n";
            cout << "1. Book Flight Ticket\n";
            cout << "2. Display All Tickets\n";
            cout << "3. Search Ticket\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cout << "\nInvalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    bookTicket();
                    break;

                case 2:
                    displayTickets();
                    break;

                case 3:
                    searchTicket();
                    break;

                case 4:
                    cout << "\nThank you for using the system.\n";
                    break;

                default:
                    cout << "\nInvalid choice. Try again.\n";
            }

        } while (choice != 4);
    }
};

int main() {
    FlightTicketSystem system;
    system.showMenu();

    return 0;
}
