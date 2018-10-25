/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#include <cstdlib>
#include <RemoteControl.hh>
#include <string>
#include <RemoteControlException.hpp>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <zconf.h>
#include <iostream>
#include <vector>
#include <LineParser.hh>
#include "Client.hh"

Client::Client(std::string const &serverAddress, std::string const &userName)
{
    this->setUserName(userName);
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
    if (connect(this->getFd(), (struct sockaddr *) this->getAddr(), sizeof(*(this->getAddr()))) == -1)
        throw RemoteControlException(CONNECT_ERROR);
    if (dup2(this->getFd(), 0) == -1)
        throw RemoteControlException(DUP2_ERROR);
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

void Client::run()
{
    LineParser lineParser;
    std::string prompt = "\e[32m" + this->getUserName() + "~> " + "\e[39m";

    this->setRunningStatus(true);
    write(1, prompt.c_str(), prompt.length());
    while (this->getRunningStatus())
    {
        lineParser.getUserEntry();
        if (lineParser.getWords().size() == 2 && lineParser.getWords()[0] == "cd")
            chdir(lineParser.getWords()[1].c_str());
        else if (!lineParser.getLine().empty())
            system(lineParser.getLine().c_str());
        write(1, prompt.c_str(), prompt.length());
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

std::string const &Client::getUserName() const
{
    return this->userName;
}

void Client::setUserName(std::string const &userName)
{
    this->userName = userName;
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
