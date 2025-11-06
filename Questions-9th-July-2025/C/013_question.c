#include <stdio.h>
#include<math.h>
#include<string.h>

int main() {
    // TODO: Implement solution here

    char input[100];
    int count = 0;
    double output = 0;
    scanf("%s", input);
    for(int i = strlen(input) - 1; i >= 0; i--){
        if(input[i]>='0' && input[i]<='9')
            output += pow(17,count++)*(input[i] - '0');
        else if(input[i]>='A' && input[i]<='G')
            output += pow(17,count++)*(input[i] - 'A' + 10);
    }
    printf("%d", (int)output);

    return 0;
}
