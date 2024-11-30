#ifndef IO_TERMINAL_HPP
# define IO_TERMINAL_HPP

#include "CaptureFd.hpp"
# include <string>

class IoTerminal
{
    // variables
    public:
    private:
        CaptureFd stdoutCFd;
        CaptureFd stderrCFd;
        std::string stdoutBuf;
        std::string stderrBuf;
    // functions
    public:
        // special member functions
        IoTerminal(void); // default constructor
        ~IoTerminal(void); // destructor
        // operators
        // others
        void boot(void);
        void exit(void);
        std::string getStdout(void);
        std::string getStderr(void);
    private:
};

#endif
