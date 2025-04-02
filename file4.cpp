#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

// Struktura reprezentująca produkt
struct Product {
    std::string name;
    double price;
    int quantity;
};

// Funkcja do wczytywania produktów z pliku
void loadProducts(const std::string &filename, std::vector<Product> &products) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Nie udało się otworzyć pliku " << filename << ". Rozpoczynam od pustej listy.\n";
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        Product p;
        if (!(iss >> std::ws) || std::getline(iss, p.name, '\t').fail()) {
            continue; // pomijamy źle sformatowane linie
        }
        // Usunięcie ewentualnych zbędnych spacji w nazwie
        if(p.name.empty())
            continue;
        if (!(iss >> p.price >> p.quantity)) {
            continue;
        }
        products.push_back(p);
    }
    infile.close();
}

// Funkcja zapisująca produkty do pliku
void saveProducts(const std::string &filename, const std::vector<Product> &products) {
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Nie udało się otworzyć pliku " << filename << " do zapisu.\n";
        return;
    }
    for (const auto &p : products) {
        // Zapisujemy w formacie: nazwa<tab>cena<tab>ilość
        outfile << p.name << "\t" << p.price << "\t" << p.quantity << "\n";
    }
    outfile.close();
}

// Funkcja wyświetlająca listę produktów
void displayProducts(const std::vector<Product> &products) {
    std::cout << "\nLista produktów:\n";
    std::cout << "-----------------------------------\n";
    for (const auto &p : products) {
        std::cout << "Nazwa: " << p.name << "\tCena: " << p.price << "\tIlość: " << p.quantity << "\n";
    }
    std::cout << "-----------------------------------\n";
}

// Funkcja dodająca nowy produkt
void addProduct(std::vector<Product> &products) {
    Product p;
    std::cout << "Podaj nazwę produktu: ";
    std::getline(std::cin >> std::ws, p.name);
    if(p.name.empty()){
        std::cout << "Nazwa nie może być pusta!\n";
        return;
    }
    std::cout << "Podaj cenę jednostkową: ";
    std::cin >> p.price;
    if(std::cin.fail() || p.price < 0) {
        std::cout << "Cena musi być liczbą nieujemną!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "Podaj ilość: ";
    std::cin >> p.quantity;
    if(std::cin.fail() || p.quantity < 0) {
        std::cout << "Ilość musi być liczbą całkowitą nieujemną!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    products.push_back(p);
    std::cout << "Produkt został dodany.\n";
    // Czyszczenie bufora wejścia
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Funkcja usuwająca produkt
void removeProduct(std::vector<Product> &products) {
    std::cout << "Podaj nazwę produktu do usunięcia: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    bool found = false;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->name == name) {
            products.erase(it);
            std::cout << "Produkt usunięty.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Nie znaleziono produktu o nazwie: " << name << "\n";
    }
}

// Funkcja zmieniająca ilość produktu
void updateQuantity(std::vector<Product> &products) {
    std::cout << "Podaj nazwę produktu do zmiany ilości: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    bool found = false;
    for (auto &p : products) {
        if (p.name == name) {
            std::cout << "Aktualna ilość: " << p.quantity << "\n";
            std::cout << "Podaj nową ilość: ";
            int newQuantity;
            std::cin >> newQuantity;
            if(std::cin.fail() || newQuantity < 0) {
                std::cout << "Ilość musi być liczbą całkowitą nieujemną!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return;
            }
            p.quantity = newQuantity;
            std::cout << "Ilość została zaktualizowana.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Nie znaleziono produktu o nazwie: " << name << "\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Funkcja wyszukująca produkt po nazwie
void searchProduct(const std::vector<Product> &products) {
    std::cout << "Podaj nazwę produktu do wyszukania: ";
    std::string name;
    std::getline(std::cin >> std::ws, name);
    bool found = false;
    for (const auto &p : products) {
        if (p.name.find(name) != std::string::npos) {
            std::cout << "Znaleziono produkt: " << p.name << "\tCena: " << p.price << "\tIlość: " << p.quantity << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Nie znaleziono produktu zawierającego: " << name << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::vector<Product> products;
    // Określenie nazwy pliku - argv[1] lub domyślnie "magazyn.txt"
    std::string filename = (argc > 1) ? argv[1] : "magazyn.txt";

    loadProducts(filename, products);

    bool running = true;
    while (running) {
        std::cout << "\n--- Menu ---\n"
                  << "1. Wyświetl spis produktów\n"
                  << "2. Dodaj produkt\n"
                  << "3. Usuń produkt\n"
                  << "4. Zmień ilość produktu\n"
                  << "5. Wyszukaj produkt po nazwie\n"
                  << "6. Zakończ program\n"
                  << "Wybierz opcję: ";
        int choice;
        std::cin >> choice;
        if(std::cin.fail()){
            std::cout << "Wprowadzono niepoprawną wartość. Spróbuj ponownie.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(choice) {
            case 1:
                displayProducts(products);
                break;
            case 2:
                addProduct(products);
                break;
            case 3:
                removeProduct(products);
                break;
            case 4:
                updateQuantity(products);
                break;
            case 5:
                searchProduct(products);
                break;
            case 6:
                running = false;
                break;
            default:
                std::cout << "Niepoprawna opcja. Wybierz ponownie.\n";
        }
    }

    saveProducts(filename, products);
    std::cout << "Dane zapisane w pliku " << filename << ". Do widzenia!\n";
    return 0;
}
