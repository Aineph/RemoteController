/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#ifndef REMOTECONTROL_SERVERCOMMAND_HH
#define REMOTECONTROL_SERVERCOMMAND_HH

class ServerCommand
{
public:
    typedef void (*Command)(std::vector<std::string> const&, Server *);

private:
    std::string commandName;

    Command command;

public:
    ServerCommand();

    explicit ServerCommand(std::string const &commandName, Command command);

    ServerCommand(ServerCommand const &other);

    virtual ~ServerCommand();

    ServerCommand &operator=(ServerCommand const &other);

    void operator()(std::vector<std::string> const &arguments, Server *server) const;

    static void execute(std::vector<ServerCommand> const &commands, LineParser lineParser, Server *server);

    static void list(std::vector<std::string> const &arguments, Server *server);

    static void attack(std::vector<std::string> const &arguments, Server *server);

    static void exit(std::vector<std::string> const &arguments, Server *server);

    std::string const &getCommandName() const;

    void setCommandName(std::string const &commandName);

    Command getCommand() const;

    void setCommand(Command command);
};


#endif //REMOTECONTROL_SERVERCOMMAND_HH
