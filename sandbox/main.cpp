#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "math/Vector2.h"

#include <iostream>

int main()
{


    // Rendering variables
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    /* triangle stuff */

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);


    unsigned int VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Linking shaders to vertexes, pasting them with glue

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);


    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window))
    {

        // Input stuff here:
        processInput(window);


        // Rendering stuff here:
        glClearColor(0.39f, 0.58f, 0.92f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // THE TRIANGLE!!!

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        // Update stuff here:
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();


    return 0;
}


