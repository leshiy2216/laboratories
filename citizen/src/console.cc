#include <iostream>
#include <functions/functions.h>
#include <conio.h>
#include <list>
using namespace std;
using namespace peoples;

int main() {
    HumanList humans;
    int choice;
    int index;
    Human human;
    int typeChoice;
    string name;
    string schoolORuniversity;
    int ticket;
    bool family;
    int book;
    double score;
    int id;
    int experience;

    do {
        cout << "Menu:" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Print list" << endl;
        cout << "4. Search for element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            system("cls");
            cout << "Enter index: ";
            std::cin >> index;
            system("cls");
            cout << "Choice type: " << endl;
            cout << "1. Schooler" << endl;
            cout << "2. Student" << endl;
            cout << "3. Retire" << endl;
            std::cin >> typeChoice;
            if (typeChoice == 1)
            {
                system("cls");
                human.set_type(SCHOOLER);
                cout << "Enter name: " << endl;
                std::cin >> name;
                human.set_name(name);
                system("cls");
                cout << "Enter School " << endl;
                std::cin >> schoolORuniversity;
                human.set_educational_institution(schoolORuniversity);
                system("cls");
                cout << "Enter ticket" << endl;
                std::cin >> ticket;
                human.set_ticket(ticket);
                system("cls");
                cout << "From large family? " << endl;
                std::cin >> family;
                human.set_is_large_family(family);
            }
            if (typeChoice == 2)
            {
                system("cls");
                human.set_type(STUDENT);
                cout << "Enter name: " << endl;
                std::cin >> name;
                human.set_name(name);
                system("cls");
                cout << "Enter university " << endl;
                std::cin >> schoolORuniversity;
                human.set_educational_institution(schoolORuniversity);
                system("cls");
                cout << "Enter book" << endl;
                std::cin >> book;
                human.set_book(book);
                system("cls");
                cout << "Enter score" << endl;
                std::cin >> score;
                human.set_score(score);
            }
            if (typeChoice == 3)
            {
                system("cls");
                human.set_type(RETIRE);
                cout << "Enter name" << endl;
                std::cin >> name;
                human.set_name(name);
                system("cls");
                cout << "Enter ID" << endl;
                std::cin >> id;
                human.set_retire_id(id);
                system("cls");
                cout << "Enter experience" << endl;
                std::cin >> experience;
                human.set_experience(experience);
            }
            humans.insert(&human);
            break;
        case 2:
            system("cls");
            cout << "Enter index: ";
            std::cin >> index;
            humans.remove(index);
            break;
        case 3:
            humans.print_list(2);
            break;
        case 4:
            system("cls");
           // double max = humans.search_max_payday(human, 5);
            break;
        case 5:
            system("cls");
            cout << "Exiting..." << endl;
            break;
        default:
            system("cls");
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}