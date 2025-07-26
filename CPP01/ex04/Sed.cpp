#include "Sed.h"

Sed::Sed(const char* fileName)
    : _infileName(fileName), _outfileName(_infileName + ".replace"),
      _infileErrno(0), _outfileErrno(0)
{
    _infile.open(_infileName.c_str(), std::ifstream::in);
    if (!_infile.is_open()) {
        _infileErrno = errno;
        return;
    }
    _outfile.open(_outfileName.c_str(),
                  std::ofstream::out | std::ofstream::trunc);
    if (!_outfile.is_open()) {
        _outfileErrno = errno;
        return;
    }
}

Sed::~Sed()
{
    if (_infileErrno == 0) _infile.close();
    if (_outfileErrno == 0) _outfile.close();
}

bool Sed::fail() const
{
    return _infileErrno != 0 || _outfileErrno != 0;
}

void Sed::errorMessage() const
{
    if (_infileErrno != 0) {
        std::cerr << _infileName + ": " + strerror(_infileErrno) << '\n';
    }
    if (_outfileErrno != 0) {
        std::cerr << _outfileName + ": " + strerror(_outfileErrno) << '\n';
    }
}

void Sed::searchAndReplace(const std::string& search,
                           const std::string& replace)
{
    std::string result;
    std::stringstream buffer;

    buffer << _infile.rdbuf();
    std::string content = buffer.str();
    if (!search.empty()) {
        size_t start = 0;
        size_t end = 0;
        while ((end = content.find(search, end)) != std::string::npos) {
            result.append(content, start, end - start);
            result.append(replace);
            end += search.length();
            start = end;
        }
        result.append(content, start);
    }
    _outfile << result;
}