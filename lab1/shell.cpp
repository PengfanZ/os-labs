#include <iostream>
#include <string>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
using namespace std;

int main()
{
    int status;
    string type1Commands[5] = {"hello", "bye", "assignment", "author", "section"};
    while (true)
    {
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
            pid_t parentOrChild = fork();
            if (parentOrChild == 0)
            {
                string dir = "/bin/" + command;
                const char *const args[] = {command.c_str(), nullptr};
                execve(dir.c_str(), const_cast<char *const *>(args), NULL);
                exit(status);
            }
            else
            {
                wait(&status);
            }
        }
    }
}