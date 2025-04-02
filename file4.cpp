#include <string>
#include <chrono>
#include <iostream>
#include <vector>

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
    const int iterations = 1000000;
{
		TimeMeasurement t("Krótka pętla");
        std::vector<int> container;
		for (int i = 0; i < iterations; i++) {
            container.insert(container.begin(), 123456);
        }
	}

	{
		TimeMeasurement t("Długa pętla");
        std::vector<int> container;
		for (int i = 0; i < iterations; i++) {
            container.insert(container.begin(), 123456);
        }
	}

	return 0;
}
