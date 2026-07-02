#include <stdio.h>

int main() {
    char name[64];
    
    printf("🐾 小啪的 Flatpak 第一个包！\n");
    printf("请输入你的名字：");
    fflush(stdout);
    
    fgets(name, sizeof(name), stdin);
    
    printf("你好，%s欢迎来到 Flatpak 世界！\n", name);
    printf("按 Enter 键退出...");
    getchar();
    
    return 0;
}