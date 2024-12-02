#include "CaptureFd.hpp"
#include "IoCapture.hpp"
#include <cstdlib>

extern "C" {
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
    #include <fcntl.h>
}
/*
 * special member functions
 */
IoCapture::IoCapture(void)
    : isBooted(false),
    status(-1)
{}

IoCapture::~IoCapture(void)
{
    if (this->isBooted == true)
        this->exit();
}

/*
 * operators
 */
IoCapture& IoCapture::operator=(IoCapture& ioCapture)
{
    if (this != &ioCapture)
    {
        this->isBooted = ioCapture.isBooted;
        this->stdoutCFd = ioCapture.stdoutCFd;
        this->stderrCFd = ioCapture.stderrCFd;
        this->stdoutBuf = ioCapture.stdoutBuf;
        this->stderrBuf = ioCapture.stderrBuf;
        ioCapture.isBooted = false;
        ioCapture.stdoutBuf = "";
        ioCapture.stderrBuf = "";
    }
    return *this;
}

/*
 * others: public
 */
void IoCapture::boot(void)
{
    if (this->isBooted == true)
        return ;
    this->stdoutCFd.capture(1);
    this->stderrCFd.capture(2);
    this->isBooted = true;
    this->pid = fork();
    if (this->pid == -1)
        this->exit();
}

void IoCapture::exit(void)
{
    if (this->isBooted == false && this->pid != -1)
        return ;
    if (pid == 0) {
        printf("wefuysdf\n");
        ::exit(0);
    }
    this->isBooted = false;

    int status;
    waitpid(this->pid, &status, 0);
    while (!WIFEXITED(status) && !WIFSIGNALED(status))
        waitpid(this->pid, &status, 0);
    if (WIFEXITED(status))
        this->status = WEXITSTATUS(status);
    else
        this->status = WTERMSIG(status);
    if (pid > 0)
    {
        this->getStderr();
        this->getStdout();
    }
    this->stdoutCFd.unCapture();
    this->stderrCFd.unCapture();
}
bool IoCapture::isCapturing(void)
{
    return this->isBooted && pid == 0;
};

int IoCapture::getStatus(void)
{
    return this->status;
}

std::string IoCapture::getStdout(void)
{
    this->stdoutBuf += this->stdoutCFd.read();
    return (this->stdoutBuf);
}

std::string IoCapture::getStderr(void)
{
    this->stderrBuf += this->stderrCFd.read();
    return (this->stderrBuf);
}

/*
 * others: private
 */
