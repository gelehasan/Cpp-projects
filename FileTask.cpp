#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
 
void showMenu() {
	std::vector < std::string > info= { "For creating a file click 1\n", "For writing to an existing file choose 2\n", "to quit write 3\n" };
	
	for (int i = 0; i < info.size(); i++) {
		std::cout << info[i];

	}
}
std::vector<std::string> premadefileNames = { "example.txt", "example2.txt"};

void displayExistingFiles() {
	std::cout << "Existing files\n";
	for (int i = 0; i < premadefileNames.size(); i++) {
		std::cout << premadefileNames[i] << "\n";
	}
}
