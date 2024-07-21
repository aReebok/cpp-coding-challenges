#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <locale>

class WC {
private:
    std::string filename;

public:
    WC(const std::string file){
        filename = file;
    }

    /**
     * See here for more details on c++ files
     * https://cplusplus.com/doc/tutorial/files/
     */
    int getByteCount(){
        std::ifstream MyTestFile(filename, std::ios::binary);
        std::streampos begin, end;
        begin = MyTestFile.tellg();             // gets current position; returns a streampos
        MyTestFile.seekg(0, std::ios::end);     // change current position to ios::end 
        end = MyTestFile.tellg();               // get current position (now at the end)
        MyTestFile.close();

        return end - begin;
    }

    int getLineCount() {
        std::ifstream MyTestFile(filename);
        std::string line;
        int count = 0;
        while (getline(MyTestFile, line)) count++;
        MyTestFile.close();

        return count;
    }

    int getWordCount() {
        std::ifstream MyTestFile(filename);
        int wordCount = 0;
        std::string line, word;
        while(getline(MyTestFile, line)) {
            std::stringstream stream(line);
            while(stream >> word) wordCount++;   
        }
        MyTestFile.close();

        return wordCount;
    }

    int getCharCount() {
        std::wifstream file(filename);
        
        // Set the locale to handle UTF-8
        file.imbue(std::locale(""));

        int characters = 0;
        wchar_t ch;
        while (file.get(ch)) {
            characters++;
        }
        return characters;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ccwc -[c|l|w|m] file_path" << std::endl;
        std::cerr << "Options:" << std::endl;
        std::cerr << "  -c\tcount bytes" << std::endl;
        std::cerr << "  -l\tcount lines" << std::endl;
        std::cerr << "  -w\tcount words" << std::endl;
        std::cerr << "  -m\tcount characters" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    std::string option = "-a";
    if (argc >= 3) {
        option = argv[1];
        filePath = argv[2];
    }

    WC f(filePath);

    int count = 0;
    if (option == "-c") {
        count = f.getByteCount();
    } else if (option == "-l") {
        count = f.getLineCount();
    } else if (option == "-w") {
        count = f.getWordCount();
    } else if (option == "-m") {
        count = f.getCharCount();
    } else {
        std::cout<< "\t" << f.getLineCount() << "\t" << f.getWordCount() << "\t"
        << f.getByteCount() << "\t" << filePath << std::endl;
        return 0;
    }
    std::cout << "\t" << count << "\t" << filePath << std::endl;
}