#include <iostream>
using namespace std;

class Cafeteria {
public:
    int remainingStudents(int students[], int sandwiches[], int n) {
        int Front = 0;
        int top = 0;
        int rotations = 0;
        while (Front < n && rotations < n) {
            if (students[Front] == sandwiches[top]) {
                top++;
                Front++;
                rotations = 0;
            } else {
                int temp = students[Front];
                for (int i = Front; i < n - 1; i++) {
                    students[i] = students[i + 1];
                }
                students[n - 1] = temp;
                rotations++;
            }
        }

        return n - top;
    }
};
int main() {
    int n;
    cout << "Enter number of students/sandwiches: ";
    cin >> n;
    int students[100], sandwiches[100];
    cout << "Enter student preferences (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++)
        cin >> students[i];
    cout << "Enter sandwich stack (0 for circular, 1 for square): ";
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];
    Cafeteria cafe;
    int result = cafe.remainingStudents(students, sandwiches, n);
    cout << "Number of students unable to eat: " << result << endl;
    return 0;
}
