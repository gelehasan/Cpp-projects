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



bool CheckFileExistans(std::vector<std::string>& arrayFileNames, std::string filename) {

	return std::find(arrayFileNames.begin(), arrayFileNames.end(), filename) != arrayFileNames.end();
}
void writeToFile() {
	bool modyfyingFile = true;
	displayExistingFiles();
	std::string filename;
	std::cout << "Enter the file name you want to modify \n";
	std::cin >> filename;

	while (modyfyingFile) {
		if (CheckFileExistans(premadefileNames, filename)) {
			std::cout << "File exists";
			std::fstream currentFile(filename, std::ios::out | std::ios::in | std::ios::app);
			if (currentFile.is_open()) {
				std::string userinput;
				std::cout << "Enter text to add to the file or stop to exit";

				while (true) {
					std::getline(std::cin, userinput);
					if (userinput == "stop") {
						break;
					}
					currentFile << userinput;
				}
				

			}
		}
		else {
			std::cout << "File Doesn't exist";
		}

	}


 

}

void readFromFile() {

}

int main() {
	bool Stillcontinue = true;
	
	 

	showMenu();
	while (Stillcontinue) {
		int chosenvalue;
		std::cin >> chosenvalue;
	
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		}
		 
			switch (chosenvalue) {
			case 1:
				std::cout << "***Write to a file 1***\n";
				writeToFile();
				break;
			case 2:
				std::cout << "You have chosen 2\n";
				break;
			case 3:
				std::cout << "loop has ended\n";
				Stillcontinue = false;
				break;
			default:
				std::cout << "invalid value choose again\n";


			}
 
		 
	
	}
	 
 
	return 0;
}
