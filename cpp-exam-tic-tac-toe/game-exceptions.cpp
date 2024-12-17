#include <exception>
#include <string>

class IllegalMoveException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Illegal move attempted!";
    }
};

class IllegalBoardConfigurationException : public std::exception
{
private:
    std::string msg;

public:
    IllegalBoardConfigurationException(const std::string &message = "Illegal board configuration!")
        : msg(message) {}

    const char *what() const noexcept override
    {
        return msg.c_str();
    }
};
