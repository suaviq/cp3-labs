// napisać klasę która stworzy obrazek
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <windows.h>
using namespace std;


struct BmpHeader {
    char bitmapSignatureBytes[2] = { 'B', 'M' };
    uint32_t sizeOfBitmapFile = 54 + 786432;
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;
} bmpHeader;

struct BmpInfoHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 50; 
    int32_t height = 50; 
    uint16_t numberOfColorPlanes = 1; 
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0; 
    int32_t horizontalResolution = 3780; 
    int32_t verticalResolution = 3780; 
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;
} bmpInfoHeader;

struct Pixel {
    uint8_t blue = 255;
    uint8_t green = 255;
    uint8_t red = 0;
} pixel;


struct Pixel {
    uint8_t blue = 50;
    uint8_t green = 10;
    uint8_t red = 200;
};

class MyBMP
{
private:
    string name;
    BmpHeader header;
    BmpInfoHeader info;
    Pixel pixel;

public:
    MyBMP(string image = "image")
    {
        name = image + ".bmp";
    }

    bool create(int32_t w, int32_t h)
    {
        ofstream fout(this->name, ios::binary);
        if (fout.is_open())
        {
            info.height = h;
            info.width = w;
            header.sizeOfBitmapFile = 54 + (w * h * 3);
            fout.write((char*)&header, 14);
            fout.write((char*)&info, 40);

            size_t numberOfPixels = info.width * info.height;
            for (int i = 0; i < numberOfPixels; i++) {
                fout.write((char*)&pixel, 3);
            }
            fout.close();
            return true;
        }
        cout << "\nERROR: Couldn't open the file!\n";
        return false;
    }
}


int main(){
    MyBMP b("zdjecie");
    b.create(512, 512);

    //b.read(300, 300);

    return 0;
}