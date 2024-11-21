#include <stdio.h>
#include <stdbool.h> 

int main() {
    bool var1 = true;  
    bool var2 = false; 

    
    bool andResult = var1 && var2;
    bool orResult = var1 || var2;
    bool notVar1 = !var1;
    bool notVar2 = !var2;

    
    printf("Logical AND (var1 && var2): %d\n", andResult);
    printf("Logical OR (var1 || var2): %d\n", orResult);
    printf("Logical NOT (!var1): %d\n", notVar1);
    printf("Logical NOT (!var2): %d\n", notVar2);

    return 0;
}
