# Lothon
demo os in c

# features:
Basic bootloader
Shell

# TODO
[] more command such as ls,mkdir,etc.
[] gui
[] boot sequence

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

# Enjoy controllerastrobot :)
![Controllerastrobot](https://github.com/user-attachments/assets/1c384e79-10b7-4917-8ff3-d56ee76fe425)
