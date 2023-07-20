#include <iostream>
#include <vector>

bool canSurviveChakravyuh(const std::vector<int>& enemyPower, int power, int skips, int recharges) {
    int currentCircle = 0;
    int powerRegained = 0;
    while (currentCircle < enemyPower.size()) {
        int requiredPower = enemyPower[currentCircle];

        // special cases for enemies k3 and k7
        if (currentCircle == 2 || currentCircle == 6) {
            requiredPower += enemyPower[currentCircle] / 2;
        }

        if (power >= requiredPower) {
            power -= requiredPower;
        } else {
            if (skips > 0) {
                --skips;
            } else if (recharges > 0 && powerRegained > 0) {
                power += powerRegained;
                --recharges;
            } else {
                return false;  // not enough power and no skips or recharges left
            }
        }
        ++currentCircle;
    }
    return true;
}

int main() {
    std::vector<int> test1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    std::vector<int> test2 = {5, 10, 15, 20, 25, 30, 35, 40, 450, 50, 55};

    std::cout << (canSurviveChakravyuh(test1, 1000, 3, 2) ? "Yes" : "No") << std::endl;
    std::cout << (canSurviveChakravyuh(test2, 500, 0, 3) ? "Yes" : "No") << std::endl;

    return 0;
}