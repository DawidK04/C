#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class Firma {
public:
    std::string name;
    std::string nip;
    std::string date;
    std::string mail;

    Firma(const std::string &_name,
          const std::string &_nip,
          const std::string &_date,
          const std::string &_mail)
        : name(_name), nip(_nip), date(_date), mail(_mail)
    {
        if (name.length() < 3 || name.length() > 100) {
            throw std::length_error("Error: Company name must be between 3 and 100 characters long");
        }

        if (nip.length() != 10) {
            throw std::length_error("Error: NIP must consist of exactly 10 digits");
        }
        for (char c : nip) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                throw std::invalid_argument("Error: NIP can only contain numbers");
            }
        }

        if (date.length() != 10) {
            throw std::length_error("Error: date must be in YYYY-MM-DD format (10 characters)");
        }
        if (date[4] != '-' || date[7] != '-') {
            throw std::invalid_argument("Error: date must be in YYYY-MM-DD format ('-' characters in positions 5 and 8)");
        }
        for (std::size_t i = 0; i < date.length(); ++i) {
            if (i == 4 || i == 7) continue;
            if (!std::isdigit(static_cast<unsigned char>(date[i]))) {
                throw std::invalid_argument("Error: Date must be numeric in YYYY-MM-DD format");
            }
        }
        if (mail.find('@') == std::string::npos) {
            throw std::invalid_argument("Error: Email address must contain the '@' character");
        }
    }
};

int main() {
    try {
        Firma mojaFirma(
            "Nazwa Firmy",
            "1234567890",
            "2025-04-23",
            "nazwa@gmail.com"
        );
        std::cout << "The Firma object was created successfully." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


