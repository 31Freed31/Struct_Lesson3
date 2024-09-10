#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Vector2D {
    double x;
    double y;
};

Vector2D add(const Vector2D& v1, const Vector2D& v2) {
    return { v1.x + v2.x, v1.y + v2.y };
}

Vector2D subtract(const Vector2D& v1, const Vector2D& v2) {
    return { v1.x - v2.x, v1.y - v2.y };
}

Vector2D scale(const Vector2D& v, double scalar) {
    return { v.x * scalar, v.y * scalar };
}

double length(const Vector2D& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vector2D normalize(const Vector2D& v) {
    double len = length(v);
    if (len == 0) {
        cout << "Cannot normalize zero-length vector." << endl;
        return { 0, 0 };
    }
    return { v.x / len, v.y / len };
}

int main() {
    string operation;
    cout << "Enter operation (add, subtract, scale, length, normalize): ";
    cin >> operation;

    if (operation == "add" || operation == "subtract") {
        Vector2D v1, v2;
        cout << "Enter vector 1 (x y): ";
        cin >> v1.x >> v1.y;
        cout << "Enter vector 2 (x y): ";
        cin >> v2.x >> v2.y;

        Vector2D result;
        if (operation == "add") {
            result = add(v1, v2);
        }
        else {
            result = subtract(v1, v2);
        }

        cout << "Resulting vector: (" << result.x << ", " << result.y << ")" << endl;

    }
    else if (operation == "scale") {
        Vector2D v;
        double scalar;
        cout << "Enter vector (x y): ";
        cin >> v.x >> v.y;
        cout << "Enter scalar: ";
        cin >> scalar;

        Vector2D result = scale(v, scalar);
        cout << "Resulting vector: (" << result.x << ", " << result.y << ")" << endl;

    }
    else if (operation == "length") {
        Vector2D v;
        cout << "Enter vector (x y): ";
        cin >> v.x >> v.y;

        double result = length(v);
        cout << "Length of vector: " << result << endl;

    }
    else if (operation == "normalize") {
        Vector2D v;
        cout << "Enter vector (x y): ";
        cin >> v.x >> v.y;

        Vector2D result = normalize(v);
        cout << "Normalized vector: (" << result.x << ", " << result.y << ")" << endl;

    }
    else {
        cout << "Unknown operation!" << endl;
    }
    return 0;
}
