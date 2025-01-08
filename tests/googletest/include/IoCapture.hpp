#ifndef IO_CAPTURE_HPP
# define IO_CAPTURE_HPP

#include "CaptureFd.hpp"
# include "IIoCapture.hpp"
# include <string>

extern "C" {
    # include <unistd.h>
}

/**
 * ！！！注意！！！
 * 現在は、複数のインスタンスを同時にbootすると挙動がおかしくなり、
 * 入出力を正しくもとに戻せない可能性があります。
 * 必ず、instance1.boot
 *  -> instance1.exit
 *  -> instance2.boot
 *  -> instance2.exit とするようにしてください。
 */
class IoCapture : public IIoCapture
{
    // variables
    public:
    private:
        bool isBooted;
        int status;
        pid_t pid;
        CaptureFd stdoutCFd;
        CaptureFd stderrCFd;
        std::string stdoutBuf;
        std::string stderrBuf;
    // functions
    public:
        // special member functions
        IoCapture(void); // default constructor
        ~IoCapture(void); // destructor
        // operators
        IoCapture& operator=(IoCapture& ioCapture);
        // others
        void boot(void);
        void exit(void);
        bool isCapturing(void);
        int getStatus(void);
        std::string getStdout(void);
        std::string getStderr(void);
    private:
};

#endif
