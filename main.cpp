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