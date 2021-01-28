#include "../Main.h"
#include "PolyGL.h"
#include <string>
#include <iostream>
#include <fstream>


std::string readFile(const char *filePath) //courtesy of https://stackoverflow.com/questions/32842617/read-glsl-shaders-from-file/32843008
{
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}


unsigned int loadShader(const char *filePath, GLenum type) 
{
    std::string shaderString = readFile(filePath);
    const char* shaderSource = shaderString.c_str();
    unsigned int shader = glCreateShader(type);

    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Error: shader compilation failed.\n" << infoLog << std::endl;
    }

    return(shader);

}

unsigned int createProgram(unsigned int vertex, unsigned int fragment)
{
    unsigned int program;
    program = glCreateProgram();

    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "Error: shader program linking failed.\n" << infoLog << std::endl;
    }

    return program;
}