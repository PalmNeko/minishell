#include "IoTerminal.hpp"

/*
 * special member functions
 */
IoTerminal::IoTerminal(void)
{}

IoTerminal::~IoTerminal(void)
{
    this->exit();
}

/*
 * operators
 */

/*
 * others: public
 */
void IoTerminal::boot(void)
{
    this->stdoutCFd.capture(1);
    this->stderrCFd.capture(2);
}

void IoTerminal::exit(void)
{
    this->getStderr();
    this->getStdout();
    this->stdoutCFd.unCapture();
    this->stderrCFd.unCapture();
}

std::string IoTerminal::getStdout(void)
{
    this->stdoutBuf += this->stdoutCFd.read();
    return (this->stdoutBuf);
}

std::string IoTerminal::getStderr(void)
{
    this->stderrBuf += this->stderrCFd.read();
    return (this->stderrBuf);
}

/*
 * others: private
 */
