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
}