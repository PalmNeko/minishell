#include "CaptureFd.hpp"
#include <string>
#include <cstring>

extern "C" {
    #include "ms_test.h"
    #include <unistd.h>
}

/*
 * special member functions
 */
CaptureFd::CaptureFd(void)
    : isCaptured(false)
{}

CaptureFd::~CaptureFd(void)
{
    this->unCapture();
}

int CaptureFd::capture(int fd)
{
    if (this->isCaptured == true)
        return (-1);
    this->targetFd = fd;
    if (ms_capture(this->targetFd, this->pipedFd, &this->storedFd) == -1)
        return (-1);
    this->isCaptured = true;
    return (0);
}

int CaptureFd::unCapture(void)
{
    if (this->isCaptured == false)
        return (-1);
    ms_uncapture(this->targetFd, this->pipedFd, &this->storedFd);
    this->isCaptured = false;
    return (0);
}
std::string CaptureFd::read(void)
{
    std::string str;
    char        buf[1024];
    int         read_size;

    if (this->isCaptured == false)
        return ("");
    read_size = ::read(this->pipedFd[0], buf, 1023);
    while (read_size != -1)
    {
        buf[read_size] = '\0';
        str += buf;
        read_size = ::read(this->pipedFd[0], buf, 1023);
    }
    return (str);
}

/*
 * operators
 */
CaptureFd& CaptureFd::operator=(CaptureFd& captureFd)
{
    if (this != &captureFd)
    {
        this->isCaptured = captureFd.isCaptured;
        this->targetFd = captureFd.targetFd;
        memmove(this->pipedFd, captureFd.pipedFd, sizeof(this->pipedFd));
        this->storedFd = captureFd.storedFd;
        captureFd.isCaptured = -1;
        captureFd.targetFd = -1;
        captureFd.pipedFd[0] = -1;
        captureFd.pipedFd[1] = -1;
        captureFd.storedFd = -1;
    }
    return *this;
}

/*
 * others: public
 */

/*
 * others: private
 */
