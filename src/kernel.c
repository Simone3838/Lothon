void kernel_main() {
    const char *str = "Welcome to Lothon OS!";
    char *video_memory = (char*) 0xb8000;
    int i = 0;

    while (str[i] != '\0') {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = 0x07; // Set the color attribute to white on black
        i++;
    }

    while (1) {
        // Halt the CPU
        __asm__("hlt");
    }
}
