#ssh-bash

##Description:
whlie conncecting a server with ssh, bash shell would load
.bash_profile instead of .bashrc

##Solution:
write such code in .bash_profile
<!--lang:bash -->
    if [ -f ~/.bashrc ]; then
        . ~/.bashrc
    fi

