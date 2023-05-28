#include <iostream>
#include <functions/functions.h>
#include <conio.h>
#include <list>
#include <memory>
#include <vector>
using namespace std;
using namespace peoples;


void printMenu() 
{
    cout << "Menu:\n"
        << "1. Add element to the array by index\n"
        << "2. Remove element from the array by index\n"
        << "3. Print the array\n"
        << "4. Exit\n";
}

int main() 
{
    HumanList humanList;

    while (true) 
    {
        cout << endl;
        printMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            system("cls");
            cout << "Enter the type of human (0 - Schooler, 1 - Student, 2 - Retire): ";
            int type;
            cin >> type;

            string name;
            cout << "Enter the name: ";
            cin.ignore();
            getline(cin, name);

            switch (type) 
            {
            case 0: 
            {
                string educational_institution;
                int ticket;
                bool is_large_family;

                cout << "Enter the educational institution: ";
                getline(cin, educational_institution);
                cout << "Enter the ticket number: ";
                cin >> ticket;
                cout << "Is it from a large family? (0 - No, 1 - Yes): ";
                cin >> is_large_family;

                HumanPtr human = make_shared<Schooler>(name, educational_institution, ticket, is_large_family);
                humanList.insert(humanList.size(), human);

                system("cls");
                cout << "Schooler added to the array.\n";
                break;
            }
            case 1: 
            {
                string educational_institution;
                int book;
                double score;

                cout << "Enter the educational institution: ";
                getline(cin, educational_institution);
                cout << "Enter the book number: ";
                cin >> book;
                cout << "Enter the score: ";
                cin >> score;

                HumanPtr human = make_shared<Student>(name, educational_institution, book, score);
                humanList.insert(humanList.size(), human);

                system("cls");
                cout << "Student added to the array.\n";
                break;
            }
            case 2: 
            {
                int id;
                int experience;

                cout << "Enter the ID: ";
                cin >> id;
                cout << "Enter the experience: ";
                cin >> experience;

                HumanPtr human = make_shared<Retire>(name, id, experience);
                humanList.insert(humanList.size(), human);

                system("cls");
                cout << "Retire added to the array.\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }

            break;
        }
        case 2: 
        {
            if (humanList.size() == 0) 
            {
                system("cls");
                cout << "The array is empty.\n";
                break;
            }

            system("cls");
            cout << "Enter the index of the element to remove: ";
            int index;
            cin >> index;

            try 
            {
                humanList.remove(index);
                system("cls");
                cout << "Element removed from the array.\n";
            }
            catch (const exception& e) 
            {
                system("cls");
                cout << "Invalid index. Please try again.\n";
            }

            break;
        }
        case 3: 
        {
            if (humanList.size() == 0) 
            {
                system("cls");
                cout << "The array is empty.\n";
                break;
            }

            system("cls");
            cout << "Printing the array:\n" << endl;
            for (int i = 0; i < humanList.size(); ++i) 
            {
                cout << "Human " << i << ":\n";
                humanList[i]->print(cout);
                cout << endl;
            }

            break;
        }
        case 4:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}