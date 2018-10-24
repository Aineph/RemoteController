/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#include <exception>
#include <string>
#include "RemoteControlException.hpp"

RemoteControlException::RemoteControlException(std::string const &message) noexcept
{
    this->setMessage(message);
}

RemoteControlException::RemoteControlException(RemoteControlException const &other) noexcept
{
    this->setMessage(other.getMessage());
}

RemoteControlException::~RemoteControlException() noexcept
{
}

RemoteControlException &RemoteControlException::operator=(RemoteControlException const &other) noexcept
{
    if (this != &other)
        this->setMessage(other.getMessage());
    return *this;
}

char const *RemoteControlException::what() const noexcept
{
    return this->getMessage().c_str();
}

std::string const &RemoteControlException::getMessage() const
{
    return this->message;
}

void RemoteControlException::setMessage(std::string const &message)
{
    this->message = message;
}