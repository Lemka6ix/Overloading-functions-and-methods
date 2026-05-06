#include <iostream>
#include <cmath>
#include <vector>


class Vector3D {
    private:
        double x;
        double y;
        double z;
        static int cnt;

    public:
        Vector3D(double x_p, double y_p, double z_p) : x(x_p), y(y_p), z(z_p) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }


        Vector3D() : x(0), y(0), z(0) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }


        Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }

        Vector3D& operator=(const Vector3D& other) {
            if (this != &other) {
                x = other.x;
                y = other.y;
                z = other.z;
            }
            return *this;
        }


        ~Vector3D() {
            cnt--;
            std::cout << "The vector has been deleted. Left: " << cnt << std::endl;
        }


        void print() const {
            std::cout << "x: " << x << " y: " << y << " z: " << z;
        }


        double vector_length() const {
        return sqrt(x*x + y*y + z*z);
        }

        static int getCount() {
        return cnt;
        }

        Vector3D& operator++() {
        double percent = 1.01;
        x *= percent;
        y *= percent;
        z *= percent;
        return *this;
        }

        Vector3D operator++(int) {
        Vector3D temp = *this;
        double percent = 1.01;
        x *= percent;
        y *= percent;
        z *= percent;
        return temp;
        }

        Vector3D& operator--() {
        double percent = 1.01;
        x /= percent;
        y /= percent;
        z /= percent;
        return *this;
        }

        Vector3D operator--(int) {
        Vector3D temp = *this;
        double percent = 1.01;
        x /= percent;
        y /= percent;
        z /= percent;
        return temp;
        }

        Vector3D& operator+=(const Vector3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
        }

        Vector3D& operator-=(const Vector3D& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
        }

        Vector3D& operator*=(const Vector3D& other) {
        double result = x * other.x + y * other.y + z * other.z;
        x = result;
        y = result;
        z = result;
        return *this;
        }

        friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
        lhs += rhs;
        return lhs;
        }

        friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
        lhs -= rhs;
        return lhs;
        }

        friend Vector3D operator*(Vector3D lhs, const Vector3D& rhs) {
        lhs *= rhs;
        return lhs;
        }

        bool operator<(const Vector3D& other) const {
        return this->vector_length() < other.vector_length();
        }

        bool operator>(const Vector3D& other) const {
        return this->vector_length() > other.vector_length();
        }

        bool operator<=(const Vector3D& other) const {
        return this->vector_length() <= other.vector_length();
        }

        bool operator>=(const Vector3D& other) const {
        return this->vector_length() >= other.vector_length();
        }

        bool operator==(const Vector3D& other) const {
        return this->vector_length() == other.vector_length();
        }

         bool operator!=(const Vector3D& other) const {
        return this->vector_length() != other.vector_length();
        }
};


int Vector3D::cnt = 0;

int menu(int choice) {
    std::cout << "\n1. Create vector\n"
              << "2. Show all vectors\n"
              << "3. Vector addition\n"
              << "4. Vector subtraction\n"
              << "5. Vector multiplication\n"
              << "6. Increase vector by 1%\n"
              << "7. Decrease vector by 1%\n"
              << "8. Compare vector lengths\n"
              << "9. Show total vector count\n"
              << "0. Exit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    return choice;
}


Vector3D createVector() {
    int method;
    std::cout << "Choose creation method:\n";
    std::cout << "1. By coordinates (x, y, z)\n";
    std::cout << "2. By two points (x1, y1, z1, x2, y2, z2)\n";
    std::cout << "Your choice: ";
    std::cin >> method;
    
    if (method == 1) {
        double x, y, z;
        std::cout << "Enter vector coordinates (x y z): ";
        std::cin >> x >> y >> z;
        return Vector3D(x, y, z);
    }
    else if (method == 2) {
        double x1, y1, z1, x2, y2, z2;
        std::cout << "Enter first point (x1 y1 z1): ";
        std::cin >> x1 >> y1 >> z1;
        std::cout << "Enter second point (x2 y2 z2): ";
        std::cin >> x2 >> y2 >> z2;
        return Vector3D(x1, y1, z1, x2, y2, z2);
    }
    else {
        std::cout << "Invalid choice! Creating default vector.\n";
        return Vector3D();
    }
}
