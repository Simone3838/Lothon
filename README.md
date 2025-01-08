# Lothon
demo os in c

# features:
- [x] Basic bootloader

- [x] Shell

# TODO
- [ ] more command such as ls,mkdir,etc.

- [ ] gui

- [ ] boot sequence

# how to compile it?
```
nasm -f bin boot.asm -o boot.bin
i686-elf-gcc -ffreestanding -c kernel.c -o kernel.o
i686-elf-ld -o kernel.bin -T linker.ld kernel.o
cat boot.bin kernel.bin > os-image.bin
```
then you can run the image by running this command:
```
qemu-system-x86_64 -drive format=raw,file=os-image.bin
```
or you can run in vmbox :-)
Step 1: Install VirtualBox

If you haven't installed VirtualBox yet, download and install it from the VirtualBox website.


Step 2: Create a New Virtual Machine

Open VirtualBox and click on "New" to create a new virtual machine.

Name your virtual machine (e.g., "LothonOS"), and set the type to "Other" and version to "Other/Unknown (64-bit)".

Allocate memory (RAM) to the virtual machine. 64 MB should be sufficient for this basic OS.

Choose "Do not add a virtual hard disk" and click "Create".

Step 4: Configure the Virtual Machine

Select your newly created virtual machine and click "Settings".

Go to the "System" tab, then the "Motherboard" tab, and make sure "Floppy" is unchecked and "Optical" is checked.

Go to the "Processor" tab and allocate at least one CPU core.

Go to the "Display" tab and allocate sufficient video memory (e.g., 16 MB).

Go to the "Storage" tab, click on the "Empty" slot under "Controller: IDE", and then click on the disk icon on the right. Choose "Choose a disk file..." and select your os-image.bin file.

Ensure that the "Live CD/DVD" checkbox is checked.


Step 3: Start the Virtual Machine

Click "Start" to boot your virtual machine.

VirtualBox will use the os-image.bin file as a bootable image and start your custom OS.

# Enjoy controllerastrobot :)
![Controllerastrobot](https://github.com/user-attachments/assets/1c384e79-10b7-4917-8ff3-d56ee76fe425)
