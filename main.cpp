#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Student.h"

using namespace std;

int main() {
    ifstream in("students.csv");
    vector<Student> students;
    string line;
    getline();

    while (std::getline(in, line)) {

        Student s;

        stringstream ss(line);
        string group_str, gpa_str;

        getline(ss, s.name, ',');
        getline(ss, s.faculty, ',');
        getline(ss, group_str, ',');
        getline(ss, gpa_str, ',');

        s.group = std::stoi(group_str);
        s.gpa = std::stod(gpa_str);

        students.push_back(s);
    }

    in.close();

    auto start = chrono::high_resolution_clock::now();

    sort(students.begin(), students.end());

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Time: " << duration.count() << " ms\n";

    ofstream out("students_sorted.csv");
    out << "name,faculty,group,gpa\n";
    for (const auto& s : students) {
        out << s.name << "," << s.faculty << "," << s.group << "," << s.gpa << "\n";
    }
    out.close();

    return 0;
}