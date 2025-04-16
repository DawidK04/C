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

std::string grade(float score) {
    if (score >= 90) {
        return "5";
    }
    else if (score >= 80) {
        return "4+";
    }
    else if (score >= 70) {
        return "4";
    }
    else if (score >= 60) {
        return "3+";
    }
    else if (score >= 50) {
        return "3";
    }
    else {
        return "2";
    }
}



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
        std::cout << "ID: " << item.id << ", Name: " << item.firstName << ", Last name: " << item.lastName << ", Score: " << item.score << ", Grade: " << grade(item.score) << std::endl;
    }
}

void findID(std::vector<Threshold>& v, int id) {
    auto it = std::find_if(v.begin(), v.end(), [id](Threshold& v) {
        return v.id == id
    });
    
}

int main()
{
    std::vector<Threshold> v;
    parse(v);

    std::sort(v.begin(), v.end(), [](Threshold& a, Threshold& b) {
        return a.lastName > b.lastName;
    });
    for (const auto &item : v)
    {
        std::cout << "ID: " << item.id << ", Name: " << item.firstName << ", Last name: " << item.lastName << ", Score: " << item.score << ", Grade: " << grade(item.score) << std::endl;
    }

    dump(v);
    return 0;
}
