#include "my_stream.hpp"

MyStream::MyStream(ccharc_t bytes, size_t size) : bbytes(&bytes), size(size), cur(0) {}
MyStream::~MyStream() {}

int MyStream::available() {
    return size-cur;
}

int MyStream::read() {
    return -1;
}

int MyStream::peek() {
    if(cur + 1 < size) {
        return (int)*(bbytes + cur + 1);
    }
    return -1;
}

size_t MyStream::readBytes(char *buffer, size_t length) {
    if(length <= available()) {
        buffer = (char*)*(bbytes + cur);
        cur += length;
        return length;
    }
    return -1;
}

String MyStream::readString() {
    if(*bbytes == nullptr) {
        return String();
    }
    return String(*bbytes);
}

size_t MyStream::write(uint8_t) {
    return -1;
}
