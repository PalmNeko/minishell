#ifndef I_IO_CAPTURE_HPP
# define I_IO_CAPTURE_HPP

# include <string>

class IIoCapture
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        virtual ~IIoCapture(void) = 0; // destructor
        // operators
        // others
        virtual void boot(void) = 0;
        virtual void exit(void) = 0;
        virtual bool isCapturing(void) = 0;
    private:
};

#endif
