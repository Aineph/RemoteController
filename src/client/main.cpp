#include <iostream>
#include <Client.hh>
#include <RemoteControlException.hpp>

/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 23/10/2018.
 */

int main(int argc, char **argv, char **env)
{
    std::string userName;

    if (argc != 2 || env == nullptr)
        return -1;
    try
    {
        for (int i = 0; env[i] != nullptr; i++) {
            if (!strncmp(env[i], "USER=", 5))
                userName = &env[i][5];
        }
        Client *client = new Client(argv[1], userName);
        client->run();
    } catch (RemoteControlException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
