// Ch9Q2Grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name{};
    int score{};
};

int inpNumStudents()
{
    std::cout << "Enter the number of students:\t";

    int numStudents{};
    std::cin >> numStudents;

    return numStudents;
}

Student inpStudent()
{
    std::cout << "Enter Name:\t";
    std::string name{};
    std::cin >> name;

    std::cout << "Enter grade:\t";
    int grade{};
    std::cin >> grade;

    return { name, grade };
}

bool compareStudents(const Student& a, const Student& b)
{
    return (a.score > b.score);
}

int main()
{
    std::vector<Student> students;

    int numStudents{ inpNumStudents() };
    students.resize(numStudents);

    for (int i{ 0 }; i < numStudents; ++i)
    {
        students[i] = inpStudent();
    }

    std::sort(students.begin(), students.end(), compareStudents);

    for (int i{ 0 }; i < numStudents; ++i)
    {
        std::cout << students[i].name << " got a score of " << students[i].score << "\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
