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
    explicit RemoteControlException(std::string const &message) noexcept;

    RemoteControlException(RemoteControlException const &other) noexcept;

    virtual ~RemoteControlException() noexcept;

    RemoteControlException &operator=(RemoteControlException const &other) noexcept;

    virtual const char *what() const noexcept;

    std::string const &getMessage() const;

    void setMessage(std::string const &message);
};


#endif //REMOTECONTROL_CLIENTEXCEPTION_HPP
