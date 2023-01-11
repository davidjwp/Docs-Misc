### 1. LVM




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