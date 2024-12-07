#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <fstream>

int main() {
    // Ścieżka źródłowa
    std::string source = "C:\\Twoja sciezka";

    // Ścieżka docelowa (dysk USB)
    std::string destination = "daj tutaj litere twojego USB:\\";  // Użyj podwójnych ukośników

    // Sprawdzanie, czy dysk USB istnieje
    if (!std::filesystem::exists(destination)) {
        std::cerr << "np.E doesn't exist!" << std::endl;
        return 1;
    }

    // Sprawdzanie, czy folder źródłowy istnieje
    if (!std::filesystem::exists(source)) {
         std::cerr << "Source folder (C:\\Twoja sciezka) does not exist!" << std::endl;
        return 1;
    }

    std::cout << "Starting copying files from 'twoja sciezka' to 'np. E'" << std::endl;

    // Konstrukcja polecenia xcopy z przekierowaniem błędów do nul
    std::string command = "xcopy \"" + source + "\\\" \"" + destination + "\" /E /I /Q /H /Y /C /R /K > nul 2>&1";

    // Wykonanie polecenia
    int result = std::system(command.c_str());

    // Sprawdzanie, czy polecenie się powiodło
    if (result == 0) {
        std::cout << "Copying finished successfully!" << std::endl;
    } else {
        std::cerr << "There was a problem during copying! Error code: " << result << std::endl;
    }

    return 0;
}
