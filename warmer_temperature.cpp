#include <iostream>
using namespace std;

class Temperature {
public:
    int temp[100];
    int ans[100];
    int n;
    void input() {
        cout << "Enter number of days: ";
        cin >> n;
        cout << "Enter temperatures: ";
        for (int i = 0; i < n; i++) {
            cin >> temp[i];
        }
    }
    void findWarmerDays() {
        int stack[100];
        int top = -1;

        for (int i = 0; i < n; i++) {
            while (top != -1 && temp[i] > temp[stack[top]]) {
                int prev = stack[top];
                top--;
                ans[prev] = i - prev;
            }
            top++;
            stack[top] = i;
        }

        while (top != -1) {
            ans[stack[top]] = 0;
            top--;
        }
    }

    void display() {
        cout << "Days to wait for a warmer temperature:" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Temperature t;
    t.input();
    t.findWarmerDays();
    t.display();
    return 0;
}
