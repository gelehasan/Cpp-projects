#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <filesystem>


 
void showMenu() {
	std::vector < std::string > info= { "For creating a file click 1\n", "For writing to an existing file choose 2\n", "To see the contents of a file enter 3\n", "to quit write 4:\n" };
	
	for (int i = 0; i < info.size(); i++) {
		std::cout << info[i];

	}
}
std::vector<std::string> premadefileNames = { "example.txt", "example2.txt"};

void displayExistingFiles() {
	std::cout << "Existing files:\n";
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
	std::cin.ignore();

	while (modyfyingFile) {
		if (CheckFileExistans(premadefileNames, filename)) {
			std::cout << "File exists\n";
			std::fstream currentFile(filename, std::ios::out | std::ios::in | std::ios::app);
			if (currentFile.is_open()) {
				std::string userinput;
				std::cout << "Enter text to add to the file or stop to exit:\n";

				while (true) {
					std::getline(std::cin, userinput);
					if (userinput == "stop") {
						std::cout << "You have exited.\n";
						modyfyingFile = false;
						break;
					}
					currentFile << userinput;
				}
				

			}
		}
		else {
			std::cout << "File Doesn't exist.\n";
		}

	}


 

}

int readFromFile() {
	std::cin.ignore();
	std::string fileName;
	std::cout << "Enter the file you want to see it's content: ";
	std::getline(std::cin, fileName);

	
	if(std::filesystem::exists(fileName))
	{
		if(std::filesystem::file_size(fileName) == 0){
			std::cout << "\nFile is empty, nothing to read.\n"; 
			return 1;
		}

		std::ifstream file(fileName);
		std::string line;
		std::cout << "Contents of file " << fileName  << ":\n";
		while(std::getline(file, line))
		{
			std::cout << line << '\n';
		}
		}
		else
		{
			std::cout << "\nFile doesn't exist.\n"; return 1;
		}

		return 0;
}

int main() {
	bool Stillcontinue = true;
	
	 

	while (Stillcontinue) {
		showMenu();
		int chosenvalue;
		std::string input;
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
				readFromFile();
				break;
			case 4:
				std::cout << "loop has ended\n";
				Stillcontinue = false;
				break;
			default:
				std::cout << "invalid value choose again\n";


			}
 
		 
	
	}
	 
 
	return 0;
}
