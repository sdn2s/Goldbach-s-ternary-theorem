#include <iostream>
#include <vector>
#include <cmath>

// Функция для проверки простоты числа
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Функция для нахождения всех простых чисел до n
std::vector<int> generate_primes(int n) {
    std::vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Функция для проверки тернарной теоремы Гольдбаха
bool check_goldbach_ternary(int n) {
    if (n <= 5 || n % 2 == 0) return false; // Только для нечётных чисел > 5

    std::vector<int> primes = generate_primes(n);

    // Перебор всех комбинаций простых чисел
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            for (int k = j; k < primes.size(); ++k) {
                if (primes[i] + primes[j] + primes[k] == n) {
                    std::cout << n << " = " << primes[i] << " + " << primes[j] << " + " << primes[k] << std::endl;
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main() {
    int number;
    std::cout << "Введите нечётное число больше 5 для проверки тернарной теоремы Гольдбаха: ";
    std::cin >> number;

    if (number % 2 == 0 || number <= 5) {
        std::cout << "Число должно быть нечётным и больше 5!" << std::endl;
        return 1;
    }

    if (check_goldbach_ternary(number)) {
        std::cout << "Тернарная теорема Гольдбаха выполнена для числа " << number << std::endl;
    } else {
        std::cout << "Тернарная теорема Гольдбаха не выполнена для числа " << number << std::endl;
    }

    return 0;
}
