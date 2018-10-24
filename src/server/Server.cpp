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
#include <ServerCommand.hh>
#include "RemoteControlException.hpp"
#include "RemoteControl.hh"
#include "Server.hh"

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
    if (bind(this->getFd(), (struct sockaddr *) this->getAddr(), sizeof(*(this->getAddr()))))
        throw RemoteControlException(std::string(BIND_ERROR));
    if (listen(this->getFd(), REMOTECONTROL_BACKLOG) == -1)
        throw RemoteControlException(std::string(LISTEN_ERROR));
    this->target = -1;
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
        free(this->addr);
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
        if (server->getTarget() > 0)
        {
            FD_ZERO(&set);
            FD_SET(server->getTarget(), &set);
            if (select(server->getTarget() + 1, &set, NULL, NULL, &timeout) > 0)
            {
                if ((ret = read(server->getTarget(), buf, 4096)) > 0)
                {
                    buf[ret] = '\0';
                    mutex.lock();
                    write(1, buf, strlen(buf));
                    mutex.unlock();
                }
            }
        }
    }
    close(server->getTarget());
}

/*bool Server::processEntry(std::string &command)
{
    std::vector<std::string> words;
    std::string word = "";
    std::stringstream stream(command);
    std::vector<ServerCommand>::const_iterator iterator;

    while (stream >> word)
    {
        words.push_back(word);
    }
    if (words.size() > 0)
        for (iterator = this->commands.begin(); iterator != this->commands.end(); iterator++)
        {
            if (!(*iterator).getCommandName().compare(words[0]))
                (*iterator)(words, this);
        }
    else if (this->getTarget() != -1)
    {
        command += "\n";
        write(this->getTarget(), command.c_str(), command.length());
    }
    return true;
}*/

bool Server::run()
{
    RemoteController remoteController;
    std::map<std::string, ServerCommand>
    LineParser lineParser;
    std::thread acceptingThread(acceptConnections, this);
    std::thread clientReader(readContent, this);

    this->setRunningStatus(true);
    acceptingThread.detach();
    clientReader.detach();
    while (this->getRunningStatus())
    {
        std::cout << REMOTECONTROL_PROMPT;
        lineParser.getUserEntry();
//        this->processEntry(command);
    }
    return true;
}

void Server::addClient(std::string const &ip, const int fd)
{
    this->clients[ip] = fd;
}

void Server::list(std::vector<std::string>, Server *server)
{
    std::map<std::string, int>::const_iterator iterator;
    int i = 0;

    for (iterator = server->getClients().begin(); iterator != server->getClients().end(); iterator++)
    {
        std::cout << "Client n° " << i++ << ": " << iterator->first << std::endl;
    }
}

void Server::exit(std::vector<std::string>, Server *server)
{
    server->setRunningStatus(false);
}

void Server::acceptConnections(Server *server)
{
    struct sockaddr_in client;
    size_t clientLength;
    int clientFd = -1;
    std::mutex mutex;

    while (server->getRunningStatus())
    {
        clientLength = sizeof(client);
        bzero(&client, clientLength);
        if ((clientFd = accept(server->getFd(), (struct sockaddr *) &client, (socklen_t *) &clientLength)) >= 0)
        {
            mutex.lock();
            server->addClient(std::string(inet_ntoa(client.sin_addr)), clientFd);
            if (server->getTarget() == -1)
            {
                write(1, "\nLa cible a été mise à jour.\n", strlen("\nLa cible a été mise à jour.\n"));
                server->setTarget(clientFd);
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

const int Server::getTarget() const
{
    return this->target;
}

void Server::setTarget(const int target)
{
    this->target = target;
}