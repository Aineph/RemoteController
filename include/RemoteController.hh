/*
 * Created by Nicolas Fez for RemoteControl.
 * Started on 24/10/2018.
 */

#ifndef REMOTECONTROL_REMOTECONTROLLER_HH
#define REMOTECONTROL_REMOTECONTROLLER_HH


class RemoteController
{
private:
    int remoteTarget;

public:
    RemoteController();

    RemoteController(RemoteController const &other);

    virtual ~RemoteController();

    RemoteController &operator=(RemoteController const &other);

    const int getRemoteTarget() const;

    void setRemoteTarget(const int remoteTarget);
};

#endif //REMOTECONTROL_REMOTECONTROLLER_HH
