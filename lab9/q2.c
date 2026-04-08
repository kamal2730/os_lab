#include <stdio.h>
int main(){
    int page_size=32;
    int page_count=8;

    int x=204;
    printf("Page no:%d Page offset:%d \n",x/page_size,x%page_size); 
    x=56;
    printf("Page no:%d Page offset:%d \n",x/page_size,x%page_size);  
    return 0;
}