#pragma once
#include "overhead.h"

// shader setup class, meant to be used in "head.h"
class shader : public overhead {
public: shader();

public: bool shaderInit();
//public: void trythisinit();
public: bool loadShader(const std::string &filename, GLenum shaderType);
public: void useProgram();
public: void close();

private: bool tryCompile(int shaderID);
private: int createShader(const std::string &filename, GLenum shaderType);
private: bool linkShaders();
private: std::string readFile(const char* file);
private: void printLinkError(int32_t shaderID);
private: void printCompileError(int32_t shaderID);

// shaderProgram, vertexShader, & fragmentShader are already declared in the
// 'overhead' class and are protected. 'shader' class can use them

protected: std::vector<int32_t> shaderIDs;
};