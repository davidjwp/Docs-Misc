in order of tasks:

#### choose OS

**ROCKY VS DEBIAN**

Debian is a more general purpose distribution, it comes out the box with more features and applications, it is focused primarely on stability and ease of use making it the basis for a lot of other distros like Ubuntu, Mint, Arch, Debian is maintained by a team of volunteers over the internet.

It is more stable and portable, but slower to update.

Rocky linux is a distribution system based on the Red hat distro one of the most used linux distributions, thus it is an excelent distro but Rocky is more targeted towards server use and comes in with very little functionnality for this reason, Rocky is worked on by The Rocky Enterprise Software Foundation. 

It is better for servers and faster to update but less portable and stable.




#### install OS

**installing OS on VMbox**



#### install SSH

**install SSH and configure server**


#### 

fdisk

lsblk

blkid



### 2. Device Mapper
The device mapper is a framework provided by the Linux kernel for mapping physical block devices onto higher-level virtual block devices. It forms the foundation of the logical volume manager (LVM), software RAIDs and dm-crypt disk encryption, and offers additional features such as file system snapshots.

Device mapper works by passing data from a virtual block device, which is provided by the device mapper itself, to another block device. Data can be also modified in transition, which is performed, for example, in the case of device mapper providing disk encryption or simulation of unreliable hardware behavior.

The following mapping targets are available:

cache – allows creation of hybrid volumes, by using solid-state drives (SSDs) as caches for hard disk drives (HDDs)

clone – will permit usage before a transfer is complete.

crypt – provides data encryption, by using the Linux kernel’s Crypto API

delay – delays reads and/or writes to different devices (used for testing)

era – behaves in a way similar to the linear target, while it keeps track of blocks that were written to within a user-defined period of time

error – simulates I/O errors for all mapped blocks (used for testing)

flakey – simulates periodic unreliable behaviour (used for testing)

linear – maps a continuous range of blocks onto another block device

mirror – maps a mirrored logical device, while providing data redundancy

multipath – supports the mapping of multipathed devices, through usage of their path groups

raid – offers an interface to the Linux kernel’s software RAID driver (md)

snapshot and snapshot-origin – used for creation of LVM snapshots, as part of the underlying copy-on-write scheme

striped – stripes the data across physical devices, with the number of stripes and the striping chunk size as parameters

thin – allows creation of devices larger than the underlying physical device, physical space is allocated only when written to

zero – an equivalent of /dev/zero, all reads return blocks of zeros, and writes are discarded






A.1. IDE
hdparm -i gives you more information about the hardware, like disk manufacturer, serial number and disk geometry.

A.1.1 SATA
Serial ATA is ATA over serial lines. SATA uses smaller cables, then parallel ATA, which leaves more room and thus better cooling in the computer housing. SATA also does not use the master/slave setup anymore and is hotplugable.

A.2. SCSI
A.2.1. SAS
Serial-attached SCSI has thinner cables, less bulky connectors and allows for longer cables. The hardware is cheaper and less prone to crosstalk.

