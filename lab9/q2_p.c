#include <stdio.h>
int page_size=32;
int page_num=8;

void memory_mapping(int physical_addr){
    //page_num and offset
    printf("page_number:%d \npage_offset:%d \n",physical_addr/page_size,physical_addr%page_size);
}
int main(){
    memory_mapping(204);
    memory_mapping(56);
    return 0;
}