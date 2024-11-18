#ifndef CAPTURE_FD_HPP
# define CAPTURE_FD_HPP

# include <string>

class CaptureFd
{
    // variables
    private:
        bool isCaptured;
        int targetFd;
        int pipedFd[2];
        int storedFd;
    // functions
    public:
        // special member functions
        CaptureFd(void); // default constructor
        CaptureFd(const CaptureFd& captureFd); // copy constructor
        ~CaptureFd(void); // destructor
        int capture(int fd);
        int unCapture(void);
        std::string read(void);
        // operators
        CaptureFd& operator=(const CaptureFd& captureFd); // operator=
        // others
    private:
};

#endif
