#ifndef SED_H
#define SED_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Sed {
private:
    std::ifstream _infile;
    std::ofstream _outfile;
    std::string _infileName;
    std::string _outfileName;
    int _infileErrno;
    int _outfileErrno;

public:
    Sed(const char* fileName);
    ~Sed();
    void searchAndReplace(const std::string& search,
                          const std::string& replace);
    bool fail() const;
    void errorMessage() const;
};

#endif
