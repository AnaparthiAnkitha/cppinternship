#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    float grade[100], credit[100];
    float totalCredits = 0, totalGradePoints = 0;

    cout << "========== CGPA CALCULATOR ==========\n";
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << endl;

        do {
            cout << "Enter Grade Point (0 - 10): ";
            cin >> grade[i];
            if (grade[i] < 0 || grade[i] > 10)
                cout << "Invalid Grade! Enter between 0 and 10.\n";
        } while (grade[i] < 0 || grade[i] > 10);

        do {
            cout << "Enter Credit Hours: ";
            cin >> credit[i];
            if (credit[i] <= 0)
                cout << "Credit Hours must be greater than 0.\n";
        } while (credit[i] <= 0);

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    // Semester GPA
    float semesterGPA = totalGradePoints / totalCredits;

    // Previous CGPA Details
    float previousCGPA, previousCredits;
    cout << "\nEnter Previous CGPA (0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter Previous Total Credits (0 if first semester): ";
    cin >> previousCredits;

    float overallCGPA;

    if (previousCredits == 0)
        overallCGPA = semesterGPA;
    else
        overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints) /
                      (previousCredits + totalCredits);

    // Display Results
    cout << "\n========== COURSE DETAILS ==========\n";
    cout << left << setw(10) << "Course"
         << setw(15) << "Grade"
         << setw(15) << "Credits" << endl;

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(10) << i + 1
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "\n====================================\n";
    cout << "Total Credits      : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Semester GPA       : " << semesterGPA << endl;
    cout << "Overall CGPA       : " << overallCGPA << endl;
    cout << "====================================\n";

    return 0;
}