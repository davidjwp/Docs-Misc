in order of tasks:

### choose OS

**ROCKY VS DEBIAN**

Debian is a more general purpose distribution, it comes out the box with more features and applications, it is focused primarely on stability and ease of use making it the basis for a lot of other distros like Ubuntu, Mint, Arch, Debian is maintained by a team of volunteers over the internet.

It is more stable and portable, but slower to update.

Rocky linux is a distribution system based on the Red hat distro one of the most used linux distributions, thus it is an excelent distro but Rocky is more targeted towards server use and comes in with very little functionnality for this reason, Rocky is worked on by The Rocky Enterprise Software Foundation. 

It is better for servers and faster to update but less portable and stable.

### install OS

**installing OS on VMbox**

before even installing the OS you need to create a virtual machine, it is fairly straightforward.

to begin with open VMbox, VMbox for Virtual Box Manager is a free software capable of virtualization for a great many different operating system, it is used by enterprises as well as home users.

VMbox runs on x86 hardware, needs only 512MB of RAM for the MBR plus the alloted memory for the OS(though more is always better).

for a brief explanation of virtualization, virtualization is the act of creating a virtual version of something at the same abstraction level, it can be done for computer hardware, storage devices and computer networks.

create a new virtual machine 

![new_vm](../Misc/assets/Born2beroot/new_vm.png)

for the present you should name the OS Born2beroot to stay consistent and if installed on school
grounds you should install in sgoinfre

![name_os](../Misc/assets/Born2beroot/name_os.png)

the memory size (RAM) can be left as default 

![ram](../Misc/assets/Born2beroot/ram.png)

create a virtual hard disk

![hard_disk](../Misc/assets/Born2beroot/hard_disk.png)

the hard disk file type is not important, but it is good to know what each type does differently

-   **VDI** Virtual Disk Image it is the default VMbox hard disk file type and is widely used with other virutalization software thus very portable, it is the image of a virtual disk as opposed to a virtual disk, the image can be extended to add or remove space even while using it.

they are smaller and more efficient than VHD but slower than VMDK.

-   **VHD** Virtual Hard Disk acts just like a physical hard disk, they have flexible sizes and are good for pre-built systems.

the VHD has been superseded by VHDX the newer version which can hold more data.

-   **VMDk** Virtual Machine Disk allows for cloning of physical hard disk and backups of virtual machines off-site

VMDK allows incremental backups of changes to data from the time of the last backups.

for this machine you should use the default 

![hd_type](../Misc/assets/Born2beroot/hd_type.png)

Dinamically allocated

![dynamic_alloc](../Misc/assets/Born2beroot/dynamic_alloc.png)

leave default

![file_location](../Misc/assets/Born2beroot/file_location.png)

now the VM is created, to install the OS you need to insert the installation disk of the OS into the disk drive, in a virtual sense it means you have to give the virtual IDE(Integrated Drive Electronic) the image of the OS.

for debian that image can be found here: 

![debian_iso](../Misc/assets/Born2beroot/debian-logo-horizontal.png)(https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/)



### install utilities

**install SSH/sudo/UFW**

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

install ssh

    apt install openssh-server

install UFW

    apt install ufw


### configure utilities 

**configure SSH service/sudo/UFW**

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

ssh is currently installed, to make sure it is running let's restart
    service {service} [OPTION] ##this isn't exactly the prototype for this command
    service ssh restart

the service command is used to control SysVinit(System V initalisation) services through SysVinit scripts, System V is just the name for one of the first commercial version of UNIX

now change the default port(22) to 4242

    sudo nano /etc/ssh/sshd_config

nano is the default debian text editor

look for the line

    #Port 22

and simply change it to

    #Port 4242

you can check for that the line is properly changed with grep

    sudo grep /etc/ssh/ssh_config

then restart ssh again

3. UFW

UFW or Uncomplicated Firewall is a program for managing a netfilter firewall

before you can connect to the ssh server you have to configurr ufw
first off enable ufw

    sudo ufw enable