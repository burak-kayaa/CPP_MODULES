#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "Error\n";
        return 1;
    }
    RPN rpn;

    rpn.run(av[1]);
}