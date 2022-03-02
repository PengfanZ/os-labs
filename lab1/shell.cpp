#include <iostream>
#include <string>
using namespace std;

int main()
{
    string type1Commands[5] = {"hello", "bye", "assignment", "author", "section"};
    while (true)
    {
        cout << "Shell> ";
        string command;
        getline(cin, command);
        if (command == "hello")
        {
            cout << "Hello from OS Class\n";
        }
        else if (command == "bye")
        {
            cout << "Goodbye\n";
            break;
        }
        else if (command == "assignment")
        {
            cout << "202 lab #1 (Spring 2022)\n";
        }
        else if (command == "author")
        {
            cout << "Pengfan Zhang \n"
                 << "N11814324\n"
                 << "pz723\n";
        }
        else if (command == "section")
        {
            cout << "003\n";
        }
        else
        {
            // TODO:
        }
    }
}