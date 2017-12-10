sudo chmod +x ez.out # change perms
sudo chmod +x ez.mac
sudo mkdir /usr/local/bin
sudo mkdir /usr/local/share
sudo mkdir /usr/local/share/ez
sudo cp ez.out /usr/bin/ez # create a copy of the ez interpreter in the path
sudo cp ez.mac /usr/local/bin/ez
sudo cp help.ez /usr/local/share/ez/ # create copy of libs
sudo cp creator.ez /usr/local/share/ez/
sudo cp sauce.ez /usr/local/share/ez/
sudo cp all.ez /usr/local/share/ez/
sudo rm -rf help.ez # then delete that file
sudo rm -rf creator.ez
sudo rm -rf sauce.ez
sudo rm -rf all.ez
echo "Command: ez"
echo "Usage: ez <ez-file>\n"
echo "Description: "
echo "Uses the ez interpreter to run a .ez file.\n"
echo "Install completed successfully."
