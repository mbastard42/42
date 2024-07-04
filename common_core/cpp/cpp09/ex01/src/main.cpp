#include <stack>
#include <iostream>

int main(int ac, char **av) {

    double tmp1;
    double tmp2;
    std::stack<double> stack;

    if (ac == 2) {
        for (int i = 0; av[1][i] ; i++) {
            if (strchr("0123456789 +-/*", av[1][i])) {
                if (strchr("0123456789", av[1][i]) && stack.size() < 3)
                    stack.push(av[1][i] - 48);
                else if (strchr("+-/*", av[1][i]) && stack.size() > 1) {
                    tmp2 = stack.top();
                    stack.pop();
                    tmp1 = stack.top();
                    stack.pop();
                    switch (av[1][i]) {
                        case '-':
                            stack.push(tmp1 - tmp2); break;
                        case '+':
                            stack.push(tmp1 + tmp2); break;
                        case '/':
                            stack.push(tmp1 / tmp2); break;
                        case '*':
                            stack.push(tmp1 * tmp2); break;
                    }
                } else if (av[1][i] != ' ') {
                    std::cout << "Error" << std::endl;
                    return 0;
                }
            } else { std::cout << "Error" << std::endl; return 0; }
        }
        std::cout << stack.top() << std::endl;
        stack.pop();
    } else { std::cout << "Wrong number of arguments" << std::endl; }
    return 0;
}