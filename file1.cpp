#include <iostream>

int main(int argc, char *argv[]) {
    int option;

    do {
        std::cout << "Menu\n";
        std::cout << "1. Print the number of program arguments\n";
        std::cout << "2. Print the selected program argument\n";
        std::cout << "3. Print all program arguments\n";
        std::cout << "4. End the program\n";
        std::cout << "Select the option";
        std::cin >> option;

        switch(option) {
            case 1: {
                std::cout << "Number of program arguments: " << argc << std::endl;
                break;
            }
            case 2: {
                int number;
                std::cout << "Input the argument number od 0 do " << argc - 1 << ": ";
                std::cin >> number;
                if(number >= 0 && number < argc) {
                    std::cout << "Argument " << number << ": " << argv[number] << std::endl;
                } else {
                    std:cerr << "Error: invalid argument number." << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "All program arguments\n";
                for (int i = 0; i < argc; ++i) {
                    std::cout << "Argument " << i <<
                }
            }

        }
    }
}