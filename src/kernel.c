#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// VGA text mode buffer constants
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_ADDRESS 0xB8000

// Keyboard I/O ports
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Function prototypes
void kernel_main(void);
void clear_screen(void);
void print(const char* str);
void print_newline(void);
void print_prompt(void);
void handle_command(const char* command);
void help_command(void);
void cls_command(void);

// Global variables
uint16_t* video_memory = (uint16_t*) VGA_ADDRESS;
uint8_t terminal_row = 0;
uint8_t terminal_column = 0;
uint8_t terminal_color = 0x07;  // Light grey on black

// Kernel entry point
void kernel_main() {
    clear_screen();
    print("Welcome to Lothon OS!");
    print_newline();
    print_prompt();

    char command[256];
    int command_index = 0;

    while (true) {
        char c = getchar();  // Read character input

        if (c == '\n') {
            command[command_index] = '\0';
            handle_command(command);
            command_index = 0;
            print_prompt();
        } else {
            command[command_index++] = c;
            char str[2] = {c, '\0'};
            print(str);
        }
    }
}

// Clear the screen
void clear_screen() {
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            video_memory[index] = (uint16_t) ' ' | (uint16_t) terminal_color << 8;
        }
    }
    terminal_row = 0;
    terminal_column = 0;
}

// Print a string to the screen
void print(const char* str) {
    size_t i = 0;
    while (str[i] != '\0') {
        const size_t index = terminal_row * VGA_WIDTH + terminal_column;
        video_memory[index] = (uint16_t) str[i] | (uint16_t) terminal_color << 8;
        terminal_column++;
        if (terminal_column >= VGA_WIDTH) {
            terminal_column = 0;
            terminal_row++;
        }
        i++;
    }
}

// Print a newline
void print_newline() {
    terminal_column = 0;
    terminal_row++;
}

// Print the shell prompt
void print_prompt() {
    print("> ");
}

// Handle a command
void handle_command(const char* command) {
    if (strcmp(command, "help") == 0) {
        help_command();
    } else if (strcmp(command, "cls") == 0) {
        cls_command();
    } else {
        print("Unknown command: ");
        print(command);
        print_newline();
    }
}

// Print the help message
void help_command() {
    print("Available commands:");
    print_newline();
    print("help - Show this help message");
    print_newline();
    print("cls - Clear the screen");
    print_newline();
}

// Clear the screen command
void cls_command() {
    clear_screen();
}

// Read a byte from the keyboard data port
char getchar() {
    char c = 0;

    // Wait for a key press
    while (c == 0) {
        if (inb(KEYBOARD_STATUS_PORT) & 0x01) {
            c = inb(KEYBOARD_DATA_PORT);
        }
    }

    return c;
}

// Read a byte from an I/O port
uint8_t inb(uint16_t port) {
    uint8_t result;
    __asm__("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

// Placeholder for a simple string comparison function
int strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}
