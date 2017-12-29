sudo chmod +x ez.out # change perms
sudo chmod +x ez.mac
sudo mkdir /usr/local/bin &>/dev/null
sudo mkdir /usr/local/share &>/dev/null
sudo mkdir /usr/local/share/ez &>/dev/null
if [ "$(uname)" == "Linux" ]; then
	sudo cp ez.out /usr/local/bin/ez
	sudo rm -rf ez.mac
else
	sudo cp ez.mac /usr/local/bin/ez
	sudo rm -rf ez.out
fi
sudo cp help.ez /usr/local/share/ez/ && sudo rm -rf help.ez # copy libs then delete that file
sudo cp creator.ez /usr/local/share/ez/ && sudo rm -rf creator.ez
sudo cp sauce.ez /usr/local/share/ez/ && sudo rm -rf sauce.ez
sudo cp all.ez /usr/local/share/ez/ && sudo rm -rf all.ez
sudo rm -rf ezwin_install.exe
sudo rm -rf ez.exe
read -n1 -p "Would you like to delete the original interpreter? [y,n]: " y_or_n;
echo
if [ "$y_or_n" = "y" ]; then
	if [ "$(uname)" == "Linux" ]; then
		sudo rm -rf ez.out
	else
		sudo rm -rf ez.mac
	fi
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