/**
 * @file main.cpp
 * @brief Программа для операций с 3D векторами
 * @details Эта программа предоставляет комплексную реализацию операций с 3D векторами,
 * включая арифметические операции, сравнения и различные вспомогательные функции.
 */
#include <iostream>
#include <cmath>
#include <vector>


/**
 * @class Vector3D
 * @brief Представляет 3-мерный вектор с координатами x, y, z
 * 
 * Этот класс предоставляет различные операции для 3D векторов, включая арифметические операции,
 * сравнения, вычисление длины и статистический отсчет созданных векторов.
 */
class Vector3D {
    private:
        double x;    ///< Координата X вектора
        double y;    ///< Координата Y вектора
        double z;    ///< Координата Z вектора
        static int cnt;   ///< Статический счетчик для отслеживания общего количества экземпляров Vector3D

    public:

        /**
         * @brief Конструктор, создающий вектор из координат
         * @param x_p Значение координаты X
         * @param y_p Значение координаты Y
         * @param z_p Значение координаты Z
         */
        Vector3D(double x_p, double y_p, double z_p) : x(x_p), y(y_p), z(z_p) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }

        /**
         * @brief Конструктор, создающий вектор из двух точек
         * @param x1_p Координата X первой точки
         * @param y1_p Координата Y первой точки
         * @param z1_p Координата Z первой точки
         * @param x2_p Координата X второй точки
         * @param y2_p Координата Y второй точки
         * @param z2_p Координата Z второй точки
         * 
         * Создает вектор, направленный из (x1,y1,z1) в (x2,y2,z2)
         */
        Vector3D(double x1_p, double y1_p, double z1_p, double x2_p, double y2_p, double z2_p) 
        : x(x2_p - x1_p), y(y2_p - y1_p), z(z2_p - z1_p) {
        cnt++;
        std::cout << "The vector has been created. Total:" << cnt << std::endl;
        }

        /**
         * @brief Конструктор по умолчанию - создает нулевой вектор
         */
        Vector3D() : x(0), y(0), z(0) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }

        /**
         * @brief Конструктор копирования
         * @param other Вектор для копирования
         */
        Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {
            cnt++;
            std::cout << "The vector has been created. Total: " << cnt << std::endl;
        }


        /**
         * @brief Оператор присваивания
         * @param other Вектор для присваивания
         * @return Ссылка на этот вектор
         */
        Vector3D& operator=(const Vector3D& other) {
            if (this != &other) {
                x = other.x;
                y = other.y;
                z = other.z;
            }
            return *this;
        }

        /**
         * @brief Деструктор - уменьшает счетчик экземпляров
         */
        ~Vector3D() {
            cnt--;
            std::cout << "The vector has been deleted. Left: " << cnt << std::endl;
        }

        /**
         * @brief Выводит координаты вектора в стандартный вывод
         */
        void print() const {
            std::cout << "x: " << x << " y: " << y << " z: " << z;
        }


        /**
         * @brief Вычисляет длину (величину) вектора
         * @return Длина вектора как double
         */
        double vector_length() const {
        return sqrt(x*x + y*y + z*z);
        }


        /**
         * @brief Получает общее количество созданных экземпляров Vector3D
         * @return Общее количество векторов, созданных с начала программы
         */
        static int getCount() {
        return cnt;
        }


        // Унарные операторы

        /**
         * @brief Префиксный оператор инкремента - увеличивает длину вектора на 1%
         * @return Ссылка на этот вектор после инкремента
         */
        Vector3D& operator++() {
        double percent = 1.01;
        x *= percent;
        y *= percent;
        z *= percent;
        return *this;
        }


        /**
         * @brief Постфиксный оператор инкремента - увеличивает длину вектора на 1%
         * @return Копия вектора до инкремента
         */
        Vector3D operator++(int) {
        Vector3D temp = *this;
        double percent = 1.01;
        x *= percent;
        y *= percent;
        z *= percent;
        return temp;
        }


        /**
         * @brief Префиксный оператор декремента - уменьшает длину вектора на 1%
         * @return Ссылка на этот вектор после декремента
         */
        Vector3D& operator--() {
        double percent = 1.01;
        x /= percent;
        y /= percent;
        z /= percent;
        return *this;
        }

        /**
         * @brief Постфиксный оператор декремента - уменьшает длину вектора на 1%
         * @return Копия вектора до декремента
         */
        Vector3D operator--(int) {
        Vector3D temp = *this;
        double percent = 1.01;
        x /= percent;
        y /= percent;
        z /= percent;
        return temp;
        }


        // Составные операторы присваивания

        /**
         * @brief Составной оператор присваивания сложения
         * @param other Вектор для сложения
         * @return Ссылка на этот вектор после сложения
         */
        Vector3D& operator+=(const Vector3D& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
        }

        /**
         * @brief Составной оператор присваивания вычитания
         * @param other Вектор для вычитания
         * @return Ссылка на этот вектор после вычитания
         */
        Vector3D& operator-=(const Vector3D& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
        }

        /**
         * @brief Составной оператор присваивания умножения (скалярное произведение)
         * @param other Вектор для умножения
         * @return Ссылка на этот вектор после умножения
         * @note Это преобразует вектор в скалярный результат во всех компонентах
         */
        Vector3D& operator*=(const Vector3D& other) {
        double result = x * other.x + y * other.y + z * other.z;
        x = result;
        y = result;
        z = result;
        return *this;
        }


        // Бинарные арифметические операторы

        /**
         * @brief Оператор сложения для двух векторов
         * @param lhs Вектор слева от оператора
         * @param rhs Вектор справа от оператора
         * @return Новый вектор - результат сложения
         */
        friend Vector3D operator+(Vector3D lhs, const Vector3D& rhs) {
        lhs += rhs;
        return lhs;
        }

        /**
         * @brief Оператор вычитания для двух векторов
         * @param lhs Вектор слева от оператора
         * @param rhs Вектор справа от оператора
         * @return Новый вектор - результат вычитания
         */
        friend Vector3D operator-(Vector3D lhs, const Vector3D& rhs) {
        lhs -= rhs;
        return lhs;
        }

        /**
         * @brief Оператор умножения для двух векторов (скалярное произведение)
         * @param lhs Вектор слева от оператора
         * @param rhs Вектор справа от оператора
         * @return Новый вектор с результатом скалярного произведения во всех компонентах
         */
        friend Vector3D operator*(Vector3D lhs, const Vector3D& rhs) {
        lhs *= rhs;
        return lhs;
        }


        // Операторы сравнения (сравнивают длины векторов)

        /**
         * @brief Оператор меньше - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длина этого вектора меньше длины другого
         */
        bool operator<(const Vector3D& other) const {
        return this->vector_length() < other.vector_length();
        }

        /**
         * @brief Оператор больше - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длина этого вектора больше длины другого
         */
        bool operator>(const Vector3D& other) const {
        return this->vector_length() > other.vector_length();
        }

        /**
         * @brief Оператор меньше или равно - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длина этого вектора меньше или равна длине другого
         */
        bool operator<=(const Vector3D& other) const {
        return this->vector_length() <= other.vector_length();
        }

        /**
         * @brief Оператор больше или равно - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длина этого вектора больше или равна длине другого
         */
        bool operator>=(const Vector3D& other) const {
        return this->vector_length() >= other.vector_length();
        }

        /**
         * @brief Оператор равенства - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длины векторов равны
         */
        bool operator==(const Vector3D& other) const {
        return this->vector_length() == other.vector_length();
        }

        /**
         * @brief Оператор неравенства - сравнивает длины векторов
         * @param other Вектор для сравнения
         * @return True если длины векторов не равны
         */
         bool operator!=(const Vector3D& other) const {
        return this->vector_length() != other.vector_length();
        }
};

// Инициализация статической переменной-члена
int Vector3D::cnt = 0;


/**
 * @brief Отображает главное меню и получает выбор пользователя
 * @param choice Предыдущий выбор (не используется)
 * @return Выбор пользователя из меню
 */
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


/**
 * @brief Создает новый вектор на основе ввода пользователя
 * @return Новосозданный объект Vector3D
 * 
 * Позволяет пользователю выбрать между созданием вектора по координатам
 * или по двум точкам в пространстве.
 */
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



/**
 * @brief Отображает все векторы в коллекции
 * @param vectors Вектор объектов Vector3D для отображения
 */
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


/**
 * @brief Главная функция - точка входа в программу
 * @return Статус выхода (0 для успеха)
 * 
 * Предоставляет интерактивный интерфейс командной строки для операций с 3D векторами.
 * Пользователи могут создавать векторы, выполнять операции и просматривать результаты.
 */
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