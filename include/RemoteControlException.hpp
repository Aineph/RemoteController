/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#ifndef REMOTECONTROL_CLIENTEXCEPTION_HPP
#define REMOTECONTROL_CLIENTEXCEPTION_HPP

class RemoteControlException : public std::exception
{
private:
    std::string message;
public:
    RemoteControlException(std::string const &message) noexcept;

    RemoteControlException(RemoteControlException const &other) noexcept;

    ~RemoteControlException() noexcept;

    RemoteControlException &operator=(RemoteControlException const &other) noexcept;

    virtual const char *what(void) const noexcept;

    std::string const &getMessage() const;

    void setMessage(std::string const &message);
};


#endif //REMOTECONTROL_CLIENTEXCEPTION_HPP
