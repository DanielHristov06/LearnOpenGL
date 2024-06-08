#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    glfwInit(); // Initialize the library

    window = glfwCreateWindow(1600, 900, "Hello World", NULL, NULL); // Create a windowed mode window and its OpenGL context
    if (!window) {
        std::cout << "Window failed to create!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);// Make the window's context current

    // Initialize the GLEW library
    if (glewInit() != GLEW_OK) {
        std::cout << "Error!" << std::endl;
        return -1;
    }

    // Create and bind a vertex buffer with the specified positions
    float positions[6] = {
         0.0f,  0.5f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0); // Add an attribute for the positions of each vertex

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT); // Render here

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window); // Swap front and back buffers

        glfwPollEvents(); // Poll for and process events
    }

    glfwTerminate();
    return 0;
}