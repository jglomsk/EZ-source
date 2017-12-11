sudo chmod +x ez.out # change perms
sudo chmod +x ez.mac
sudo mkdir /usr/local/bin
sudo mkdir /usr/local/share
sudo mkdir /usr/local/share/ez
if [ "$(uname)" == "Linux" ]; then
	sudo cp ez.out /usr/local/bin/ez
	sudo rm -rf ez.mac
else
	sudo cp ez.mac /usr/local/bin/ez
	sudo rm -rf ez.out
fi
sudo cp help.ez /usr/local/share/ez/ # create copy of libs
sudo cp creator.ez /usr/local/share/ez/
sudo cp sauce.ez /usr/local/share/ez/
sudo cp all.ez /usr/local/share/ez/
sudo rm -rf help.ez # then delete that file
sudo rm -rf creator.ez
sudo rm -rf sauce.ez
sudo rm -rf all.ez
sudo rm -rf ezwin_install.exe
sudo rm -rf ez.exe
read -n1 -p "Would you like to delete the original interpreter? [y,n]: " y_or_n;
if [ "$y_or_n" = "y" ]; then
	if [ "$(uname)" == "Linux" ]; then
		sudo rm -rf ez.out
	else
		sudo rm -rf ez.mac
	fi
	echo
else
	echo "Deletion declined."
fi
echo "Command: ez"
echo "Usage: ez <ez-file>"
echo "Description: "
echo
echo "Uses the ez interpreter to run a .ez file."
echo
echo "Install completed successfully."