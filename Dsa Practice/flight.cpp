
#include <iostream>
using namespace std;

int main()
{
    int cost[10][10];
    string city[10];
    int n, i, j;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter city names:\n";
    for (i = 0; i < n; i++)
        cin >> city[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cost[i][j] = 0;
    }

    cout << "Enter flight cost between cities (0 if no flight):\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                cout << city[i] << " to " << city[j] << ": ";
                cin >> cost[i][j];
            }
        }
    }

    cout << "\nFlight Graph (Adjacency Matrix):\n\t";

    for (i = 0; i < n; i++)
        cout << city[i] << "\t";

    cout << endl;

    for (i = 0; i < n; i++)
    {
        cout << city[i] << "\t";

        for (j = 0; j < n; j++)
            cout << cost[i][j] << "\t";

        cout << endl;
    }

    return 0;
}