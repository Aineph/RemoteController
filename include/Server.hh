/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#ifndef REMOTECONTROL_SOCKET_HPP
#define REMOTECONTROL_SOCKET_HPP

class Server
{
private:
    struct sockaddr_in *addr;
    int fd;
    int currentTarget;
    bool runningStatus;
    std::map<std::string, int> clients;

    static void acceptConnections(Server *server);

    static void readContent(Server *server);

    bool processEntry(std::string &command);

    static void clientHandler(Server *server, struct sockaddr client, int clientFd);

public:

    typedef void (*Command)(std::vector<std::string>, Server *);

    Server();

    Server(Server const &other);

    ~Server();

    Server &operator=(Server const &other);

    bool run();

    void addClient(std::string const &ip, const int fd);

    struct sockaddr_in *getAddr() const;

    void setAddr(struct sockaddr_in *addr);

    const int getFd() const;

    void setFd(const int fd);

    const bool getRunningStatus() const;

    void setRunningStatus(const bool runningStatus);

    std::map<std::string, int> const &getClients() const;

    void setClients(std::map<std::string, int> const &clients);

    const int getCurrentTarget() const;

    void setCurrentTarget(const int currentTarget);

};


#endif //REMOTECONTROL_SOCKET_HPP
