#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
        std::ifstream MyTestFile(filename);
        int count = 0;
        char c;
        while (MyTestFile.get(c)) {
            if (c >= 32 && c <= 126) count++;
        }
        MyTestFile.close();
        return count;
    }

};

// enum Commands {
//     l = "-l", w, c, m
// };

int main(int argc, char* argv[]) {
    if (argc >= 1) {
        WC myWCProgram("test.txt");  
        std::cout << myWCProgram.getCharCount() << std::endl;

    } else {
        std::cout << "please enter arguments"<< std::endl;
    }
    return 0;
}