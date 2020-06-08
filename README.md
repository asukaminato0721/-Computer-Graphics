# 计算机图形学代码备份

> 本项目是基于 MinGW 的，所有代码均已测试成功。

在老师提供的压缩包 `glut-3.7.6-bin.rar` 里有 glut.def, glut.h, glut32.lib, glut32.lib.

作如下安排

假设要编译的 `test.cpp` 在 `fold` 文件夹里

1. glut.def 不用管。

2. glut.h 放在 `\MinGW\include\GL\glut.h`

3. 网上找一个 32 位的 opengl32.dll 下载下来，放在 `fold`，(cmd 里运行 `gcc -v` 确认 `gcc` 是否是 32 位）

4. glut32.dll 也放 `fold`

5. 在 `fold` 目录打开 cmd, 运行 `g++ -o test -Wall test.cpp -mwindows glut32.lib -lopengl32 -lglu32` 即编译成功，会得到 `test.cpp`

6. 注意 `#include <windows.h>` 一定要写第一行

    ```cpp
    #include <windows.h>
    #include <GL/glut.h>
    ......
    ```

[参考链接](https://w3.cs.jmu.edu/bernstdh/Web/common/help/cpp_mingw-glut-setup.php)

---

弃 CPP，转投 Python 怀抱。

[相关资料](https://hansimov.github.io/#PyOpenGL%20的几个问题)
