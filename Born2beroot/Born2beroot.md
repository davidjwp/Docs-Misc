in order of tasks:

#### choose OS

**ROCKY VS DEBIAN**

Debian is a more general purpose distribution, it comes out the box with more features and applications, it is focused primarely on stability and ease of use making it the basis for a lot of other distros like Ubuntu, Mint, Arch, Debian is maintained by a team of volunteers over the internet.

It is more stable and portable, but slower to update.

Rocky linux is a distribution system based on the Red hat distro one of the most used linux distributions, thus it is an excelent distro but Rocky is more targeted towards server use and comes in with very little functionnality for this reason, Rocky is worked on by The Rocky Enterprise Software Foundation. 

It is better for servers and faster to update but less portable and stable.

#### install OS

**installing OS on VMbox**



#### install utilities

**install SSH/sudo/vim/UFW**

the first step is gonna be to change current user to root

    su [options] [-] [user [argument...]]
    su -

the su command goes for substitute user and allows you to run commands with a substitute user, if no user is defined then it will default to root.

here the flag [-] means login

now you can install sudo which allows you to execute a command as the superuser or another user.

    apt-get update
    apt-get upgrade
    apt install sudo

really there is no difference between doing apt-get and apt,
the apt command is a shell front end for APT (Advanced Packaging Tool),
APT contains apt-get/cache and other utilities.

so the command apt brings all thoses under a nice little package 📦️

    apt install vim

install vim

    apt install openssh-server

install ssh

    apt install ufw

install UFW

#### configure utilities 

**configure SSH service/sudo**

1. SUDO

now that everything you need is installed let's configure some of the utilities, first set user to sudo group.

    usermod [options] LOGIN
    su -
    usermod -aG sudo djacobs

usermod goes for user modification, it allows you to modify the system account files to reflect the changes that are specified on the command line (i.e manage a user account)

the -a option adds the user to the supplementary group(s) it can only be used with the -G option which goes for the list of supplementary groups which the user is a also a member of.

you can then check the sudo group like this

    getent group sudo

now you need to edit the sudoers file to give user permission rights 

    sudo visudo

use sudo to get permission to use visudo command that let's you edit the sudoers file, sudoers is a policy plugin that determines a user's sudo priviledges, it is the default sud policy plugin.

once in the file write

    djacobs ALL=(ALL) ALL

a typical line is divided like so

    root    ALL=(ALL:ALL) ALL

-   **root** username the rule applies to
-   **ALL(1)** indicates the rule applies to ALL hosts
-   **ALL(2)** indicates that this user can execute commands as ALL users
-   **ALL(3)** indicates that this user can execute commands as ALL groups
-   **ALL(4)** indicates the rule applies to ALL commands

2. SSH

you can check the SSH status with this 
    systemctl [OPTIONS...] COMMAND [UNIT...]
    sudo systemctl status ssh

systemctl goes for system contrl, to control the systemd system and service manager, it's used to introspect and control the state of the "systemd" system and service manager
