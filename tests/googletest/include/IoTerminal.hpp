#ifndef IO_TERMINAL_HPP
# define IO_TERMINAL_HPP

#include "CaptureFd.hpp"
# include <string>

/**
 * ！！！注意！！！
 * 現在は、複数のインスタンスを同時にbootすると挙動がおかしくなり、
 * 入出力を正しくもとに戻せない可能性があります。
 * 必ず、instance1.boot
 *  -> instance1.exit
 *  -> instance2.boot
 *  -> instance2.exit とするようにしてください。
 */
class IoTerminal
{
    // variables
    public:
    private:
        bool isBooted;
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
