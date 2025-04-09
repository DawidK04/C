#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

struct Threshold {
    int id;
    std::string firstName;
    std::string lastName;
    float score;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Threshold, id, firstName, lastName, score)
};

void dump(std::vector<Threshold> &v) {
    std::ofstream t("1.json");

    json data = v;
    t << data.dump() << std::endl;
}

void parse(std::vector<Threshold> &v) {
    std::ifstream t("data.json");
    std::stringstream buffer;
    buffer << t.rdbuf();
    //std::string str = buffer.str();
    json data = json::parse(buffer.str());

    v = data;

    for (const auto &item : v)
    {
        std::cout << "ID: " << item.id << ", Name: " << item.firstName << ", Last name: " << item.lastName << ", Score: " << item.score << std::endl;
    }
}

int main()
{
    std::vector<Threshold> v;
    parse(v);
    dump(v);
    return 0;
}
