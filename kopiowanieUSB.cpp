#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <string>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const char* sourceEnv = std::getenv("source");
    const char* destinationEnv = std::getenv("destination");

    if (!sourceEnv || !destinationEnv) {
        std::cerr << "Environment variables 'source' and/or 'destination' are not set!" << std::endl;
        return 1;
    }

    std::string source = sourceEnv;
    std::string destination = destinationEnv;

    // Check if the folders exist
    if (!std::filesystem::exists(source)) {
        std::cerr << "Source folder (" << source << ") does not exist!" << std::endl;
        return 1;
    }

    if (!std::filesystem::exists(destination)) {
        std::cerr << "Destination folder (" << destination << ") does not exist!" << std::endl;
        return 1;
    }

    std::cout << "Starting the copy process from '" << source << "' to '" << destination << "'..." << std::endl;

    // Create the xcopy command
    std::string command = "xcopy \"" + source + "\\*\" \"" + destination + "\\\" /E /I /Q /H /Y /C /R /K > nul 2>&1";

    // Run the xcopy command
    int result = std::system(command.c_str());

    if (result == 0) {
        std::cout << std::endl << "Copying completed successfully!" << std::endl;
    } else {
        std::cerr << "There was an issue during copying! Error code: " << result << std::endl;
    }

    std::cout << "Press Enter to finish...";
    std::cin.get();

    return 0;
}
