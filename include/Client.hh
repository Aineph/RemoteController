/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#ifndef REMOTECONTROL_CLIENT_HH
#define REMOTECONTROL_CLIENT_HH


class Client
{
private:
    struct sockaddr_in *addr;
    std::string serverAddress;
    std::string userName;
    int fd;
    bool runningStatus;

public:
    Client(std::string const &serverAddress, std::string const &userName);

    Client(Client const &other);

    ~Client();

    Client operator=(Client const &other);

    void run();

    struct sockaddr_in *getAddr() const;

    void setAddr(struct sockaddr_in *addr);

    std::string const &getUserName() const;

    void setUserName(std::string const &userName);

    std::string const &getServerAddress() const;

    void setServerAddress(std::string const &address);

    const int getFd() const;

    void setFd(const int fd);

    const bool getRunningStatus() const;

    void setRunningStatus(const bool runningStatus);
};


#endif //REMOTECONTROL_CLIENT_HH
