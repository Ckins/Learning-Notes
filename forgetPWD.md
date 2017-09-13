# how to reset password
[Ubuntu official document](https://help.ubuntu.com/community/LostPassword)
* Reboot your computer
* Hold Shift during boot to start GRUB menu
* Highlight your image and press E to edit
* Find the line starting with "linux" and append rw init=/bin/bash at the end of that line
* Press Ctrl+X to boot.
* Type in passwd username
* Set your password.
* Type in reboot.
