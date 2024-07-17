#include <iostream>
#include <fstream>
#include <string>

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
        begin = MyTestFile.tellg();
        MyTestFile.seekg(0, std::ios::end);
        end = MyTestFile.tellg();
        MyTestFile.close();
        return end - begin;
    }
};  

int main() {
    WC myWCProgram("test.txt");  
    std::cout << myWCProgram.getByteCount() << std::endl;
}