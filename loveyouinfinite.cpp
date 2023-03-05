#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Set initial color to white
    std::cout << "\033[0m";

    bool first_message = true; // Flag to track which message to print next

    while (true) {
        if (first_message) {
            // Fade out first message
            for (int i = 100; i >= 0; i -= 5) {
                std::cout << "\033[2K"; // Clear current line
                std::cout << "\033[38;2;255;255;255m"; // Set text color to white
                std::cout << "\033[1m"; // Set text style to bold
                std::cout << "Anish Love You\n"; // Print first message
                std::cout << "\033[0m"; // Reset color and style
                std::cout << "\033[38;2;0;0;0m"; // Set text color to black
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            first_message = false;
        } else {
            // Fade in second message
            for (int i = 0; i <= 100; i += 5) {
                std::cout << "\033[2K"; // Clear current line
                std::cout << "\033[38;2;255;255;255m"; // Set text color to white
                std::cout << "\033[1m"; // Set text style to bold
                std::cout << "Anish Love You\n"; // Print second message
                std::cout << "\033[0m"; // Reset color and style
                std::cout << "\033[38;2;0;0;0m"; // Set text color to black
                std::cout.flush();
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }

            first_message = true;
        }
    }

    return 0;
}
