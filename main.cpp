#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct File {
    string name;
    string content;
};

vector<File> fileSystem;

void createFile() {
    string fname;
    cout << "Enter file name: ";
    cin >> fname;
    File f = {fname, ""};
    fileSystem.push_back(f);
    cout << "File created: " << fname << endl;
}

void writeFile() {
    string fname, content;
    cout << "Enter file name to write: ";
    cin >> fname;
    bool found = false;
    for (auto &f : fileSystem) {
        if (f.name == fname) {
            cout << "Enter content: ";
            cin.ignore();
            getline(cin, content);
            f.content = content;
            cout << "Content written to " << fname << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "File not found!" << endl;
}

void readFile() {
    string fname;
    cout << "Enter file name to read: ";
    cin >> fname;
    bool found = false;
    for (auto &f : fileSystem) {
        if (f.name == fname) {
            cout << "Content of " << fname << ": " << f.content << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "File not found!" << endl;
}

void listFiles() {
    cout << "Files in system:" << endl;
    for (auto &f : fileSystem) {
        cout << "- " << f.name << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\nFile System Simulator Menu:\n";
        cout << "1. Create File\n";
        cout << "2. Write File\n";
        cout << "3. Read File\n";
        cout << "4. List Files\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: createFile(); break;
            case 2: writeFile(); break;
            case 3: readFile(); break;
            case 4: listFiles(); break;
            case 5: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
