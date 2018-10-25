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
    RemoteControlException(std::string const &message) throw();

    RemoteControlException(RemoteControlException const &other) throw();

    ~RemoteControlException() throw();

    RemoteControlException &operator=(RemoteControlException const &other) throw();

    virtual const char *what(void) const throw();

    std::string const &getMessage() const;

    void setMessage(std::string const &message);
};


#endif //REMOTECONTROL_CLIENTEXCEPTION_HPP
