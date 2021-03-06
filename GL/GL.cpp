#include <GLFW/glfw3.h>//전처리부터 읽어짐 그리고 메인 부터 봄
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#pragma comment(lib, "opengl32")//lib이 안에 오픈지엘을 가져온다

//컴파일러에게 명령어 전달 전처리기에 키워드를 내려줌 comment 외부에있는 파일을 알려주

static void error_callback(int error, const char* description)

{

    fputs(description, stderr);//오류나면 말해줌

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)

{

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}

int main(void)

{

    GLFWwindow* window;// 포인터 선언

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())

        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//원도우를 만들갰다 윈도우를 내놔라
    if (!window)//윈도우에 대한 주소값을 알려줌 실패했다면 glfw윈도우를 삭제

    {
        glfwTerminate();
        exit(EXIT_FAILURE);

    }
    glfwMakeContextCurrent(window);//glcontext잡어서 windowd에 넣음
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))

    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//glfw앞에 붙은게 윈도우 창 상태를 바꿔주는거
        ratio = width / (float)height;
        glClearColor(0.7f, 0.7f, 0.7f, 1);//rgb임 
        //double말고 float쓰는 이유 더블보다 빠르게 사용이 가능해서
        glClear(GL_COLOR_BUFFER_BIT);

        if (GetAsyncKeyState(VK_SPACE) & 0x8000)

        {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.5f, 0.1f);
            glVertex2f(-0.7f, 0.1f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.7f, 0.3f);
            glVertex2f(-0.7f, 0.1f);
            glEnd();

        }
        else {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.5f, -0.2f);
            glVertex2f(-0.7f, -0.2f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.7f, 0.0f);
            glVertex2f(-0.7f, -0.2f);
            glEnd();

        }
        glfwSwapBuffers(window);//버퍼 스압
        glfwPollEvents();//이벤트 q 메세지가 들어가있는지 없는지 확인 메세지가 있으면 키콜백 아니면 에러콜백이 실행됨

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}