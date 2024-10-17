#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>

void typewrite(const std::string &text, int interval) {
    for (char ch : text) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;

        input.ki.wVk = VkKeyScan(ch);
        input.ki.dwFlags = 0;
        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));

        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
}

void clean_html_and_write_to_file() {
    std::ifstream infile("html_content.txt");
    if (!infile.is_open()) {
        std::cerr << "Koe durung gawe html_content.txt blog..." << std::endl;
        return;
    }

    std::string html_content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    std::string cleaned_text;
    size_t pos = 0, start, end;
    while ((start = html_content.find('<', pos)) != std::string::npos) {
        cleaned_text += html_content.substr(pos, start - pos);
        end = html_content.find('>', start);
        pos = end + 1;
    }
    cleaned_text += html_content.substr(pos);

    std::ofstream outfile("output.txt");
    outfile << cleaned_text;
    outfile.close();
}

int main() {
    clean_html_and_write_to_file();
    
    std::cout << "Starting in 5 seconds..." << std::endl;
    for (int i = 5; i > 0; --i) {
        std::cout << i << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::ifstream file("output.txt");
    if (!file.is_open()) {
        std::cerr << "raono output.txt blog!" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    // Simulate typing the text
    typewrite(text, 50);

    std::cout << "Wes..." << std::endl;
    return 0;
}

