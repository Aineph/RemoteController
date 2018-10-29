/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 29/10/2018.
 */

#ifndef REMOTECONTROL_COMMANDINTERPRETER_HH
#define REMOTECONTROL_COMMANDINTERPRETER_HH


class CommandInterpreter
{
private:
    std::string command;
    std::vector<std::string> arguments;
    std::string currentDirectory;
    std::string lastDirectory;
    std::string userHome;

public:
    explicit CommandInterpreter(std::string const &userHome = "");

    explicit CommandInterpreter(std::string const &command, std::vector<std::string> const &arguments,
                       std::string const &userHome);

    CommandInterpreter(CommandInterpreter const &other);

    ~CommandInterpreter();

    CommandInterpreter &operator=(CommandInterpreter const &other);

    void execute();

    void changeDirectory();

    void performCommand();

    void getActiveDirectory();

    std::string const &getCommand() const;

    void setCommand(std::string const &command);

    std::vector<std::string> const &getArguments() const;

    void setArguments(std::vector<std::string> const &arguments);

    std::string const &getCurrentDirectory() const;

    void setCurrentDirectory(std::string const &currentDirectory);

    std::string const &getLastDirectory() const;

    void setLastDirectory(std::string const &lastDirectory);

    std::string const &getUserHome() const;

    void setUserHome(std::string const &userHome);
};

#endif //REMOTECONTROL_COMMANDINTERPRETER_HH
