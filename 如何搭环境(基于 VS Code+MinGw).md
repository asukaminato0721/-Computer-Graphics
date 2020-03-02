在文件夹里有 glut.def, glut.h, glut32.lib, glut32.lib.

作如下安排

1. glut.def 不用管。

2. glut.h 放入 `\MinGW\include\GL\glut.h`

3. 网上找一个 32 位的 opengl32.dll 下载下来，放在 cpp 文件同目录，(cmd 里运行 `gcc -v` 确认是否是 32 位）

4. glut32.dll 也放同目录

5. 在 `test.cpp` 文件目录打开 cmd, 运行 `g++ -o test -Wall test.cpp -mwindows glut32.lib -lopengl32 -lglu32`

6. 注意 `#include <windows.h>` 一定要写第一行

> <https://w3.cs.jmu.edu/bernstdh/Web/common/help/cpp_mingw-glut-setup.php>