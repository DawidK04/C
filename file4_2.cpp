#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <list>

class TimeMeasurement {
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        TimeMeasurement(std::string _name) : name(_name) {
		start = std::chrono::high_resolution_clock::now();
        }

    ~TimeMeasurement() {
		std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;
		std::cout << name << ": " << duration.count() << " sec" << std::endl;
	}
};

int main() {
    const int N = 1000000;
{
        std::vector<int> vec;
        vec.reserve(N);
		for (int i = 0; i < N; i++) {
            vec.push_back(i);

		TimeMeasurement t("Krótka pętla");
	}

	{
        std::list<int> lst;
		for (int i = 0; i < N; i++) {
            lst.push
        }

		TimeMeasurement t("Długa pętla");
	}

	return 0;
}
