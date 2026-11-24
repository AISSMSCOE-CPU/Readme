#include <iostream>
using namespace std;

struct Student
{
    int PRN;
    int date;
    int month;
};

int main()
{
    Student A[50], B[50], SE_AIML_DOB[100];
    int n, m, i, j, k;

    cout << "Enter number of students in Division A: ";
    cin >> n;

    cout << "Enter PRN, date and month for Division A:\n";
    for (i = 0; i < n; i++)
    {
        cin >> A[i].PRN >> A[i].date >> A[i].month;
    }

    cout << "Enter number of students in Division B: ";
    cin >> m;

    cout << "Enter PRN, date and month for Division B:\n";
    for (i = 0; i < m; i++)
    {
        cin >> B[i].PRN >> B[i].date >> B[i].month;
    }

    i = 0;
    j = 0;
    k = 0;

    while (i < n && j < m)
    {
        if (A[i].month < B[j].month ||
           (A[i].month == B[j].month &&
            A[i].date <= B[j].date))
        {
            SE_AIML_DOB[k] = A[i];
            i++;
        }
        else
        {
            SE_AIML_DOB[k] = B[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        SE_AIML_DOB[k] = A[i];
        i++;
        k++;
    }

    while (j < m)
    {
        SE_AIML_DOB[k] = B[j];
        j++;
        k++;
    }

    cout << "\nSorted SE AIML Students by Date of Birth:\n";
    cout << "PRN\tDate\tMonth\n";

    for (i = 0; i < k; i++)
    {
        cout << SE_AIML_DOB[i].PRN << "\t"
             << SE_AIML_DOB[i].date << "\t"
             << SE_AIML_DOB[i].month << endl;
    }

    return 0;
}
