#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);  

GLFWwindow* createWindow(){
    GLFWwindow* window = glfwCreateWindow(800,600, "Learning Open GL", NULL, NULL);
    if(window == NULL){
        printf("Failed To Create GLF@ window");
        glfwTerminate();
        
    }

    glfwMakeContextCurrent(window);
    return window;
}

int initGLAD(){
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Failed To Initialize GLAD");
        return -1;
    }
    return 0;
}

void frameBuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0,800,600);
}

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = createWindow();
    initGLAD();
    glfwSetFramebufferSizeCallback(window, frameBuffer_size_callback);

    while(!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}