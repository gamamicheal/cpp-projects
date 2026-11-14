#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

struct Patient {
    int patientNumber;
    string name;
    int age;
    string gender;
    string contact;
    string diagnosis;
    string appointment;
    double consultationFee;
    double laboratoryFee;
    double medicationFee;
};

class HospitalSystem {
private:
    Patient patients[100];
    int totalPatients;
    int nextPatientNumber;

    string getText(string prompt) {
        string value;
        cout << prompt;
        getline(cin >> ws, value);
        return value;
    }

    int getInteger(string prompt, int minimum) {
        int value;

        while (true) {
            cout << prompt;

            if (cin >> value && value >= minimum) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }

            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    double getFee(string prompt) {
        double value;

        while (true) {
            cout << prompt;

            if (cin >> value && value >= 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }

            cout << "Invalid fee. Enter a non-negative amount.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void savePatients() {
        ofstream file("patients.txt");

        if (!file) {
            cout << "Error saving records.\n";
            return;
        }

        file << totalPatients << '\n';
        file << nextPatientNumber << '\n';

        for (int i = 0; i < totalPatients; i++) {
            file << patients[i].patientNumber << ' '
                 << quoted(patients[i].name) << ' '
                 << patients[i].age << ' '
                 << quoted(patients[i].gender) << ' '
                 << quoted(patients[i].contact) << ' '
                 << quoted(patients[i].diagnosis) << ' '
                 << quoted(patients[i].appointment) << ' '
                 << patients[i].consultationFee << ' '
                 << patients[i].laboratoryFee << ' '
                 << patients[i].medicationFee << '\n';
        }

        cout << "Records saved successfully.\n";
    }

    void loadPatients() {
        ifstream file("patients.txt");

        if (!file) {
            cout << "No previous records found.\n";
            return;
        }

        file >> totalPatients >> nextPatientNumber;

        if (!file || totalPatients < 0 || totalPatients > 100) {
            totalPatients = 0;
            nextPatientNumber = 1001;
            cout << "Invalid records file. Starting fresh.\n";
            return;
        }

        for (int i = 0; i < totalPatients; i++) {
            file >> patients[i].patientNumber
                 >> quoted(patients[i].name)
                 >> patients[i].age
                 >> quoted(patients[i].gender)
                 >> quoted(patients[i].contact)
                 >> quoted(patients[i].diagnosis)
                 >> quoted(patients[i].appointment)
                 >> patients[i].consultationFee
                 >> patients[i].laboratoryFee
                 >> patients[i].medicationFee;

            if (!file) {
                totalPatients = i;
                cout << "Warning: Incomplete records found.\n";
                break;
            }
        }

        cout << totalPatients << " record(s) loaded.\n";
    }

    void displayOnePatient(const Patient& p) {
        cout << "\n========== PATIENT DETAILS ==========\n";
        cout << "Patient number: " << p.patientNumber << '\n';
        cout << "Name: " << p.name << '\n';
        cout << "Age: " << p.age << '\n';
        cout << "Gender: " << p.gender << '\n';
        cout << "Contact: " << p.contact << '\n';
        cout << "Diagnosis: " << p.diagnosis << '\n';
        cout << "Appointment: " << p.appointment << '\n';

        cout << fixed << setprecision(2);
        cout << "Consultation fee: K" << p.consultationFee << '\n';
        cout << "Laboratory fee: K" << p.laboratoryFee << '\n';
        cout << "Medication fee: K" << p.medicationFee << '\n';

        double total = p.consultationFee +
                       p.laboratoryFee +
                       p.medicationFee;

        cout << "Total fees: K" << total << '\n';
        cout << "=====================================\n";
    }

public:
    HospitalSystem() {
        totalPatients = 0;
        nextPatientNumber = 1001;
        loadPatients();
    }

    void registerPatient() {
        if (totalPatients >= 100) {
            cout << "Maximum patient capacity reached.\n";
            return;
        }

        Patient p;

        p.patientNumber = nextPatientNumber++;

        cout << "\n========== REGISTER PATIENT ==========\n";
        cout << "Patient number: " << p.patientNumber << '\n';

        p.name = getText("Enter patient name: ");
        p.age = getInteger("Enter age: ", 1);
        p.gender = getText("Enter gender: ");
        p.contact = getText("Enter contact: ");
        p.diagnosis = getText("Enter diagnosis: ");
        p.appointment = getText("Enter appointment date/time: ");

        p.consultationFee = getFee("Consultation fee (K): ");
        p.laboratoryFee = getFee("Laboratory fee (K): ");
        p.medicationFee = getFee("Medication fee (K): ");

        patients[totalPatients] = p;
        totalPatients++;

        cout << "\nPatient registered successfully!\n";

        displayOnePatient(p);
        savePatients();
    }

    void displayAllPatients() {
        if (totalPatients == 0) {
            cout << "No patient records available.\n";
            return;
        }

        for (int i = 0; i < totalPatients; i++) {
            displayOnePatient(patients[i]);
        }
    }

    void searchPatient() {
        if (totalPatients == 0) {
            cout << "No records available.\n";
            return;
        }

        int number = getInteger("Enter patient number: ", 1);

        for (int i = 0; i < totalPatients; i++) {
            if (patients[i].patientNumber == number) {
                cout << "Patient found!\n";
                displayOnePatient(patients[i]);
                return;
            }
        }

        cout << "Patient not found.\n";
    }

    void showMenu() {
        int choice;

        do {
            cout << "\n=====================================\n";
            cout << "  HOSPITAL PATIENT MANAGEMENT SYSTEM\n";
            cout << "=====================================\n";
            cout << "1. Register patient\n";
            cout << "2. Display all patients\n";
            cout << "3. Search patient\n";
            cout << "4. Save records\n";
            cout << "5. Exit\n";
            cout << "=====================================\n";

            choice = getInteger("Enter choice: ", 1);

            switch (choice) {
                case 1:
                    registerPatient();
                    break;

                case 2:
                    displayAllPatients();
                    break;

                case 3:
                    searchPatient();
                    break;

                case 4:
                    savePatients();
                    break;

                case 5:
                    savePatients();
                    cout << "Thank you for using the system.\n";
                    break;

                default:
                    cout << "Invalid choice. Select 1 to 5.\n";
            }

        } while (choice != 5);
    }
};

int main() {
    HospitalSystem hospital;
    hospital.showMenu();

    return 0;
}
