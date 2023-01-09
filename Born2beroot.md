https://blog.codefarm.me/2021/11/29/device-mapper-and-linux-lvm/

https://www.system-rescue.org/lvm-guide-en/How-the-logical-volume-manager-works/#:~:text=A%20logical%20block%20device%20such,of%20flexibility%20with%20block%20devices

https://gauravmmh1.medium.com/writing-your-own-device-mapper-target-539689d19a89#:~:text=Such%20device%20mapper%20target%20can,to%20underlying%20existing%20block%20devices.

https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/logical_volume_manager_administration/device_mapper#dm-mappings
(very useful, see that back)

https://knowitlikepro.com/understanding-master-boot-record-mbr/


https://knowitlikepro.com/understanding-extended-boot-record-ebr/

https://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/usr.html


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

