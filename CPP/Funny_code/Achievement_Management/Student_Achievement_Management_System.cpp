#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string className;
    int id;
    string name;
    map<string, float> scores;
    float average;

    Student() = default;
};

vector<Student> stuList;
set<string> globalCourseNames;

float InputScore(const string& subject) {
    float score;
    while (true) {
        cout << "Enter score for " << subject << " (1-100): ";
        cin >> score;
        if (score >= 1 && score <= 100) break;
        cout << "Invalid input. Please enter a score between 1 and 100.\n";
    }
    return score;
}

void Input(vector<Student>& students) {
    system("cls");
    char cont = 'y';

    while (tolower(cont) == 'y') {
        Student s;

        cout << "Enter Class Name: ";
        cin >> s.className;

        cout << "Enter Student ID: ";
        cin >> s.id;

        cout << "Enter Student Name: ";
        cin >> s.name;

        int courseCount;
        cout << "Enter number of courses: ";
        cin >> courseCount;

        float sum = 0;
        for (int i = 0; i < courseCount; i++) {
            string course;
            float score;

            cout << "Enter course name: ";
            cin >> course;
            globalCourseNames.insert(course);

            score = InputScore(course);
            s.scores[course] = score;
            sum += score;
        }

        s.average = (courseCount > 0) ? sum / courseCount : 0;
        students.push_back(s);

        cout << "Continue entering? (y/n): ";
        cin >> cont;
    }
}

void Write(const vector<Student>& students) {
    ofstream file("score.txt");
    if (!file) {
        cout << "Error: Cannot open file for writing.\n";
        return;
    }

    file << globalCourseNames.size() << "\n";
    for (const string& course : globalCourseNames) {
        file << course << " ";
    }
    file << "\n";

    file << students.size() << "\n";
    for (const auto& s : students) {
        file << s.className << " " << s.id << " " << s.name << " " << s.average << "\n";
        for (const string& course : globalCourseNames) {
            if (s.scores.count(course))
                file << s.scores.at(course) << " ";
            else
                file << -1 << " ";
        }
        file << "\n";
    }

    file.close();
}

vector<Student> Read() {
    ifstream file("score.txt");
    vector<Student> students;
    if (!file) {
        cout << "No score.txt file found.\n";
        return students;
    }

    int courseCount;
    file >> courseCount;
    globalCourseNames.clear();

    for (int i = 0; i < courseCount; i++) {
        string course;
        file >> course;
        globalCourseNames.insert(course);
    }

    int n;
    file >> n;
    for (int i = 0; i < n; i++) {
        Student s;
        file >> s.className >> s.id >> s.name >> s.average;

        for (const string& course : globalCourseNames) {
            float score;
            file >> score;
            if (score != -1)
                s.scores[course] = score;
        }

        students.push_back(s);
    }

    file.close();
    return students;
}

void Output(const vector<Student>& students) {
    system("cls");
    if (students.empty()) {
        cout << "No records to display.\n";
        system("pause");
        return;
    }

    cout << "Class\tID\tName";
    for (const string& c : globalCourseNames) cout << "\t" << c;
    cout << "\tAverage\n";
    cout << "-------------------------------------------------------------\n";

    for (const auto& s : students) {
        cout << s.className << "\t" << s.id << "\t" << s.name;
        for (const string& c : globalCourseNames) {
            if (s.scores.count(c)) cout << "\t" << s.scores.at(c);
            else cout << "\t-";
        }
        cout << "\t" << s.average << "\n";
    }

    cout << "-------------------------------------------------------------\n";
    system("pause");
}

int main() {
    int choice;
    do {
        system("cls");
        cout << "====== Student Management System ======\n";
        cout << "1. Input Student Records\n";
        cout << "2. Output All Records\n";
        cout << "0. Exit\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Input(stuList);
                Write(stuList);
                break;
            case 2:
                stuList = Read();
                Output(stuList);
                break;
            case 0:
                cout << "Goodbye!\n"; break;
            default:
                cout << "Invalid choice!\n"; system("pause");
        }
    } while (choice != 0);

    return 0;
}
