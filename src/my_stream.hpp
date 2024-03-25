#pragma once

#include "Stream.h"


typedef const char* const ccharc_t;

class MyStream: public Stream
{
public:
    MyStream(ccharc_t bytes, size_t size);
    ~MyStream();
    int available() override;
    int read() override;
    int peek() override;
    size_t readBytes(char *buffer, size_t length) override;
    String readString() override;
public: // Print.h
    size_t write(uint8_t) override;

private:
    const ccharc_t* const bbytes;
    size_t size;
    int cur;
};