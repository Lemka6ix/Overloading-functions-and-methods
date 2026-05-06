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

        Vector3D(double x1_p, double y1_p, double z1_p, double x2_p, double y2_p, double z2_p) 
        : x(x2_p - x1_p), y(y2_p - y1_p), z(z2_p - z1_p) {
        cnt++;
        std::cout << "The vector has been created. Total:" << cnt << std::endl;
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


void showVectors(const std::vector<Vector3D>& vectors) {
    if (vectors.empty()) {
        std::cout << "No vectors!" << std::endl;
        return;
    }
    
    std::cout << "Created vectors:" << std::endl;
    for (size_t i = 0; i < vectors.size(); ++i) {
        std::cout << i + 1 << ". ";
        vectors[i].print();
        std::cout << " (length: " << vectors[i].vector_length() << ")" << std::endl;
    }
}

int main() {
    std::vector<Vector3D> vectors;
    int choice;
    do {
        choice = menu(choice);
        switch (choice) {
            case 1: {
                Vector3D newVec = createVector();
                vectors.push_back(newVec);
                std::cout << "Vector created: ";
                newVec.print();
                std::cout << std::endl;
                break;
            }
            
            case 2: {
                showVectors(vectors);
                break;
            }
            
            case 3: {
                if (vectors.size() < 2) {
                    std::cout << "Not enough vectors!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx1, idx2;
                std::cout << "Select first vector: ";
                std::cin >> idx1;
                std::cout << "Select second vector: ";
                std::cin >> idx2;
                
                if (idx1 > 0 && idx1 <= vectors.size() && idx2 > 0 && idx2 <= vectors.size()) {
                    Vector3D result = vectors[idx1-1] + vectors[idx2-1];
                    vectors.push_back(result);
                    std::cout << "Addition result: ";
                    result.print();
                    std::cout << std::endl;
                } else {
                    std::cout << "Invalid selection!" << std::endl;
                }
                break;
            }

            case 4: {
                if (vectors.size() < 2) {
                    std::cout << "Not enough vectors for this operation!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx1, idx2;
                std::cout << "Select first vector: ";
                std::cin >> idx1;
                std::cout << "Select second vector: ";
                std::cin >> idx2;
                
                if (idx1 > 0 && idx1 <= vectors.size() && idx2 > 0 && idx2 <= vectors.size()) {
                    Vector3D result = vectors[idx1-1] - vectors[idx2-1];
                    vectors.push_back(result);
                    std::cout << "Subtraction result: ";
                    result.print();
                    std::cout << std::endl;
                } else {
                    std::cout << "Invalid vector selection!" << std::endl;
                }
                break;
            }
            
            case 5: {
                if (vectors.size() < 2) {
                    std::cout << "Not enough vectors for this operation!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx1, idx2;
                std::cout << "Select first vector: ";
                std::cin >> idx1;
                std::cout << "Select second vector: ";
                std::cin >> idx2;
                
                if (idx1 > 0 && idx1 <= vectors.size() && idx2 > 0 && idx2 <= vectors.size()) {
                    Vector3D result = vectors[idx1-1] * vectors[idx2-1];
                    vectors.push_back(result);
                    std::cout << "Multiplication result: ";
                    result.print();
                    std::cout << std::endl;
                } else {
                    std::cout << "Invalid vector selection!" << std::endl;
                }
                break;
            }
            
            case 6: {
                if (vectors.empty()) {
                    std::cout << "No vectors created!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx;
                std::cout << "Select vector to increase: ";
                std::cin >> idx;
                
                if (idx > 0 && idx <= vectors.size()) {
                    std::cout << "Before increase: ";
                    vectors[idx-1].print();
                    std::cout << " (length: " << vectors[idx-1].vector_length() << ")" << std::endl;
                    
                    ++vectors[idx-1];
                    
                    std::cout << "After increase: ";
                    vectors[idx-1].print();
                    std::cout << " (length: " << vectors[idx-1].vector_length() << ")" << std::endl;
                } else {
                    std::cout << "Invalid vector selection!" << std::endl;
                }
                break;
            }
            
            case 7: {
                if (vectors.empty()) {
                    std::cout << "No vectors created!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx;
                std::cout << "Select vector to decrease: ";
                std::cin >> idx;
                
                if (idx > 0 && idx <= vectors.size()) {
                    std::cout << "Before decrease: ";
                    vectors[idx-1].print();
                    std::cout << " (length: " << vectors[idx-1].vector_length() << ")" << std::endl;
                    
                    --vectors[idx-1];
                    
                    std::cout << "After decrease: ";
                    vectors[idx-1].print();
                    std::cout << " (length: " << vectors[idx-1].vector_length() << ")" << std::endl;
                } else {
                    std::cout << "Invalid vector selection!" << std::endl;
                }
                break;
            }
            
            case 8: {
                if (vectors.size() < 2) {
                    std::cout << "Not enough vectors for this operation!" << std::endl;
                    break;
                }
                showVectors(vectors);
                int idx1, idx2;
                std::cout << "Select first vector: ";
                std::cin >> idx1;
                std::cout << "Select second vector: ";
                std::cin >> idx2;
                
                if (idx1 > 0 && idx1 <= vectors.size() && idx2 > 0 && idx2 <= vectors.size()) {
                    const Vector3D& v1 = vectors[idx1-1];
                    const Vector3D& v2 = vectors[idx2-1];
                    
                    std::cout << "Vector 1: ";
                    v1.print();
                    std::cout << " (length: " << v1.vector_length() << ")" << std::endl;
                    
                    std::cout << "Vector 2: ";
                    v2.print();
                    std::cout << " (length: " << v2.vector_length() << ")" << std::endl;
                    
                    if (v1 < v2) std::cout << "First vector is shorter than second" << std::endl;
                    if (v1 > v2) std::cout << "First vector is longer than second" << std::endl;
                    if (v1 == v2) std::cout << "Vectors have equal length" << std::endl;
                    if (v1 != v2) std::cout << "Vectors have different lengths" << std::endl;
                } else {
                    std::cout << "Invalid vector selection!" << std::endl;
                }
                break;
            }
            
            case 9: {
                std::cout << "Total vectors created since program start: " << Vector3D::getCount() << std::endl;
                std::cout << "Current number of vectors in memory: " << vectors.size() << std::endl;
                break;
            }
            
            case 0: {
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            
            default: {
                std::cout << "Invalid choice!" << std::endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}