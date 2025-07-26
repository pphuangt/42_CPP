#include "Sed.h"

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <search> <replace>"
                  << std::endl;
        return EXIT_FAILURE;
    }
    Sed sed(argv[1]);
    if (sed.fail()) {
        sed.errorMessage();
        return EXIT_FAILURE;
    }
    sed.searchAndReplace(argv[2], argv[3]);
    return EXIT_SUCCESS;
}
