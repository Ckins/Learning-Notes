# SSH-KEYS
## Description:
It is a great convenience to be authoricated to server without entering pwd.
## Reference:
[https://wiki.archlinux.org/](https://wiki.archlinux.org/index.php/SSH_keys_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))
## Solution
* produce keygen:
<!--lang:bash-->
    ssh-keygen
* copy kengen to the server
<!--lang:bash-->
    mkdir ~/.ssh
    cd ~/.ssh
    ssh-copy-id <user>@<ip or hostname>
* login the remote-host
<!--lang:bash-->
    chmod 700 ~/.ssh
    chmod 700 /home/${your usrname}
    chmod 600 ~/.ssh/authorized_keys

